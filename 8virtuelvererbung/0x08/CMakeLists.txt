cmake_minimum_required(VERSION 3.15)
project(clion)

set(CMAKE_CXX_STANDARD 20)
add_executable(a_polymorphie_01_novirtual a_polymorphie_01_novirtual.cpp)
add_executable(a_polymorphie_02_virtual a_polymorphie_02_virtual.cpp)
add_executable(a_polymorphie_03_ab a_polymorphie_03_ab.cpp)
add_executable(b_abstract_01_report b_abstract_01_report.cpp)
add_executable(b_abstract_02_clone b_abstract_02_clone.cpp)
add_executable(c_multiple_01_simple c_multiple_01_simple.cpp)
add_executable(c_multiple_02_diamond c_multiple_02_diamond.cpp)

add_executable(sol_moorerock sol_moorerock.cpp)
add_executable(sol_petersmines sol_petersmines.cpp)
add_executable(sol_unionbeach_v1 sol_unionbeach_v1.cpp)
add_executable(sol_unionbeach_v2 sol_unionbeach_v2.cpp)
add_executable(sol_unionbeach_v3 sol_unionbeach_v3.cpp)

add_executable(work_windows work_windows.cpp)
