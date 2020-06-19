cmake_minimum_required(VERSION 3.17)

# set the project name
project(test_boost_interprocesses)
add_compile_options(-std=c++14)
add_link_options(-lrt)

## find and include required dependencies
find_package(Boost REQUIRED)
list(APPEND list_include_dirs ${BOOST_INCLUDE_DIR})

# add the executable
add_executable(sender sender.cpp)
target_link_libraries(sender PRIVATE -pthread -lrt)
add_executable(receiver receiver.cpp)
target_link_libraries(receiver PRIVATE -pthread -lrt)
add_executable(sender_reset_mq sender_reset_mq.cpp)
target_link_libraries(sender_reset_mq PRIVATE -pthread -lrt)