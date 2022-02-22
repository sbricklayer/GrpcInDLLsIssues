#include "GrpcClientContextProvider.h"

namespace DLL2 {
  grpc::ClientContext& ClientContextProvider::get_client_context()
  {
    return client_context_;
  }
}