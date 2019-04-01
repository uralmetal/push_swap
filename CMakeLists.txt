cmake_minimum_required(VERSION 3.13)
project(push_swap C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

include_directories(.)
include_directories(./get_next_line)
include_directories(./libft)
include_directories(./push_swap_lib)
include_directories(./push_swap_sort)
include_directories(./stack)

file(GLOB libft
        "libft/*.h"
        "libft/*.c"
        )

file(GLOB stack
        "stack/*.h"
        "stack/*.c"
        )

file(GLOB push_swap_lib
        "push_swap_lib/*.c"
        "push_swap_lib/*.h"
        )

file(GLOB get_next_line
        "get_next_line/*.c"
        "get_next_line/*.h"
        )

file(GLOB push_swap_sort
        "push_swap_sort/*.c"
        "push_swap_sort/*.h"
        )

add_executable(checker ${libft} ${stack} ${push_swap_lib} ${get_next_line}
        checker.c )
add_executable(push_swap ${libft} ${stack} ${push_swap_lib} ${push_swap_sort}
        push_swap.c)
