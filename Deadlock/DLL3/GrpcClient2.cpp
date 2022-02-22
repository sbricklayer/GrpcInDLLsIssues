#include <grpc++/create_channel.h>
#include <example_service2.grpc.pb.h>
#include "GrpcClient2.h"

class ExampleService2Accessor::Impl
{

public:
  Impl()
  {
    auto channel_ptr = CreateChannel("localhost:12010",grpc::InsecureChannelCredentials());
    example_service_client_ = ExampleService2::NewStub(channel_ptr);
  }

private:
  std::unique_ptr<ExampleService2::Stub> example_service_client_;
};

ExampleService2Accessor::ExampleService2Accessor() : pimpl_(std::make_unique<Impl>())
{
}

ExampleService2Accessor& ExampleService2Accessor::getInstance()
{
  static ExampleService2Accessor instance;
  return instance;
}