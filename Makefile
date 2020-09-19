CXX = g++
CPPFLAGS = -DSHELL=BASH --std=c++11 -Wall -Wextra -Werror  -I. -Ilib -Isegments -ggdb
LDFLAGS = -lgit2
DEPS = $(wildcard lib/*.h) $(wildcard lib/*.cpp) $(wildcard segments/*.h) $(wildcard segments/*.cpp)
OBJ  = main.o $(patsubst %.cpp,%.o,$(wildcard lib/*.cpp)) $(patsubst %.cpp,%.o,$(wildcard segments/*.cpp))


.PHONY: all
all: powerline-shell-cpp

%.o: %.c $(DEPS) main.c
	$(CXX) -c -o $@ $< $(CXXFLAGS)

powerline-shell-cpp: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)


.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: distclean
distclean: clean
	rm -f powerline-shell-cpp
