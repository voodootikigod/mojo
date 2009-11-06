
CC = gcc
LEG = leg
NAME = mojo
BIN = bin/$(NAME)
DEST = /usr/bin
CFILES = src/*.c
CFLAGS = -std=c99

all: parser build
	
build:
	@$(CC) $(CFLAGS) $(CFILES) -o $(BIN)
	
parser:
	@$(LEG) < src/parser.leg > src/parser.c
	
inspect: all
	@./$(BIN) < examples/template.js.html
	
install: $(BIN)
	cp $(BIN) $(DEST)/$(NAME) 
	
uninstall: $(DEST)/$(NAME)
	rm $(DEST)/$(NAME)
	