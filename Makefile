CC = gcc

OBJ = src/main.c src/utils/*.c src/lexer/*.c

OUT = opti

build:
	${CC} -g ${OBJ} -o ${OUT}