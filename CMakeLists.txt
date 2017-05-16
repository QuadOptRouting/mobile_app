cmake_minimum_required(VERSION 3.7)
project(mobile_app)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        client.cpp)

add_executable(mobile_app ${SOURCE_FILES})

set(BOOST_COMPONENTS system thread filesystem date_time)
# Late 2017 TODO: remove the following checks and always use std::regex
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
        set(BOOST_COMPONENTS ${BOOST_COMPONENTS} regex)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_BOOST_REGEX -lpthread -lboost_system -lrt")
    endif()
endif()
find_package(Boost 1.58.0 COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIR})



target_link_libraries(mobile_app ${Boost_LIBRARIES} -lpthread )
