CC = g++
SOURCES = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCES))
TARGET = main
LIB = libpair
CXXFLAGS = -c -Wall -O3

$(TARGET) : $(OBJ)
	@mkdir -p lib
	$(CC) -shared -fPIC -o ./lib/$(LIB).so $(OBJ)
	@rm $(OBJ)
	$(CC) -o $(TARGET) -L./lib $(SOURCES) -lpair

%.o : %.cpp
	$(CC) -fPIC $^ $(CXXFLAGS) -o $@

.PHONY : clean
clean:
	rm -rf lib
	rm -rf main
