cmake_minimum_required( VERSION 3.0 )
project( socialnetwork )
include_directories ( ./include ./src)
add_executable( output ./src/main.cpp ./src/maindriver.cpp ./src/post.cpp ./src/user.cpp ./src/utils.cpp )