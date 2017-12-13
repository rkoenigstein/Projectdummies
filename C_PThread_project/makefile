#define variables for compiler and linker to use
CC = gcc
LINKER = gcc

#compiler and linker flags
# -Wall: all warnings on, -g: generate debug information
DEBUG = -g
OPTIMIZATION = -O2
CFLAGS = -std=c99 -Wall $(DEBUG) $(OPTIMIZATION) -pthread
LDFLAGS = -Wall -pthread

#source files
SRC = $(wildcard *.c)
INCLUDES = $(wildcard *.h)

#object files
OBJS = $(SRC:%.c=%.o)

#executable
EXECUTABLE = helloworld

#clean up
RM = rm -f

$(EXECUTABLE): $(OBJS)
	$(LINKER) $(OBJS) $(LDFLAGS) -o $@
	@echo "Linking done"

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Complied "$<" successfully"

.PHONY: clean
clean:
	$(RM) $(EXECUTABLE) $(OBJS)
	@echo "Cleanup done"
