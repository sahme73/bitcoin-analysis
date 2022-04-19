####################################################################################################

#Compiler Vars: (Contact mentor for optimal compiler tags!)

CXX=clang++
CXX_FLAGS=-std=c++17 -g -O0 -Wall -Wextra -Werror

CC = g++
CFLAGS = -Wall -g

####################################################################################################

#Misc. Vars:

FILES = src/main.cpp src/Node.cpp src/Graph.cpp src/Edge.cpp
TEST_FILES = src/Node.cpp src/Graph.cpp src/Edge.cpp tests/tests.cpp

####################################################################################################

exec: bin/exec
tests: bin/tests

bin/exec: ${FILES}
	${CXX} ${CXX_FLAGS} $^ -o bin/exec

bin/tests: ${TEST_FILES}
	${CXX} ${CXX_FLAGS} $^ -o bin/tests

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -rf bin/*

####################################################################################################