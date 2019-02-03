cmake_minimum_required(VERSION 3.13)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

file(GLOB libft
        "libft/*.h"
        "libft/*.c"
        )

add_executable(push_swap main.c ${libft} stack/init_stack.c stack/stack.h
        stack/stack_put.c stack/stack_resize.c stack/stack_pull.c stack/stack_print.c stack/stack_rotate.c stack/stack_rev_rotate.c)
