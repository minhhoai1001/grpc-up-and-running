package main

import (
	"context"
	"log"
	pb "ordermgt/client/ecommerce"
	"time"
	"google.golang.org/grpc"
	"google.golang.org/grpc/status"
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
	
		ctx, cancel := context.WithTimeout(context.Background(), time.Second)
		defer cancel()
	
		// Add Order
		order1 := pb.Order{Id: "101", Items:[]string{"iPhone XS", "Mac Book Pro"}, Destination:"San Jose, CA", Price:2300.00}
		res, addErr := client.AddOrder(ctx, &order1)
	
		if addErr != nil {
			got := status.Code(addErr)
			log.Printf("Error Occured -> addOrder : , %v:", got)
		} else {
			log.Print("AddOrder Response -> ", res.Value)
		}
}

