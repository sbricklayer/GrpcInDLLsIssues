project (DeadlockExample LANGUAGES CXX)

set(SOURCES
  main.cpp
)

set(HEADERS

)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})
add_executable(DeadlockExample ${SOURCES} ${HEADERS})

target_link_libraries(DeadlockExample
    PUBLIC
        DLL3
)

install(TARGETS DeadlockExample DESTINATION "bin/Deadlock")
