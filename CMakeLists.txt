cmake_minimum_required(VERSION 3.17)
project(project4)

set(CMAKE_CXX_STANDARD 20)

add_executable(project4 proj4.cpp AgItem.cpp Animal.cpp Vegetable.cpp Tree.cpp Fruit.cpp Farm.cpp AgItem.h Animal.h Farm.h Fruit.h Tree.h Vegetable.h)