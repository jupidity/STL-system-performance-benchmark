#CMake for basic project
#Sean Cassero

# tell CMake to output all possible errors and input basic
# debugging flags during compilation

set(CMAKE_CXX_FLAGS "-Wall -g")

# glob together all files in the current directory that match
# the given extension and turn them into a SRCS file for compilation

file(GLOB SRCS *.cpp *.c *.h)

# define the target executable and the source file needed to compile it

add_executable(message ${SRCS} )
