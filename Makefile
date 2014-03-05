SOURCES=${wildcard src/*.cpp wildcard src/figures/*.cpp}
OBJECTS=$(SOURCES:src/%.cpp=obj/%.o)
CFLAGS=-c -Wall -std=c++11 -Iinclude
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE=bin/raytracer

all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
	find ./ -name \*.o  -delete

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJECTS): obj/%.o : src/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@