cmake_minimum_required(VERSION 3.15)
project(clion)

set(CMAKE_CXX_STANDARD 20)
add_executable(a_asm_01_local_vars a_asm_01_local_vars)
add_executable(a_asm_02_local_addr a_asm_02_local_addr)
add_executable(a_asm_03_call_by a_asm_03_call_by)
add_executable(b_pointer_01_memory_layout b_pointer_01_memory_layout)
add_executable(b_pointer_02_math b_pointer_02_math)
add_executable(b_pointer_03_array b_pointer_03_array)
add_executable(b_pointer_04_multiple_params b_pointer_04_multiple_params)
add_executable(b_pointer_05_swap b_pointer_05_swap)
add_executable(b_pointer_06_addon b_pointer_06_addon)
add_executable(b_pointer_07_illegal b_pointer_07_illegal)

add_executable(work_ptr_endlist work_ptr_endlist.cpp)

add_executable(sol_copperview sol_copperview)
add_executable(sol_kengate sol_kengate)
add_executable(sol_mcallenspring sol_mcallenspring)

