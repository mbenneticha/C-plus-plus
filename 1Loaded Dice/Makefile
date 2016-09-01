
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors  
CXXFLAGS += -g 
LDFLAGS = -lboost_date_time

OBJS = LoadedDie.o Die.o main.o

SRCS = LoadedDie.cpp Die.cpp main.cpp

HEADERS = LoadedDie.hpp Die.hpp

dice:${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o dice
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
    rm -f *.o a.out