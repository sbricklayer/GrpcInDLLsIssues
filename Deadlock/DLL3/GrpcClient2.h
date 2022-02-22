#ifndef GRPCCLIENT1_H
#define GRPCCLIENT1_H

#include <memory>
#include "dll3_export.h"

class DLL3_EXPORT ExampleService2Accessor
{
public:
  ExampleService2Accessor();
  ~ExampleService2Accessor();
  static ExampleService2Accessor& getInstance();
  //void callExampleService(); //we could make calls to the gRPC service, but they are not required to demonstrate the deadlock on destruction

private:
  class Impl;
  std::unique_ptr<Impl> pimpl_; //use PIMPL to uncouple consumer from all gRPC dependencies
};

#endif // GRPCCLIENT1_H
