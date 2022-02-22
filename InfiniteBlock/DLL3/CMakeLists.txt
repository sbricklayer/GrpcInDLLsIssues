
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

project (DLL3 LANGUAGES CXX)
include(GenerateExportHeader)

set(PROTO_FILES
	example_service2.proto 
)

set(SOURCES
	GrpcClient2.cpp
)
set(HEADERS
	GrpcClient2.h
 )

add_library(DLL3 SHARED ${PROTO_FILES} ${SOURCES} ${HEADERS})
generate_export_header(DLL3)

target_include_directories(DLL3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(DLL3 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(DLL3
    PUBLIC
		DLL2
	)

target_link_libraries(DLL3
	PRIVATE        
		protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET DLL3 LANGUAGE cpp)
protobuf_generate(TARGET DLL3 LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")

install(TARGETS DLL3 DESTINATION "bin/InfiniteBlock")
