package main

import (
	"bufio"
	"context"
	"fmt"
	"io"
	"log"
	pb "ordermgt/client/ecommerce"
	"os"
	"strings"
	"time"

	wrapper "github.com/golang/protobuf/ptypes/wrappers"
	"google.golang.org/grpc"
)

const (
	address = "localhost:50051"
)

func main() {
	// Setting up a connection to the server.
	conn, err := grpc.Dial(address, grpc.WithInsecure())
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()
	client := pb.NewOrderManagementClient(conn)

	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Print("> ")
		text, _ := reader.ReadString('\n')
		text = strings.TrimSpace(text)
		
		switch text {
		case "add-order":
			// Add Order
			clientDeadline := time.Now().Add(time.Duration(2 * time.Second))
			ctx, cancel := context.WithDeadline(context.Background(), clientDeadline)
			defer cancel()
			order1 := pb.Order{Id: "101", Items: []string{"iPhone XS", "Mac Book Pro"}, Destination: "San Jose, CA", Price: 2300.00}
			res, _ := client.AddOrder(ctx, &order1)
			if res != nil {
				log.Print("AddOrder Response -> ", res.Value)
			}

		case "get-order":
			// Get Order
			clientDeadline := time.Now().Add(time.Duration(2 * time.Second))
			ctx, cancel := context.WithDeadline(context.Background(), clientDeadline)
			defer cancel()
			retrievedOrder, _ := client.GetOrder(ctx, &wrapper.StringValue{Value: "106"})
			log.Print("GetOrder Response -> : ", retrievedOrder)

		case "search":
			// Search Order : Server streaming scenario
			clientDeadline := time.Now().Add(time.Duration(2 * time.Second))
			ctx, cancel := context.WithDeadline(context.Background(), clientDeadline)
			defer cancel()
			searchStream, _ := client.SearchOrders(ctx, &wrapper.StringValue{Value: "Google"})
			for {
				searchOrder, err := searchStream.Recv()
				if err == io.EOF {
					log.Print("EOF")
					break
				}

				if err == nil {
					log.Print("Search Result : ", searchOrder)
				}
			}

		case "update":
			// Update Orders : Client streaming scenario
			clientDeadline := time.Now().Add(time.Duration(2 * time.Second))
			ctx, cancel := context.WithDeadline(context.Background(), clientDeadline)
			defer cancel()
			updOrder1 := pb.Order{Id: "102", Items: []string{"Google Pixel 3A", "Google Pixel Book"}, Destination: "Mountain View, CA", Price: 1100.00}
			updOrder2 := pb.Order{Id: "103", Items: []string{"Apple Watch S4", "Mac Book Pro", "iPad Pro"}, Destination: "San Jose, CA", Price: 2800.00}
			updOrder3 := pb.Order{Id: "104", Items: []string{"Google Home Mini", "Google Nest Hub", "iPad Mini"}, Destination: "Mountain View, CA", Price: 2200.00}

			updateStream, err := client.UpdateOrders(ctx)

			if err != nil {
				log.Fatalf("%v.UpdateOrders(_) = _, %v", client, err)
			}

			// Updating order 1
			if err := updateStream.Send(&updOrder1); err != nil {
				log.Fatalf("%v.Send(%v) = %v", updateStream, updOrder1, err)
			}

			// Updating order 2
			if err := updateStream.Send(&updOrder2); err != nil {
				log.Fatalf("%v.Send(%v) = %v", updateStream, updOrder2, err)
			}

			// Updating order 3
			if err := updateStream.Send(&updOrder3); err != nil {
				log.Fatalf("%v.Send(%v) = %v", updateStream, updOrder3, err)
			}

			updateRes, err := updateStream.CloseAndRecv()
			if err != nil {
				log.Fatalf("%v.CloseAndRecv() got error %v, want %v", updateStream, err, nil)
			}
			log.Printf("Update Orders Res : %s", updateRes)

		case "process":
			// Process Order : Bi-di streaming scenario
			clientDeadline := time.Now().Add(time.Duration(2 * time.Second))
			ctx, cancel := context.WithDeadline(context.Background(), clientDeadline)
			defer cancel()
			streamProcOrder, err := client.ProcessOrders(ctx)
			if err != nil {
				log.Fatalf("%v.ProcessOrders(_) = _, %v", client, err)
			}

			if err := streamProcOrder.Send(&wrapper.StringValue{Value: "102"}); err != nil {
				log.Fatalf("%v.Send(%v) = %v", client, "102", err)
			}

			if err := streamProcOrder.Send(&wrapper.StringValue{Value: "103"}); err != nil {
				log.Fatalf("%v.Send(%v) = %v", client, "103", err)
			}

			if err := streamProcOrder.Send(&wrapper.StringValue{Value: "104"}); err != nil {
				log.Fatalf("%v.Send(%v) = %v", client, "104", err)
			}

			channel := make(chan struct{})
			go asncClientBidirectionalRPC(streamProcOrder, channel)
			time.Sleep(time.Millisecond * 1000)

			if err := streamProcOrder.Send(&wrapper.StringValue{Value: "101"}); err != nil {
				log.Fatalf("%v.Send(%v) = %v", client, "101", err)
			}
			if err := streamProcOrder.CloseSend(); err != nil {
				log.Fatal(err)
			}
			channel <- struct{}{}
		}
	}
}

func asncClientBidirectionalRPC(streamProcOrder pb.OrderManagement_ProcessOrdersClient, c chan struct{}) {
	for {
		combinedShipment, errProcOrder := streamProcOrder.Recv()
		if errProcOrder == io.EOF {
			break
		}
		log.Printf("Combined shipment : ", combinedShipment.OrdersList)
	}
	<-c
}
