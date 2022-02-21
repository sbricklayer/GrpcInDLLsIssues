#ifndef GRPCCLIENTCONTEXTPROVIDER_H
#define GRPCCLIENTCONTEXTPROVIDER_H

#include <grpcpp/client_context.h>
#include "dll2_export.h"

namespace DLL2 {
  class DLL2_EXPORT ClientContextProvider
  {
  public:
    grpc::ClientContext& get_client_context();
  private:
    grpc::ClientContext client_context_;
  };
}

#endif // GRPCCLIENTCONTEXTPROVIDER_H
