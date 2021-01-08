main:51.cpp
	g++ -o main 51.cpp -Wall -Wextra -Woverflow -fsanitize=address
.PHONY: clean
clear:
	rm main