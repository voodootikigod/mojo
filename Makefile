
CC = gcc
LEG = leg
BIN = mojo
DEST = /usr/bin
CFILES = src/*.c
CFLAGS = -std=c99

all: parser build
	
build:
	@$(CC) $(CFLAGS) $(CFILES) -o bin/$(BIN)
	
parser:
	@$(LEG) < src/parser.leg > src/parser.c
	
inspect: all
	@./bin/$(BIN) < examples/template.js.html
	
install: bin/$(BIN)
	cp bin/$(BIN) $(DEST)/$(BIN) 
	
uninstall: $(DEST)/$(BIN)
	rm $(DEST)/$(BIN)
	