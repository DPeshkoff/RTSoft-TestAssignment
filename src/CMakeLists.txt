add_executable(hw
            main.cpp 
            field.cpp
            ../include/field.h
            )

include_directories(../include)

# sometime in the future maybe -fmodules-ts
set_target_properties(hw PROPERTIES COMPILE_FLAGS "-Wall -Werror -Wpedantic -Wextra -pedantic-errors -Wold-style-cast -Os -fcoroutines -std=c++20 -fno-exceptions -pthread")

target_link_libraries(hw pthread)