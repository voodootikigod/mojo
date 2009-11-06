
CC = gcc
BIN = bin/lib
CFILES = src/*.c
CFLAGS = -std=c99

all: parser build
	
build:
	@$(CC) $(CFLAGS) $(CFILES) -o $(BIN)
	
parser:
	@leg < src/parser.leg > src/parser.c
	
test: all
	@./$(BIN) < examples/template.js.html