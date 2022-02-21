# GrpcInDLLsIssues

This repository is supposed to document issues that are observed when trying to use gRPC (built as static libraries) in a project composed of DLLs.

Currently, there is only a single example, where one DLL defines a class, that creates a grpc::ClientContext, and the other DLL creates an instance of that class and passes the ClientContext to a gRPC call, which results in an access violation later at the destruction of the ClientContext.
