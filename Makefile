CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC = ConsoleApplication2.cpp
TARGET = gil_test3

all: $(TARGET)

$(TARGET): $(SRC)
		$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
	rm -f *.o
