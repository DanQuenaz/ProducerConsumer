#################################################
# Projeto Asteroids
#################################################

project(ProdutorConsumidor)
cmake_minimum_required(VERSION 2.8)

################################################################################
# COMPILER
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


################################################################################
# CMake variables
set(${PROJECT_NAME}_ROOT_DIR         ${CMAKE_SOURCE_DIR})

SET(CMAKE_MODULE_PATH                ${${PROJECT_NAME}_ROOT_DIR}/cmake)
SET(CMAKE_CURRENT_BINARY_DIR            ${${PROJECT_NAME}_ROOT_DIR}/build)
SET(CMAKE_INSTALL_PREFIX             ${${PROJECT_NAME}_ROOT_DIR}/bin)

################################################################################
# OpenGL




set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
include_directories(${Threads_INCLUDE_DIRS})
link_directories(${Threads_LIBRARY_DIRS})
add_definitions(${Threads_DEFINITIONS})


#add_executable(test test.cpp)
#target_link_libraries(test Threads::Threads)


################################################################################
# FILES
set(HDRS
    
    #Flea3Camera.h
    #Flea3CameraMono.h
    #Flea3CameraStereo.h
)


set(SRCS
    
    src/main.cpp
    #Flea3CameraMono.cpp
    #Flea3CameraStereo.cpp
)

################################################################################
# EXEC
add_executable(${PROJECT_NAME} ${HDRS} ${SRCS})




# LIBS
set(LIBS
    ${Threads_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT})

# LINK
target_link_libraries(${PROJECT_NAME} ${LIBS})
#target_link_libraries( test ${CMAKE_THREAD_LIBS_INIT} )

#Install



















