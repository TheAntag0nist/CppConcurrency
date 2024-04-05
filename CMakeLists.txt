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
	./CppConcurrency/src/examples/JoinExample.cpp
	./CppConcurrency/src/examples/ThreadGuardExample.cpp
	./CppConcurrency/src/examples/DetachExample.cpp
	./CppConcurrency/src/examples/MoveExample.cpp
	./CppConcurrency/src/examples/FullJoinClassExample.cpp
	./CppConcurrency/src/examples/AccumulateExample.cpp
	./CppConcurrency/src/examples/MutexExample.cpp
	./CppConcurrency/src/examples/SafeStackExample.cpp
	./CppConcurrency/src/examples/SwapExample.cpp
	./CppConcurrency/src/examples/HierarchicalMutexExample.cpp
	./CppConcurrency/src/examples/UniqueLockMoveExample.cpp
	./CppConcurrency/src/examples/UniqueLockUnlockExample.cpp
	./CppConcurrency/src/examples/CallOnceExample.cpp
	./CppConcurrency/src/examples/DnsCacheExample.cpp
	./CppConcurrency/src/examples/ConditionalVariableExample.cpp
	./CppConcurrency/src/examples/ThreadSafeQueueExample.cpp
)

# Source Files
set(SOURCE_FILES
	./CppConcurrency/src/main.cpp
	./CppConcurrency/src/core/App.cpp
	./CppConcurrency/src/core/Func.cpp
	./CppConcurrency/src/core/Example.cpp
	./CppConcurrency/src/core/Command.cpp
	./CppConcurrency/src/core/AppCommands.cpp
	./CppConcurrency/src/core/ExamplesManager.cpp

	${EXAMPLES_SOURCE_FILES}
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)