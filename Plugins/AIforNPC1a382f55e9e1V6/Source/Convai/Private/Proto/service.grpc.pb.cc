#if defined(_WIN32)
#if defined(_MSC_VER)
        #pragma warning (disable:4018) // 'expression' : signed/unsigned mismatch
        #pragma warning (disable:4065) // switch statement contains 'default' but no 'case' labels
        #pragma warning (disable:4146) // unary minus operator applied to unsigned type, result still unsigned
        #pragma warning (disable:4244) // 'conversion' conversion from 'type1' to 'type2', possible loss of data
        #pragma warning (disable:4251) // 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
        #pragma warning (disable:4637) // 'var' : conversion from 'size_t' to 'type', possible loss of data
        #pragma warning (disable:4305) // 'identifier' : truncation from 'type1' to 'type2'
        #pragma warning (disable:4307) // 'operator' : integral constant overflow
        #pragma warning (disable:4309) // 'conversion' : truncation of constant value
        #pragma warning (disable:4334) // 'operator' : result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
        #pragma warning (disable:4355) // 'this' : used in base member initializer list
        #pragma warning (disable:4506) // no definition for inline function 'function'
        #pragma warning (disable:4996) // The compiler encountered a deprecated declaration.
        #pragma warning (disable:4125) // decimal digit terminates octal escape sequence
        #pragma warning (disable:4800) // decimal digit terminates octal escape sequence
        #pragma warning (disable:4668) // decimal digit terminates octal escape sequence
        #endif

        // Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto

#include "service.pb.h"
#include "service.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace service {

static const char* ConvaiService_method_names[] = {
  "/service.ConvaiService/Hello",
  "/service.ConvaiService/HelloStream",
  "/service.ConvaiService/SpeechToText",
  "/service.ConvaiService/GetResponse",
  "/service.ConvaiService/GetResponseSingle",
  "/service.ConvaiService/SubmitFeedback",
};

std::unique_ptr< ConvaiService::Stub> ConvaiService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ConvaiService::Stub> stub(new ConvaiService::Stub(channel, options));
  return stub;
}

