main:51_v2.cpp
	g++ -o main 51_v2.cpp -Wall -Wextra -Woverflow -fsanitize=address
.PHONY: clean
clear:
	rm main