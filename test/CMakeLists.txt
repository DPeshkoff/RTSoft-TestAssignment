include_directories(../include/)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(TEST_SOURCES 
    ../src/field.cpp
    )	

set(TESTS 
    ./src/test_init.cpp
    ./src/test_field.cpp
    )	


add_executable(testing ${TESTS} ${TEST_SOURCES})

target_link_libraries(testing ${GTEST_LIBRARIES} pthread)

set_target_properties(testing PROPERTIES COMPILE_FLAGS "-Wall -Werror -Wpedantic -Wextra -Os")