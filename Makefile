main:477.cpp
	g++ -o main 477.cpp -Wall -Wextra -Woverflow -fsanitize=undefined
.PHONY: clean
clear:
	rm main