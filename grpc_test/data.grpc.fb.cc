// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: data

#include "data_generated.h"
#include "data.grpc.fb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace CppFlatBufGrpc {
namespace Sample {

static const char* DataStorage_method_names[] = {
  "/CppFlatBufGrpc.Sample.DataStorage/Store",
  "/CppFlatBufGrpc.Sample.DataStorage/Retrieve",
};

std::unique_ptr< DataStorage::Stub> DataStorage::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< DataStorage::Stub> stub(new DataStorage::Stub(channel));
  return stub;
}

DataStorage::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel)  , rpcmethod_Store_(DataStorage_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Retrieve_(DataStorage_method_names[1], ::grpc::RpcMethod::SERVER_STREAMING, channel)
  {}
  
::grpc::Status DataStorage::Stub::Store(::grpc::ClientContext* context, const flatbuffers::BufferRef<Data>& request, flatbuffers::BufferRef<Stat>* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Store_, context, request, response);
}

::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<Stat>>* DataStorage::Stub::AsyncStoreRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Data>& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<Stat>>(channel_.get(), cq, rpcmethod_Store_, context, request);
}

::grpc::ClientReader< flatbuffers::BufferRef<Data>>* DataStorage::Stub::RetrieveRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Stat>& request) {
  return new ::grpc::ClientReader< flatbuffers::BufferRef<Data>>(channel_.get(), rpcmethod_Retrieve_, context, request);
}

::grpc::ClientAsyncReader< flatbuffers::BufferRef<Data>>* DataStorage::Stub::AsyncRetrieveRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<Stat>& request, ::grpc::CompletionQueue* cq, void* tag) {
  return new ::grpc::ClientAsyncReader< flatbuffers::BufferRef<Data>>(channel_.get(), cq, rpcmethod_Retrieve_, context, request, tag);
}

DataStorage::Service::Service() {
  (void)DataStorage_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      DataStorage_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< DataStorage::Service, flatbuffers::BufferRef<Data>, flatbuffers::BufferRef<Stat>>(
          std::mem_fn(&DataStorage::Service::Store), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      DataStorage_method_names[1],
      ::grpc::RpcMethod::SERVER_STREAMING,
      new ::grpc::ServerStreamingHandler< DataStorage::Service, flatbuffers::BufferRef<Stat>, flatbuffers::BufferRef<Data>>(
          std::mem_fn(&DataStorage::Service::Retrieve), this)));
}

DataStorage::Service::~Service() {
}

::grpc::Status DataStorage::Service::Store(::grpc::ServerContext* context, const flatbuffers::BufferRef<Data>* request, flatbuffers::BufferRef<Stat>* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status DataStorage::Service::Retrieve(::grpc::ServerContext* context, const flatbuffers::BufferRef<Stat>* request, ::grpc::ServerWriter< flatbuffers::BufferRef<Data>>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace CppFlatBufGrpc
}  // namespace Sample
