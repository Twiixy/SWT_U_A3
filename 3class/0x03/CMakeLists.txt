cmake_minimum_required(VERSION 3.15)
project(clion)

set(CMAKE_CXX_STANDARD 20)

add_executable(a_ctor_dtor_throw a_ctor_dtor_throw.cpp)
add_executable(a_ctor_dtor a_ctor_dtor.cpp)
add_executable(b_getter_setter b_getter_setter.cpp)
add_executable(c_const_getter c_const_getter.cpp)
add_executable(d_copyctor d_copyctor.cpp)
add_executable(e_class_address e_class_address.cpp)
add_executable(f_class_address_best f_class_address_best.cpp)

add_executable(sol_luckyrock sol_luckyrock.cpp)
add_executable(sol_meadowriver sol_meadowriver.cpp)
add_executable(sol_ravencastle sol_ravencastle.cpp)
add_executable(sol_stoneridge sol_stoneridge.cpp)

add_executable(work_class_car work_class_car.cpp)
add_executable(work_class_ctor work_class_ctor.cpp)
