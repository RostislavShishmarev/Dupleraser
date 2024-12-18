all: eraser

eraser:
	gcc main.c list/list.c list/io.c -o eraser.out -Wall -Wextra

debug:
	gcc -g main.c list/list.c list/io.c -o eraser.out -Wall -Wextra

