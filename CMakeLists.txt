cmake_minimum_required(VERSION 3.26)
project(rentCar)

set(CMAKE_CXX_STANDARD 17)

add_executable(rentCar main.cpp
        Car.cpp
        Car.h
        Customer.cpp
        Customer.h
        Rent.cpp
        Rent.h
        Vehicle.cpp
        Vehicle.h)
