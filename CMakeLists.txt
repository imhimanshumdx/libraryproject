# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(Library_Management)

# Add the main executable and list your source files
add_executable(Library_Management
    "Library_Management.cpp"  # Replace with your main source file
)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up Catch2 for testing
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.7  # Replace with the desired Catch2 version
)
FetchContent_MakeAvailable(Catch2)

# Add the test executable and list your test source files
add_executable(tests
    "test.cpp"  # Replace with your test file
    # Add other test source files as needed
)

# Include the directory containing catch.hpp
target_include_directories(tests PRIVATE "E:/My Data/orders/fiv/7/library_management")

# Link Catch2 to your test executable
target_link_libraries(tests PRIVATE Catch2::Catch2)

# Enable testing and register your test executable
include(CTest)
include(Catch)
catch_discover_tests(tests)
