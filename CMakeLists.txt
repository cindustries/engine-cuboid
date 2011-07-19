cmake_minimum_required(VERSION 2.8)
project(engine-cuboid)

#determine what to build (client/server/both)
#option( DO_BUILD_SERVER "Build the server?" YES )
#if(NOT ${DO_BUILD_SERVER})
    #message(STATUS "Building client only.")
    #set( DO_BUILD_CLIENT YES )  
#else()
    #option( DO_BUILD_CLIENT "Build the client aswell?" NO )
#endif()

#set environment accordingly
#if(${DO_BUILD_CLIENT})
    include_directories(/usr/include/SDL)
    include_directories(/usr/local/include/agar)
    find_package(SDL)
    find_package(OpenGL)
#endif()

#if(${DO_BUILD_SERVER})
    include_directories(/usr/local/include/bullet)
#endif()
include_directories(${cuboidengine_SOURCE_DIR})


#build stuff!
add_library(engine-cuboid-shared STATIC ConVarStorage.cpp ConCmdManager.cpp)
target_link_libraries(engine-cuboid-shared enet)

#if(${DO_BUILD_CLIENT})
    add_library(engine-cuboid-client STATIC CuboidClient.cpp )
    target_link_libraries(engine-cuboid-client GL agar ${SDL_LIBRARIES})
    
    add_executable(testclient test_client.cpp)
    target_link_libraries(testclient engine-cuboid-shared engine-cuboid-client)
#endif()

#if(${DO_BUILD_SERVER})
    add_library(engine-cuboid-server STATIC NetworkController.cpp PhysWorld.cpp CuboidServer.cpp)
    target_link_libraries(engine-cuboid-server BulletDynamics BulletCollision LinearMath)
    
    add_executable(testserver test_server.cpp)
    target_link_libraries(testserver engine-cuboid-shared engine-cuboid-server)
#endif()
