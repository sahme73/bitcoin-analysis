####################################################################################################

#Compiler Vars: (Contact mentor for optimal compiler tags!)

CXX=clang++
CXX_FLAGS=-std=c++17 -g -O0 -Wall -Wextra -Werror -Iincludes/buildings -Iincludes/factories -Iincludes/districts

CC = g++
CFLAGS = -Wall -g

####################################################################################################

#Misc. Vars:

FILES = src/main.cc src/Node.cpp src/Graph.cpp

####################################################################################################

exec: bin/exec
#tests: bin/tests

bin/exec: ${FILES}
	${CXX} ${CXX_FLAGS} $^ -o bin/exec

#bin/tests: src/buildings/* src/districts/* src/factories/* tests/test.cc
#	${CXX} ${CXX_FLAGS} $^ -o bin/tests

.DEFAULT_GOAL := exec
.PHONY: clean exec #tests

clean:
	rm -rf bin/*

####################################################################################################