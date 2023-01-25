cmake_minimum_required(VERSION 3.15)
project(clion)

set(CMAKE_CXX_STANDARD 20)
add_executable(a_specialize_01_pair a_specialize_01_pair.cpp)
add_executable(a_specialize_02_type a_specialize_02_type.cpp)
add_executable(a_specialize_03_vector a_specialize_03_vector.cpp)
add_executable(a_specialize_04_ispointer a_specialize_04_ispointer.cpp)
add_executable(a_specialize_05_metaprogramming a_specialize_05_metaprogramming.cpp)
add_executable(a_specialize_06_typename a_specialize_06_typename.cpp)
add_executable(b_smartptr_01_sharedptr b_smartptr_01_sharedptr.cpp)
add_executable(b_smartptr_02_weakptr b_smartptr_02_weakptr.cpp)

add_executable(sol_eastbourne sol_eastbourne.cpp)
add_executable(sol_openshaw sol_openshaw.cpp)
add_executable(sol_wintervale sol_wintervale.cpp)
add_executable(sol_banrockburn sol_banrockburn.cpp)

add_executable(work_g_inverse work_g_inverse.cpp)
