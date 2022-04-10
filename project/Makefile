CXX=clang++
CXX_FLAGS=-std=c++17 -g -O0 -Wall -Wextra -Werror -Iincludes/buildings -Iincludes/factories -Iincludes/districts

CC = g++
CFLAGS = -Wall -g

exec: bin/exec
#tests: bin/tests

bin/exec: src/main.cc src/Node.cpp
	${CC} ${CFLAGS} $^ -o bin/exec

#bin/tests: src/buildings/* src/districts/* src/factories/* tests/test.cc
#	${CXX} ${CXX_FLAGS} $^ -o bin/tests

.DEFAULT_GOAL := exec
.PHONY: clean exec #tests

clean:
	rm -rf bin/*