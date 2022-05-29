CC = g++
SOURCES = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCES))
TARGET = ass4
LIB = libass4
CXXFLAGS = -c -Wall -O3

$(TARGET) : $(OBJ)
	@mkdir -p lib
	$(CC) -shared -fPIC -o ./lib/$(LIB).so $(OBJ)
	@rm $(OBJ)
	$(CC) -o $(TARGET) -L./lib $(SOURCES) -lass4

%.o : %.cpp
	$(CC) -fPIC $^ $(CXXFLAGS) -o $@

.PHONY : clean
clean:
	rm -rf lib
	rm -rf ass4
