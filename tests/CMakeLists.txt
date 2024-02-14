include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE SRC_FILES ${SRC_DIR}/*.cpp)
list(FILTER SRC_FILES EXCLUDE REGEX "${SRC_DIR}/main.cpp")

file(GLOB_RECURSE TEST_UTILS_SRC test_utils/*.cpp)

# --- hello_test ---

add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

# --- hello_test ---
# --- contour_extraction_tests ---

add_executable(
  contour_extraction_tests
  ${SRC_FILES}
  ${TEST_UTILS_SRC}
  contour_extraction_tests.cpp
)

target_include_directories(contour_extraction_tests PRIVATE ${SRC_DIR})
target_link_libraries(
  contour_extraction_tests
  GTest::gtest_main
  ${OpenCV_LIBS}
)

# --- contour_extraction_tests ---

include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(contour_extraction_tests)
