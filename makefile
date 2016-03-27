CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=TowerDemo.cpp Node.h LinkedList.h LStack.h TowerHanoi.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
