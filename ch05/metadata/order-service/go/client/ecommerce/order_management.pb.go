// Code generated by protoc-gen-go. DO NOT EDIT.
// source: order_management.proto

package ecommerce

import (
	context "context"
	fmt "fmt"
	proto "github.com/golang/protobuf/proto"
	wrappers "github.com/golang/protobuf/ptypes/wrappers"
	grpc "google.golang.org/grpc"
	codes "google.golang.org/grpc/codes"
	status "google.golang.org/grpc/status"
	math "math"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion3 // please upgrade the proto package

type Order struct {
	Id                   string   `protobuf:"bytes,1,opt,name=id,proto3" json:"id,omitempty"`
	Items                []string `protobuf:"bytes,2,rep,name=items,proto3" json:"items,omitempty"`
	Description          string   `protobuf:"bytes,3,opt,name=description,proto3" json:"description,omitempty"`
	Price                float32  `protobuf:"fixed32,4,opt,name=price,proto3" json:"price,omitempty"`
	Destination          string   `protobuf:"bytes,5,opt,name=destination,proto3" json:"destination,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *Order) Reset()         { *m = Order{} }
func (m *Order) String() string { return proto.CompactTextString(m) }
func (*Order) ProtoMessage()    {}
func (*Order) Descriptor() ([]byte, []int) {
	return fileDescriptor_6653354279552460, []int{0}
}

func (m *Order) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_Order.Unmarshal(m, b)
}
func (m *Order) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_Order.Marshal(b, m, deterministic)
}
func (m *Order) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Order.Merge(m, src)
}
func (m *Order) XXX_Size() int {
	return xxx_messageInfo_Order.Size(m)
}
func (m *Order) XXX_DiscardUnknown() {
	xxx_messageInfo_Order.DiscardUnknown(m)
}

var xxx_messageInfo_Order proto.InternalMessageInfo

func (m *Order) GetId() string {
	if m != nil {
		return m.Id
	}
	return ""
}

func (m *Order) GetItems() []string {
	if m != nil {
		return m.Items
	}
	return nil
}

func (m *Order) GetDescription() string {
	if m != nil {
		return m.Description
	}
	return ""
}

func (m *Order) GetPrice() float32 {
	if m != nil {
		return m.Price
	}
	return 0
}

func (m *Order) GetDestination() string {
	if m != nil {
		return m.Destination
	}
	return ""
}

type CombinedShipment struct {
	Id                   string   `protobuf:"bytes,1,opt,name=id,proto3" json:"id,omitempty"`
	Status               string   `protobuf:"bytes,2,opt,name=status,proto3" json:"status,omitempty"`
	OrdersList           []*Order `protobuf:"bytes,3,rep,name=ordersList,proto3" json:"ordersList,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *CombinedShipment) Reset()         { *m = CombinedShipment{} }
func (m *CombinedShipment) String() string { return proto.CompactTextString(m) }
func (*CombinedShipment) ProtoMessage()    {}
func (*CombinedShipment) Descriptor() ([]byte, []int) {
	return fileDescriptor_6653354279552460, []int{1}
}

func (m *CombinedShipment) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_CombinedShipment.Unmarshal(m, b)
}
func (m *CombinedShipment) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_CombinedShipment.Marshal(b, m, deterministic)
}
func (m *CombinedShipment) XXX_Merge(src proto.Message) {
	xxx_messageInfo_CombinedShipment.Merge(m, src)
}
func (m *CombinedShipment) XXX_Size() int {
	return xxx_messageInfo_CombinedShipment.Size(m)
}
func (m *CombinedShipment) XXX_DiscardUnknown() {
	xxx_messageInfo_CombinedShipment.DiscardUnknown(m)
}

var xxx_messageInfo_CombinedShipment proto.InternalMessageInfo

func (m *CombinedShipment) GetId() string {
	if m != nil {
		return m.Id
	}
	return ""
}

