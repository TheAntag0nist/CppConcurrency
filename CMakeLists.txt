# Set minimum Version
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Set CXX Standard
set(CMAKE_CXX_STANDARD 17)

# Set Project
set(PROJECT_NAME CppConcurrency)
project (${PROJECT_NAME} VERSION 0.0.0 DESCRIPTION "CppConcurrency - 
		it's a repository dedicated to exploring concurrency in C++.")

# Compile Flags
add_compile_options(-Wall)

# Include Directories
include_directories(./CppConcurrency/inc)

# Examples
set(EXAMPLES_SOURCE_FILES
	./CppConcurrency/src/examples/BaseExample.cpp
	./CppConcurrency/src/examples/CallExample.cpp
)

# Source Files
set(SOURCE_FILES
	./CppConcurrency/src/main.cpp
	./CppConcurrency/src/Example.cpp
	./CppConcurrency/src/ExamplesManager.cpp

	${EXAMPLES_SOURCE_FILES}
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})