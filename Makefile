CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = src/main.c src/app.c src/input.c src/password.c src/saltgenerator.c src/hash.c
LIBS = -lcrypto
OUT = saltforge

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
