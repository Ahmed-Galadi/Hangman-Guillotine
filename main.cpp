#include "game.hpp"
#include <iostream>

int main() {
    std::string input;
    game g;

    while (!g.isGameOver()) {
        std::cout << g;
        std::cout << "\nEnter a letter: ";
        
        if (!std::getline(std::cin, input))
            break;
        
        if (input.empty())
            continue;
        
        if (input.length() > 1) {
            std::cout << "Please enter only one character!\n";
            continue;
        }
        
        g.setDiscoveredChar(input[0]);
    }
    
    std::cout << g;
    return 0;
}
