# GrpcInDLLsIssues

This repository is supposed to document issues that are observed when trying to use gRPC (built as static libraries) in a project composed of DLLs under Windows.

Currently, there is only a single example, where one DLL defines a class, that creates a grpc::ClientContext, and the other DLL creates an instance of that class and passes the ClientContext to a gRPC call, which results in an access violation later at the destruction of the ClientContext.

## Build
The project as well as gRCP were built with Visual Studio 2019.

To build gRPC, these were the steps that were used
### Clone gRPC repo including submodules
```
git clone https://github.com/grpc/grpc
cd grpc
git submodule update --init
```

### Build gRPC using cmake with Visual Studio 2019 and limited to the required components
The following will install gRPC in the folder `c:\temp\grpc` (last parameter in the long config command) which is also used in the cmake file of this repo. Feel free to change it at both locations. 
```
md .build
cd .build
cmake .. -G "Visual Studio 16 2019" -DgRPC_BUILD_GRPC_PYTHON_PLUGIN=OFF -DgRPC_BUILD_GRPC_PHP_PLUGIN=OFF -DgRPC_BUILD_GRPC_RUBY_PLUGIN=OFF -DgRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN=OFF -DgRPC_BUILD_GRPC_NODE_PLUGIN=OFF -DgRPC_BUILD_GRPC_CSHARP_PLUGIN=OFF -DgRPC_BUILD_CSHARP_EXT=OFF -DABSL_ENABLE_INSTALL=ON -DCMAKE_INSTALL_PREFIX="c:/temp/grpc"
cmake --build . --config Release
cmake --install .
```

### Build this repo and run the example
* Open the folder in Visual Studio 2019
* Generate the cmake cache
* Build
* Run the target _TestProgram.exe (Install)_
