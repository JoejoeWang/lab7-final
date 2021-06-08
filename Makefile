#CXX=clang++
CXX=g++

#CXXFLAGS= -g -std=c++14 
CXXFLAGS= -g -std=c++11 

BINARIES=a.out

all: ${BINARIES}

a.out: TestmainPartial.o ellipse.o polygon.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o 