
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

project (DLL1 LANGUAGES CXX)
include(GenerateExportHeader)

set(PROTO_FILES
	example_service.proto 
)

set(SOURCES
	GrpcClient1.cpp
)
set(HEADERS
	GrpcClient1.h
 )

add_library(DLL1 SHARED ${PROTO_FILES} ${SOURCES} ${HEADERS})
generate_export_header(DLL1)

target_include_directories(DLL1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(DLL1 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(DLL1
    PUBLIC
		DLL2
	)

target_link_libraries(DLL1
	PRIVATE        
		protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET DLL1 LANGUAGE cpp)
protobuf_generate(TARGET DLL1 LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")

install(TARGETS DLL1 DESTINATION "bin/AccessViolation")
