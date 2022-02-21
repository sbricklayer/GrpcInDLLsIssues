#include <grpc++/create_channel.h>
#include <example_service.grpc.pb.h>
#include "GrpcClient1.h"
#include <GrpcClientContextProvider.h>

//#define CROSS_DLL_CLIENT_CONTEXT_USE

void callExampleService()
{
  auto channel_ptr = CreateChannel("localhost:12010",grpc::InsecureChannelCredentials());
  auto example_service_client = StaticGrpcExample::ExampleService::NewStub(channel_ptr);

  StaticGrpcExample::ExampleRpcRequest request;
  StaticGrpcExample::ExampleRpcResponse response;

#ifdef CROSS_DLL_CLIENT_CONTEXT_USE
  //This leads to an access violation
  DLL2::ClientContextProvider client_context_provider; 
  example_service_client->ExampleRpc(&client_context_provider.get_client_context(), request, &response);
#else
  //This approach works fine
  grpc::ClientContext client_context;
  example_service_client->ExampleRpc(&client_context, request, &response);
#endif
}