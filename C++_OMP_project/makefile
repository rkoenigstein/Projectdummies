#define variables for compiler and linker to use
CC = g++
LINKER = g++

#compiler and linker flags
# -Wall: all warnings on, -g: generate debug information
DEBUG = -g
OPTIMIZATION = -O2
CFLAGS = -std=c++11 -Wall $(DEBUG) $(OPTIMIZATION) -fopenmp
LDFLAGS = -Wall -fopenmp

#source files
SRC = $(wildcard *.cpp)
INCLUDES = $(wildcard *.h)

#object files
OBJS = $(SRC:%.cpp=%.o)

#executable
EXECUTABLE = helloworld

#clean up
RM = rm -f

$(EXECUTABLE): $(OBJS)
	$(LINKER) $(OBJS) $(LDFLAGS) -o $@
	@echo "Linking done"

$(OBJS): %.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Complied "$<" successfully"

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(OBJS)
	@echo "Cleanup done"