func (m *CombinedShipment) GetStatus() string {
	if m != nil {
		return m.Status
	}
	return ""
}

func (m *CombinedShipment) GetOrdersList() []*Order {
	if m != nil {
		return m.OrdersList
	}
	return nil
}

func init() {
	proto.RegisterType((*Order)(nil), "ecommerce.Order")
	proto.RegisterType((*CombinedShipment)(nil), "ecommerce.CombinedShipment")
}

func init() { proto.RegisterFile("order_management.proto", fileDescriptor_6653354279552460) }

var fileDescriptor_6653354279552460 = []byte{
	// 330 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x94, 0x91, 0x5f, 0x4b, 0xc3, 0x30,
	0x14, 0xc5, 0x49, 0xeb, 0x86, 0xbb, 0xf3, 0xcf, 0x08, 0x32, 0xca, 0x14, 0x29, 0x7b, 0xea, 0x53,
	0x37, 0xe6, 0x9b, 0x4f, 0x82, 0xaf, 0xfe, 0x81, 0x0e, 0x7c, 0x95, 0xac, 0xb9, 0x76, 0x81, 0xb5,
	0x09, 0x49, 0x8a, 0x1f, 0xc1, 0x4f, 0xe9, 0x77, 0x91, 0x24, 0xdb, 0x18, 0x16, 0xc4, 0x3d, 0xde,
	0xdb, 0xf3, 0x3b, 0x3d, 0xf7, 0x04, 0xc6, 0x52, 0x73, 0xd4, 0xef, 0x35, 0x6b, 0x58, 0x85, 0x35,
	0x36, 0x36, 0x57, 0x5a, 0x5a, 0x49, 0x07, 0x58, 0xca, 0xba, 0x46, 0x5d, 0xe2, 0xe4, 0xb6, 0x92,
	0xb2, 0xda, 0xe0, 0xcc, 0x7f, 0x58, 0xb5, 0x1f, 0xb3, 0x4f, 0xcd, 0x94, 0x42, 0x6d, 0x82, 0x74,
	0xfa, 0x45, 0xa0, 0xf7, 0xea, 0x5c, 0xe8, 0x05, 0x44, 0x82, 0x27, 0x24, 0x25, 0xd9, 0xa0, 0x88,
	0x04, 0xa7, 0x57, 0xd0, 0x13, 0x16, 0x6b, 0x93, 0x44, 0x69, 0x9c, 0x0d, 0x8a, 0x30, 0xd0, 0x14,
	0x86, 0x1c, 0x4d, 0xa9, 0x85, 0xb2, 0x42, 0x36, 0x49, 0xec, 0xe5, 0x87, 0x2b, 0xc7, 0x29, 0x2d,
	0x4a, 0x4c, 0x4e, 0x52, 0x92, 0x45, 0x45, 0x18, 0xb6, 0x9c, 0x15, 0x0d, 0xf3, 0x5c, 0x6f, 0xcf,
	0xed, 0x56, 0xd3, 0x0d, 0x8c, 0x1e, 0x65, 0xbd, 0x12, 0x0d, 0xf2, 0xe5, 0x5a, 0x28, 0x77, 0x4e,
	0x27, 0xd3, 0x18, 0xfa, 0xc6, 0x32, 0xdb, 0xba, 0x50, 0x6e, 0xb7, 0x9d, 0xe8, 0x1c, 0xc0, 0x57,
	0x61, 0x9e, 0x84, 0xb1, 0x49, 0x9c, 0xc6, 0xd9, 0x70, 0x31, 0xca, 0xf7, 0x2d, 0xe4, 0xfe, 0xc2,
	0xe2, 0x40, 0xb3, 0xf8, 0x8e, 0xe0, 0xd2, 0x6f, 0x9f, 0xf7, 0xe5, 0xd1, 0x7b, 0x38, 0x65, 0x9c,
	0x87, 0x36, 0x3a, 0xf4, 0xe4, 0x26, 0x0f, 0x55, 0xe6, 0xbb, 0x2a, 0xf3, 0xa5, 0xd5, 0xa2, 0xa9,
	0xde, 0xd8, 0xa6, 0x45, 0xc7, 0x56, 0x68, 0x03, 0xfb, 0xa7, 0x72, 0xd2, 0x71, 0xa6, 0x0f, 0x70,
	0x66, 0x90, 0xe9, 0x72, 0xed, 0x47, 0x73, 0x2c, 0x3f, 0x27, 0xce, 0xa1, 0x55, 0x9c, 0x59, 0xdc,
	0x3a, 0x1c, 0x99, 0x3e, 0x23, 0xf4, 0x05, 0xce, 0x95, 0x96, 0x25, 0x1a, 0xf3, 0xaf, 0x10, 0xd7,
	0x07, 0x3f, 0xf8, 0xfd, 0x6a, 0x19, 0x99, 0x93, 0x55, 0xdf, 0x63, 0x77, 0x3f, 0x01, 0x00, 0x00,
	0xff, 0xff, 0xed, 0x7a, 0x7f, 0xf8, 0xa3, 0x02, 0x00, 0x00,
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// OrderManagementClient is the client API for OrderManagement service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://godoc.org/google.golang.org/grpc#ClientConn.NewStream.
type OrderManagementClient interface {
	AddOrder(ctx context.Context, in *Order, opts ...grpc.CallOption) (*wrappers.StringValue, error)
	GetOrder(ctx context.Context, in *wrappers.StringValue, opts ...grpc.CallOption) (*Order, error)
	SearchOrders(ctx context.Context, in *wrappers.StringValue, opts ...grpc.CallOption) (OrderManagement_SearchOrdersClient, error)
	UpdateOrders(ctx context.Context, opts ...grpc.CallOption) (OrderManagement_UpdateOrdersClient, error)
	ProcessOrders(ctx context.Context, opts ...grpc.CallOption) (OrderManagement_ProcessOrdersClient, error)
}

type orderManagementClient struct {
	cc *grpc.ClientConn
}

func NewOrderManagementClient(cc *grpc.ClientConn) OrderManagementClient {
	return &orderManagementClient{cc}
}

func (c *orderManagementClient) AddOrder(ctx context.Context, in *Order, opts ...grpc.CallOption) (*wrappers.StringValue, error) {
	out := new(wrappers.StringValue)
	err := c.cc.Invoke(ctx, "/ecommerce.OrderManagement/addOrder", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *orderManagementClient) GetOrder(ctx context.Context, in *wrappers.StringValue, opts ...grpc.CallOption) (*Order, error) {
	out := new(Order)
	err := c.cc.Invoke(ctx, "/ecommerce.OrderManagement/getOrder", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *orderManagementClient) SearchOrders(ctx context.Context, in *wrappers.StringValue, opts ...grpc.CallOption) (OrderManagement_SearchOrdersClient, error) {
	stream, err := c.cc.NewStream(ctx, &_OrderManagement_serviceDesc.Streams[0], "/ecommerce.OrderManagement/searchOrders", opts...)
	if err != nil {
		return nil, err
	}
	x := &orderManagementSearchOrdersClient{stream}
	if err := x.ClientStream.SendMsg(in); err != nil {
		return nil, err
	}
	if err := x.ClientStream.CloseSend(); err != nil {
		return nil, err
	}
	return x, nil
}

type OrderManagement_SearchOrdersClient interface {
	Recv() (*Order, error)
	grpc.ClientStream
}

type orderManagementSearchOrdersClient struct {
	grpc.ClientStream
}

func (x *orderManagementSearchOrdersClient) Recv() (*Order, error) {
	m := new(Order)
	if err := x.ClientStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

func (c *orderManagementClient) UpdateOrders(ctx context.Context, opts ...grpc.CallOption) (OrderManagement_UpdateOrdersClient, error) {
	stream, err := c.cc.NewStream(ctx, &_OrderManagement_serviceDesc.Streams[1], "/ecommerce.OrderManagement/updateOrders", opts...)
	if err != nil {
		return nil, err
	}
	x := &orderManagementUpdateOrdersClient{stream}
	return x, nil
}

type OrderManagement_UpdateOrdersClient interface {
	Send(*Order) error
	CloseAndRecv() (*wrappers.StringValue, error)
	grpc.ClientStream
}

type orderManagementUpdateOrdersClient struct {
	grpc.ClientStream
}

func (x *orderManagementUpdateOrdersClient) Send(m *Order) error {
	return x.ClientStream.SendMsg(m)
}

func (x *orderManagementUpdateOrdersClient) CloseAndRecv() (*wrappers.StringValue, error) {
	if err := x.ClientStream.CloseSend(); err != nil {
		return nil, err
	}
	m := new(wrappers.StringValue)
	if err := x.ClientStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

func (c *orderManagementClient) ProcessOrders(ctx context.Context, opts ...grpc.CallOption) (OrderManagement_ProcessOrdersClient, error) {
	stream, err := c.cc.NewStream(ctx, &_OrderManagement_serviceDesc.Streams[2], "/ecommerce.OrderManagement/processOrders", opts...)
	if err != nil {
		return nil, err
	}
	x := &orderManagementProcessOrdersClient{stream}
	return x, nil
}

type OrderManagement_ProcessOrdersClient interface {
	Send(*wrappers.StringValue) error
	Recv() (*CombinedShipment, error)
	grpc.ClientStream
}

type orderManagementProcessOrdersClient struct {
	grpc.ClientStream
}

func (x *orderManagementProcessOrdersClient) Send(m *wrappers.StringValue) error {
	return x.ClientStream.SendMsg(m)
}

func (x *orderManagementProcessOrdersClient) Recv() (*CombinedShipment, error) {
	m := new(CombinedShipment)
	if err := x.ClientStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

// OrderManagementServer is the server API for OrderManagement service.
type OrderManagementServer interface {
	AddOrder(context.Context, *Order) (*wrappers.StringValue, error)
	GetOrder(context.Context, *wrappers.StringValue) (*Order, error)
	SearchOrders(*wrappers.StringValue, OrderManagement_SearchOrdersServer) error
	UpdateOrders(OrderManagement_UpdateOrdersServer) error
	ProcessOrders(OrderManagement_ProcessOrdersServer) error
}

// UnimplementedOrderManagementServer can be embedded to have forward compatible implementations.
type UnimplementedOrderManagementServer struct {
}

func (*UnimplementedOrderManagementServer) AddOrder(ctx context.Context, req *Order) (*wrappers.StringValue, error) {
	return nil, status.Errorf(codes.Unimplemented, "method AddOrder not implemented")
}
func (*UnimplementedOrderManagementServer) GetOrder(ctx context.Context, req *wrappers.StringValue) (*Order, error) {
	return nil, status.Errorf(codes.Unimplemented, "method GetOrder not implemented")
}
func (*UnimplementedOrderManagementServer) SearchOrders(req *wrappers.StringValue, srv OrderManagement_SearchOrdersServer) error {
	return status.Errorf(codes.Unimplemented, "method SearchOrders not implemented")
}
func (*UnimplementedOrderManagementServer) UpdateOrders(srv OrderManagement_UpdateOrdersServer) error {
	return status.Errorf(codes.Unimplemented, "method UpdateOrders not implemented")
}
func (*UnimplementedOrderManagementServer) ProcessOrders(srv OrderManagement_ProcessOrdersServer) error {
	return status.Errorf(codes.Unimplemented, "method ProcessOrders not implemented")
}

func RegisterOrderManagementServer(s *grpc.Server, srv OrderManagementServer) {
	s.RegisterService(&_OrderManagement_serviceDesc, srv)
}

func _OrderManagement_AddOrder_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(Order)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(OrderManagementServer).AddOrder(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/ecommerce.OrderManagement/AddOrder",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(OrderManagementServer).AddOrder(ctx, req.(*Order))
	}
	return interceptor(ctx, in, info, handler)
}

func _OrderManagement_GetOrder_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(wrappers.StringValue)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(OrderManagementServer).GetOrder(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/ecommerce.OrderManagement/GetOrder",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(OrderManagementServer).GetOrder(ctx, req.(*wrappers.StringValue))
	}
	return interceptor(ctx, in, info, handler)
}

func _OrderManagement_SearchOrders_Handler(srv interface{}, stream grpc.ServerStream) error {
	m := new(wrappers.StringValue)
	if err := stream.RecvMsg(m); err != nil {
		return err
	}
	return srv.(OrderManagementServer).SearchOrders(m, &orderManagementSearchOrdersServer{stream})
}

type OrderManagement_SearchOrdersServer interface {
	Send(*Order) error
	grpc.ServerStream
}

type orderManagementSearchOrdersServer struct {
	grpc.ServerStream
}

func (x *orderManagementSearchOrdersServer) Send(m *Order) error {
	return x.ServerStream.SendMsg(m)
}

func _OrderManagement_UpdateOrders_Handler(srv interface{}, stream grpc.ServerStream) error {
	return srv.(OrderManagementServer).UpdateOrders(&orderManagementUpdateOrdersServer{stream})
}

type OrderManagement_UpdateOrdersServer interface {
	SendAndClose(*wrappers.StringValue) error
	Recv() (*Order, error)
	grpc.ServerStream
}

type orderManagementUpdateOrdersServer struct {
	grpc.ServerStream
}

func (x *orderManagementUpdateOrdersServer) SendAndClose(m *wrappers.StringValue) error {
	return x.ServerStream.SendMsg(m)
}

func (x *orderManagementUpdateOrdersServer) Recv() (*Order, error) {
	m := new(Order)
	if err := x.ServerStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

func _OrderManagement_ProcessOrders_Handler(srv interface{}, stream grpc.ServerStream) error {
	return srv.(OrderManagementServer).ProcessOrders(&orderManagementProcessOrdersServer{stream})
}

type OrderManagement_ProcessOrdersServer interface {
	Send(*CombinedShipment) error
	Recv() (*wrappers.StringValue, error)
	grpc.ServerStream
}

type orderManagementProcessOrdersServer struct {
	grpc.ServerStream
}

func (x *orderManagementProcessOrdersServer) Send(m *CombinedShipment) error {
	return x.ServerStream.SendMsg(m)
}

func (x *orderManagementProcessOrdersServer) Recv() (*wrappers.StringValue, error) {
	m := new(wrappers.StringValue)
	if err := x.ServerStream.RecvMsg(m); err != nil {
		return nil, err
	}
	return m, nil
}

var _OrderManagement_serviceDesc = grpc.ServiceDesc{
	ServiceName: "ecommerce.OrderManagement",
	HandlerType: (*OrderManagementServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "addOrder",
			Handler:    _OrderManagement_AddOrder_Handler,
		},
		{
			MethodName: "getOrder",
			Handler:    _OrderManagement_GetOrder_Handler,
		},
	},
	Streams: []grpc.StreamDesc{
		{
			StreamName:    "searchOrders",
			Handler:       _OrderManagement_SearchOrders_Handler,
			ServerStreams: true,
		},
		{
			StreamName:    "updateOrders",
			Handler:       _OrderManagement_UpdateOrders_Handler,
			ClientStreams: true,
		},
		{
			StreamName:    "processOrders",
			Handler:       _OrderManagement_ProcessOrders_Handler,
			ServerStreams: true,
			ClientStreams: true,
		},
	},
	Metadata: "order_management.proto",
}