ConvaiService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Hello_(ConvaiService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_HelloStream_(ConvaiService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_SpeechToText_(ConvaiService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_GetResponse_(ConvaiService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_GetResponseSingle_(ConvaiService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_SubmitFeedback_(ConvaiService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ConvaiService::Stub::Hello(::grpc::ClientContext* context, const ::service::HelloRequest& request, ::service::HelloResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::service::HelloRequest, ::service::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Hello_, context, request, response);
}

void ConvaiService::Stub::async::Hello(::grpc::ClientContext* context, const ::service::HelloRequest* request, ::service::HelloResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::service::HelloRequest, ::service::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, std::move(f));
}

void ConvaiService::Stub::async::Hello(::grpc::ClientContext* context, const ::service::HelloRequest* request, ::service::HelloResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::service::HelloResponse>* ConvaiService::Stub::PrepareAsyncHelloRaw(::grpc::ClientContext* context, const ::service::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::service::HelloResponse, ::service::HelloRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Hello_, context, request);
}

::grpc::ClientAsyncResponseReader< ::service::HelloResponse>* ConvaiService::Stub::AsyncHelloRaw(::grpc::ClientContext* context, const ::service::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncHelloRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReaderWriter< ::service::HelloRequest, ::service::HelloResponse>* ConvaiService::Stub::HelloStreamRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::service::HelloRequest, ::service::HelloResponse>::Create(channel_.get(), rpcmethod_HelloStream_, context);
}

void ConvaiService::Stub::async::HelloStream(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::service::HelloRequest,::service::HelloResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::service::HelloRequest,::service::HelloResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_HelloStream_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::service::HelloRequest, ::service::HelloResponse>* ConvaiService::Stub::AsyncHelloStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::HelloRequest, ::service::HelloResponse>::Create(channel_.get(), cq, rpcmethod_HelloStream_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::service::HelloRequest, ::service::HelloResponse>* ConvaiService::Stub::PrepareAsyncHelloStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::HelloRequest, ::service::HelloResponse>::Create(channel_.get(), cq, rpcmethod_HelloStream_, context, false, nullptr);
}

::grpc::ClientReaderWriter< ::service::STTRequest, ::service::STTResponse>* ConvaiService::Stub::SpeechToTextRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::service::STTRequest, ::service::STTResponse>::Create(channel_.get(), rpcmethod_SpeechToText_, context);
}

void ConvaiService::Stub::async::SpeechToText(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::service::STTRequest,::service::STTResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::service::STTRequest,::service::STTResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_SpeechToText_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::service::STTRequest, ::service::STTResponse>* ConvaiService::Stub::AsyncSpeechToTextRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::STTRequest, ::service::STTResponse>::Create(channel_.get(), cq, rpcmethod_SpeechToText_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::service::STTRequest, ::service::STTResponse>* ConvaiService::Stub::PrepareAsyncSpeechToTextRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::STTRequest, ::service::STTResponse>::Create(channel_.get(), cq, rpcmethod_SpeechToText_, context, false, nullptr);
}

::grpc::ClientReaderWriter< ::service::GetResponseRequest, ::service::GetResponseResponse>* ConvaiService::Stub::GetResponseRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::service::GetResponseRequest, ::service::GetResponseResponse>::Create(channel_.get(), rpcmethod_GetResponse_, context);
}

void ConvaiService::Stub::async::GetResponse(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::service::GetResponseRequest,::service::GetResponseResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::service::GetResponseRequest,::service::GetResponseResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_GetResponse_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::service::GetResponseRequest, ::service::GetResponseResponse>* ConvaiService::Stub::AsyncGetResponseRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::GetResponseRequest, ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponse_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::service::GetResponseRequest, ::service::GetResponseResponse>* ConvaiService::Stub::PrepareAsyncGetResponseRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::GetResponseRequest, ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponse_, context, false, nullptr);
}

::grpc::ClientReader< ::service::GetResponseResponse>* ConvaiService::Stub::GetResponseSingleRaw(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle& request) {
  return ::grpc::internal::ClientReaderFactory< ::service::GetResponseResponse>::Create(channel_.get(), rpcmethod_GetResponseSingle_, context, request);
}

void ConvaiService::Stub::async::GetResponseSingle(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle* request, ::grpc::ClientReadReactor< ::service::GetResponseResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::service::GetResponseResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_GetResponseSingle_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::service::GetResponseResponse>* ConvaiService::Stub::AsyncGetResponseSingleRaw(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponseSingle_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::service::GetResponseResponse>* ConvaiService::Stub::PrepareAsyncGetResponseSingleRaw(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponseSingle_, context, request, false, nullptr);
}

::grpc::Status ConvaiService::Stub::SubmitFeedback(::grpc::ClientContext* context, const ::service::FeedbackRequest& request, ::service::FeedbackResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::service::FeedbackRequest, ::service::FeedbackResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SubmitFeedback_, context, request, response);
}

void ConvaiService::Stub::async::SubmitFeedback(::grpc::ClientContext* context, const ::service::FeedbackRequest* request, ::service::FeedbackResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::service::FeedbackRequest, ::service::FeedbackResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SubmitFeedback_, context, request, response, std::move(f));
}

void ConvaiService::Stub::async::SubmitFeedback(::grpc::ClientContext* context, const ::service::FeedbackRequest* request, ::service::FeedbackResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SubmitFeedback_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::service::FeedbackResponse>* ConvaiService::Stub::PrepareAsyncSubmitFeedbackRaw(::grpc::ClientContext* context, const ::service::FeedbackRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::service::FeedbackResponse, ::service::FeedbackRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SubmitFeedback_, context, request);
}

::grpc::ClientAsyncResponseReader< ::service::FeedbackResponse>* ConvaiService::Stub::AsyncSubmitFeedbackRaw(::grpc::ClientContext* context, const ::service::FeedbackRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSubmitFeedbackRaw(context, request, cq);
  result->StartCall();
  return result;
}

ConvaiService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ConvaiService::Service, ::service::HelloRequest, ::service::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::HelloRequest* req,
             ::service::HelloResponse* resp) {
               return service->Hello(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[1],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< ConvaiService::Service, ::service::HelloRequest, ::service::HelloResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::service::HelloResponse,
             ::service::HelloRequest>* stream) {
               return service->HelloStream(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[2],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< ConvaiService::Service, ::service::STTRequest, ::service::STTResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::service::STTResponse,
             ::service::STTRequest>* stream) {
               return service->SpeechToText(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[3],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< ConvaiService::Service, ::service::GetResponseRequest, ::service::GetResponseResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::service::GetResponseResponse,
             ::service::GetResponseRequest>* stream) {
               return service->GetResponse(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[4],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< ConvaiService::Service, ::service::GetResponseRequestSingle, ::service::GetResponseResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::GetResponseRequestSingle* req,
             ::grpc::ServerWriter<::service::GetResponseResponse>* writer) {
               return service->GetResponseSingle(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ConvaiService::Service, ::service::FeedbackRequest, ::service::FeedbackResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::FeedbackRequest* req,
             ::service::FeedbackResponse* resp) {
               return service->SubmitFeedback(ctx, req, resp);
             }, this)));
}

ConvaiService::Service::~Service() {
}

::grpc::Status ConvaiService::Service::Hello(::grpc::ServerContext* context, const ::service::HelloRequest* request, ::service::HelloResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::HelloStream(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::service::HelloResponse, ::service::HelloRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::SpeechToText(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::service::STTResponse, ::service::STTRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::GetResponse(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::service::GetResponseResponse, ::service::GetResponseRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::GetResponseSingle(::grpc::ServerContext* context, const ::service::GetResponseRequestSingle* request, ::grpc::ServerWriter< ::service::GetResponseResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::SubmitFeedback(::grpc::ServerContext* context, const ::service::FeedbackRequest* request, ::service::FeedbackResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace service

#else
// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto

#include "service.pb.h"
#include "service.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace service {

static const char* ConvaiService_method_names[] = {
  "/service.ConvaiService/Hello",
  "/service.ConvaiService/HelloStream",
  "/service.ConvaiService/SpeechToText",
  "/service.ConvaiService/GetResponse",
  "/service.ConvaiService/GetResponseSingle",
  "/service.ConvaiService/SubmitFeedback",
};

std::unique_ptr< ConvaiService::Stub> ConvaiService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ConvaiService::Stub> stub(new ConvaiService::Stub(channel, options));
  return stub;
}

ConvaiService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Hello_(ConvaiService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_HelloStream_(ConvaiService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_SpeechToText_(ConvaiService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_GetResponse_(ConvaiService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_GetResponseSingle_(ConvaiService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_SubmitFeedback_(ConvaiService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ConvaiService::Stub::Hello(::grpc::ClientContext* context, const ::service::HelloRequest& request, ::service::HelloResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::service::HelloRequest, ::service::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Hello_, context, request, response);
}

void ConvaiService::Stub::async::Hello(::grpc::ClientContext* context, const ::service::HelloRequest* request, ::service::HelloResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::service::HelloRequest, ::service::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, std::move(f));
}

void ConvaiService::Stub::async::Hello(::grpc::ClientContext* context, const ::service::HelloRequest* request, ::service::HelloResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Hello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::service::HelloResponse>* ConvaiService::Stub::PrepareAsyncHelloRaw(::grpc::ClientContext* context, const ::service::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::service::HelloResponse, ::service::HelloRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Hello_, context, request);
}

::grpc::ClientAsyncResponseReader< ::service::HelloResponse>* ConvaiService::Stub::AsyncHelloRaw(::grpc::ClientContext* context, const ::service::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncHelloRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReaderWriter< ::service::HelloRequest, ::service::HelloResponse>* ConvaiService::Stub::HelloStreamRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::service::HelloRequest, ::service::HelloResponse>::Create(channel_.get(), rpcmethod_HelloStream_, context);
}

void ConvaiService::Stub::async::HelloStream(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::service::HelloRequest,::service::HelloResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::service::HelloRequest,::service::HelloResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_HelloStream_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::service::HelloRequest, ::service::HelloResponse>* ConvaiService::Stub::AsyncHelloStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::HelloRequest, ::service::HelloResponse>::Create(channel_.get(), cq, rpcmethod_HelloStream_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::service::HelloRequest, ::service::HelloResponse>* ConvaiService::Stub::PrepareAsyncHelloStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::HelloRequest, ::service::HelloResponse>::Create(channel_.get(), cq, rpcmethod_HelloStream_, context, false, nullptr);
}

::grpc::ClientReaderWriter< ::service::STTRequest, ::service::STTResponse>* ConvaiService::Stub::SpeechToTextRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::service::STTRequest, ::service::STTResponse>::Create(channel_.get(), rpcmethod_SpeechToText_, context);
}

void ConvaiService::Stub::async::SpeechToText(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::service::STTRequest,::service::STTResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::service::STTRequest,::service::STTResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_SpeechToText_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::service::STTRequest, ::service::STTResponse>* ConvaiService::Stub::AsyncSpeechToTextRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::STTRequest, ::service::STTResponse>::Create(channel_.get(), cq, rpcmethod_SpeechToText_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::service::STTRequest, ::service::STTResponse>* ConvaiService::Stub::PrepareAsyncSpeechToTextRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::STTRequest, ::service::STTResponse>::Create(channel_.get(), cq, rpcmethod_SpeechToText_, context, false, nullptr);
}

::grpc::ClientReaderWriter< ::service::GetResponseRequest, ::service::GetResponseResponse>* ConvaiService::Stub::GetResponseRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::service::GetResponseRequest, ::service::GetResponseResponse>::Create(channel_.get(), rpcmethod_GetResponse_, context);
}

void ConvaiService::Stub::async::GetResponse(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::service::GetResponseRequest,::service::GetResponseResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::service::GetResponseRequest,::service::GetResponseResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_GetResponse_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::service::GetResponseRequest, ::service::GetResponseResponse>* ConvaiService::Stub::AsyncGetResponseRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::GetResponseRequest, ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponse_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::service::GetResponseRequest, ::service::GetResponseResponse>* ConvaiService::Stub::PrepareAsyncGetResponseRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::service::GetResponseRequest, ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponse_, context, false, nullptr);
}

::grpc::ClientReader< ::service::GetResponseResponse>* ConvaiService::Stub::GetResponseSingleRaw(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle& request) {
  return ::grpc::internal::ClientReaderFactory< ::service::GetResponseResponse>::Create(channel_.get(), rpcmethod_GetResponseSingle_, context, request);
}

void ConvaiService::Stub::async::GetResponseSingle(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle* request, ::grpc::ClientReadReactor< ::service::GetResponseResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::service::GetResponseResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_GetResponseSingle_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::service::GetResponseResponse>* ConvaiService::Stub::AsyncGetResponseSingleRaw(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponseSingle_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::service::GetResponseResponse>* ConvaiService::Stub::PrepareAsyncGetResponseSingleRaw(::grpc::ClientContext* context, const ::service::GetResponseRequestSingle& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::service::GetResponseResponse>::Create(channel_.get(), cq, rpcmethod_GetResponseSingle_, context, request, false, nullptr);
}

::grpc::Status ConvaiService::Stub::SubmitFeedback(::grpc::ClientContext* context, const ::service::FeedbackRequest& request, ::service::FeedbackResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::service::FeedbackRequest, ::service::FeedbackResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SubmitFeedback_, context, request, response);
}

void ConvaiService::Stub::async::SubmitFeedback(::grpc::ClientContext* context, const ::service::FeedbackRequest* request, ::service::FeedbackResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::service::FeedbackRequest, ::service::FeedbackResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SubmitFeedback_, context, request, response, std::move(f));
}

void ConvaiService::Stub::async::SubmitFeedback(::grpc::ClientContext* context, const ::service::FeedbackRequest* request, ::service::FeedbackResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SubmitFeedback_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::service::FeedbackResponse>* ConvaiService::Stub::PrepareAsyncSubmitFeedbackRaw(::grpc::ClientContext* context, const ::service::FeedbackRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::service::FeedbackResponse, ::service::FeedbackRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SubmitFeedback_, context, request);
}

::grpc::ClientAsyncResponseReader< ::service::FeedbackResponse>* ConvaiService::Stub::AsyncSubmitFeedbackRaw(::grpc::ClientContext* context, const ::service::FeedbackRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSubmitFeedbackRaw(context, request, cq);
  result->StartCall();
  return result;
}

ConvaiService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ConvaiService::Service, ::service::HelloRequest, ::service::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::HelloRequest* req,
             ::service::HelloResponse* resp) {
               return service->Hello(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[1],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< ConvaiService::Service, ::service::HelloRequest, ::service::HelloResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::service::HelloResponse,
             ::service::HelloRequest>* stream) {
               return service->HelloStream(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[2],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< ConvaiService::Service, ::service::STTRequest, ::service::STTResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::service::STTResponse,
             ::service::STTRequest>* stream) {
               return service->SpeechToText(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[3],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< ConvaiService::Service, ::service::GetResponseRequest, ::service::GetResponseResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::service::GetResponseResponse,
             ::service::GetResponseRequest>* stream) {
               return service->GetResponse(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[4],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< ConvaiService::Service, ::service::GetResponseRequestSingle, ::service::GetResponseResponse>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::GetResponseRequestSingle* req,
             ::grpc::ServerWriter<::service::GetResponseResponse>* writer) {
               return service->GetResponseSingle(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConvaiService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ConvaiService::Service, ::service::FeedbackRequest, ::service::FeedbackResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ConvaiService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::FeedbackRequest* req,
             ::service::FeedbackResponse* resp) {
               return service->SubmitFeedback(ctx, req, resp);
             }, this)));
}

ConvaiService::Service::~Service() {
}

::grpc::Status ConvaiService::Service::Hello(::grpc::ServerContext* context, const ::service::HelloRequest* request, ::service::HelloResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::HelloStream(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::service::HelloResponse, ::service::HelloRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::SpeechToText(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::service::STTResponse, ::service::STTRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::GetResponse(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::service::GetResponseResponse, ::service::GetResponseRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::GetResponseSingle(::grpc::ServerContext* context, const ::service::GetResponseRequestSingle* request, ::grpc::ServerWriter< ::service::GetResponseResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status ConvaiService::Service::SubmitFeedback(::grpc::ServerContext* context, const ::service::FeedbackRequest* request, ::service::FeedbackResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace service


#endif
