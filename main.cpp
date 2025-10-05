#include "game.hpp"

int main() {
	std::string input;
	game g;

	while (true) {
		std::cout << g;
		std::getline(std::cin, input);
		if (input[0] == EOF)
			break;
		g.setDiscoveredChar(input[0]);
	}
}
