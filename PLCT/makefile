CC:=g++
SRCS := $(wildcard *.cpp)
EXES := $(SRCS:.cpp=)

all: clean $(EXES)

$(EXES): % : %.cpp
	$(CC) $< -o $@
test:
	./test.sh

clean:
	rm mixplus cnt check
.PHONY: clean all test
