# CMake build script for C++ Basic Project Setup Example
cmake_minimum_required(VERSION 3.0.2)

project(MykissFilter)

set(EXECUTABLE_NAME "filter")

# include sources
set(SOURCES
	src/main.cxx
)

# source for unit test
SET(TEST_SOURCES
	test/mocks.cpp
  test/temperature_monitor_test.cpp
)

# Enable more warnings
set(CXX_EXTRA_FLAGS "-Wall -Wextra -pedantic -Woverloaded-virtual \
                    -Wmissing-declarations -Wnon-virtual-dtor -fpermissive ")

# Debug by default has '-g'
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CXX_EXTRA_FLAGS} -O0")
# Release by default has '-O3 -DNDEBUG'
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CXX_EXTRA_FLAGS}")
# Make Debug default build type
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")

# CYGWIN requirements: we need gnu++14 instead of c++14
if(CYGWIN OR MINGW)
  add_compile_options( -std=gnu++14 )
  option(gtest_disable_pthreads "Disable uses of pthreads in gtest." ON)
else()
  add_compile_options( -std=c++14 )
endif()

# Google Dependencies require pthread if gnu g++
if(CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-pthread)
endif()

# Redirect build output
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Include necessary directories

# Treat warnings as errors in our own code
# add_compile_options(-Werror)
add_compile_options(-Wno-error)

add_subdirectory(
	../3rdparty/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest EXCLUDE_FROM_ALL
)

include_directories(${gmock_SOURCE_DIR}/include)

include_directories(../3rdparty)

include_directories(src)

# Build Executable
add_executable(${EXECUTABLE_NAME}
	${SOURCES}
	# ${HEADERS}
)

# set_directory_properties(
#   INCLUDE_DIRECTORIES 3rdparty
#   PROPERTIES COMPILE_FLAGS -Wno-err
# )

# Build unit test:
SET(TESTS_EXEC "unit_tests")

# Unit tests for our business_logic library
add_executable(${TESTS_EXEC} EXCLUDE_FROM_ALL
	${TEST_SOURCES}
)

# Standard linking to gtest & gmock stuff and our own library
target_link_libraries(${TESTS_EXEC} business_logic gtest gmock gmock_main)

# Target for code analysis
# add_custom_target(lint ${CMAKE_CURRENT_SOURCE_DIR}/scripts/verify_cpp_code.sh)

# Target for running unit tests and code style analysis
add_custom_target(tests
  COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TESTS_EXEC}
  DEPENDS lint ${TESTS_EXEC}
)
