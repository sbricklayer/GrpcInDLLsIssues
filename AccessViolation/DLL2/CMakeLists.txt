project (DLL2 LANGUAGES CXX)
include(GenerateExportHeader)

set(SOURCES
    GrpcClientContextProvider.cpp
 )
set(HEADERS
    GrpcClientContextProvider.h
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})
add_library(DLL2 SHARED ${SOURCES} ${HEADERS})
generate_export_header(DLL2)

target_include_directories(DLL2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(DLL2 PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(DLL2
    PRIVATE
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

install(TARGETS DLL2 DESTINATION "bin/AccessViolation")
