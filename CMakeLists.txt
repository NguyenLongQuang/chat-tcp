cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

project(tcp_chat)

include_directories(${PROJECT_SOURCE_DIR}/inc)

file(GLOB SHARED_SOURCE ${PROJECT_SOURCE_DIR}/src/*.c)
set(SERVER_DIR ${PROJECT_SOURCE_DIR}/server)
set(CLIENT_DIR ${PROJECT_SOURCE_DIR}/client)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DGROUP_CHAT")

set(SERVER_SOURCE ${SHARED_SOURCE} ${SERVER_DIR}/main.c)

set(CLIENT_SOURCE ${SHARED_SOURCE} ${CLIENT_DIR}/main.c)

add_executable(server ${SERVER_SOURCE})
add_executable(client ${CLIENT_SOURCE})

target_link_libraries(server pthread)
target_link_libraries(client pthread)

set_target_properties(server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

set_target_properties(client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

