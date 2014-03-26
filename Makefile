SOURCES=${wildcard src/*.cpp wildcard src/figures/*.cpp wildcard src/materials/*.cpp wildcard src/cameras/*.cpp}
OBJECTS=$(SOURCES:src/%.cpp=obj/%.o)
CFLAGS=-c -Wall -std=c++11 -Iinclude `libpng-config --cflags` -g3
LDFLAGS=`libpng-config --ldflags` -g3 -lrt
EXECUTABLE=bin/raytracer

all: prepare $(EXECUTABLE)

prepare:
	@mkdir -p obj
	@mkdir -p obj/materials
	@mkdir -p obj/figures
	@mkdir -p obj/cameras

clean:
	rm -f $(EXECUTABLE)
	find ./ -name \*.o  -delete

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJECTS): obj/%.o : src/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
