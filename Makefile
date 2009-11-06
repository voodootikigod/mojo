
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
	@./$(BIN) < examples/template.html
	
test: all
	@./$(BIN) < spec/fixtures/article.html > spec/fixtures/article.html.js
	@./$(BIN) < spec/fixtures/users.html > spec/fixtures/users.html.js
	@./$(BIN) < spec/fixtures/profile.html > spec/fixtures/profile.html.js
	@./$(BIN) < spec/fixtures/comments.html > spec/fixtures/comments.html.js
	@./$(BIN) < spec/fixtures/page.html > spec/fixtures/page.html.js
	@./$(BIN) < spec/fixtures/welcome.html > spec/fixtures/welcome.html.js
	@jspec run --rhino
	
install: $(BIN)
	cp $(BIN) $(DEST)/$(NAME) 
	
uninstall: $(DEST)/$(NAME)
	rm $(DEST)/$(NAME)
	