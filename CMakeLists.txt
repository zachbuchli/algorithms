cmake_minimum_required(VERSION 3.16)
project(algs C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g3 -Og -Wall -Wextra -Werror -pedantic -DHAVE_INLINE -D_FORTIFY_SOURCE=2 -D_GNU_SOURCE")

add_executable(search search.c)
target_link_libraries(search PRIVATE m)

add_executable(queue queue.c)
add_executable(stack stack.c)
add_executable(string string.c)
add_executable(qsort qsort.c)
