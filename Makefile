CC = gcc

OBJ = src/main.c src/utils/*.c src/lexer/*.c

OUT = opti

build:
	${CC} ${OBJ} -o ${OUT}