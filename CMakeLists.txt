cmake_minimum_required(VERSION 3.16)
project(algs C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g3 -Og -Wall -Wextra -pedantic -DHAVE_INLINE -D_FORTIFY_SOURCE=2 -D_GNU_SOURCE")

add_executable(main main.c)
target_link_libraries(main PRIVATE m)

add_executable(queue queue.c)
add_executable(stack stack.c)
