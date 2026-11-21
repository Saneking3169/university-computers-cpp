CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra

app: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

clean:
	rm -f app

.PHONY: clean
