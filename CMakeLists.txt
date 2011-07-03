cmake_minimum_required(VERSION 2.8)
project(cuboidengine)

include_directories(/usr/local/include/agar)
include_directories(/usr/local/include/bullet)
include_directories(/usr/include/SDL)
include_directories(${cuboidengine_SOURCE_DIR})

add_subdirectory(shared)
add_subdirectory(server)
add_subdirectory(client)

add_executable(testclient test_client.cpp)
add_executable(testserver test_server.cpp)

target_link_libraries(testclient cuboid_shared_lib cuboid_client_lib)
target_link_libraries(testserver cuboid_shared_lib cuboid_server_lib)