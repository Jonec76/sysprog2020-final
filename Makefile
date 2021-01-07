main:1483.c
	gcc -o main 1483.c -Wall -Wextra -Woverflow -fsanitize=address
.PHONY: clean
clear:
	rm main