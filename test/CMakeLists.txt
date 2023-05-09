enable_testing()
include(GoogleTest)

add_executable(object_test object_test.cpp)
target_link_libraries(object_test bf GTest::gtest_main)
gtest_discover_tests(object_test)

add_executable(bit_array_test bit_array_test.cpp)
target_link_libraries(bit_array_test bf GTest::gtest_main)
gtest_discover_tests(bit_array_test)

add_executable(counter_array_test counter_array_test.cpp)
target_link_libraries(counter_array_test bf GTest::gtest_main)
gtest_discover_tests(counter_array_test)