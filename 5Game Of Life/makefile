CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = GameOfLife.o

SRCS = GameOfLife.cpp

game:${OBJS}
${CXX} ${LDFLAGS} ${OBJS} -o game
${OBJS}: ${SRCS}
${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
rm -f *.o a.out