#ifndef GRPCCLIENTCONTEXTPROVIDER_H
#define GRPCCLIENTCONTEXTPROVIDER_H

#include <grpcpp/client_context.h>
#include "dll2_export.h"

namespace DLL2 {
  //The actual motivation to create a class like this in a separate DLL, was to
  //abstract the cancellation concept in a way that can be used in several gRPC-based client DLLs.
  //In actual production code such a class might provide a bridge between
  //the cancellation concept of the main software (e.g., polling some atomic bool)
  //and gRPC (calling ClientContext::TryCancel()). There might be other use-cases as well.
  //For the sake of simplicity, the example was reduced to the bare minimum.
  class DLL2_EXPORT ClientContextProvider
  {
  public:
    grpc::ClientContext& get_client_context();
  private:
    grpc::ClientContext client_context_;
  };
}

#endif // GRPCCLIENTCONTEXTPROVIDER_H
