#include "game.hpp"
#include <random>
#include <fstream>
#include <vector>

// static helpers

static int randomIndex() {
	std::random_device	randDev;
	std::mt19937		gen(randDev());
	std::uniform_int_distribution<> dis(1, 201);
	return (dis(gen));
}
static std::vector<std::string> getFrame(int failureCount) {
    std::vector<std::string> output;
    
    int start = failureCount * 9;
    
    std::ifstream stateFile("Guillotine.txt");
    if (!stateFile.is_open()) {
        std::cerr << "Error: Could not open Guillotine.txt" << std::endl;
        return output;
    }    
    std::string line;

    for (int i = 0; i < start && getline(stateFile, line); i++) ;
    
	if (failureCount == 5)
		for (int i = 0; i < 11 && getline(stateFile, line); i++)
			output.push_back(line);
	else
	   for (int i = 0; i < 8 && getline(stateFile, line); i++)
		 output.push_back(line);
	return output;
}


// class members
game::game() : failureCount(0), score(0), gameOver(false) {
	int				wordIndex = randomIndex();
	std::fstream	wordsFile("words.txt");
	std::string		word;
	if (wordsFile.is_open()) {
		while (std::getline(wordsFile, word) && wordIndex--) ;
		wordsFile.close();
	}
	secretWord = word;
	discoveredChars = std::string(secretWord.length(), '_');
}

void	game::setDiscoveredChar(char c) {
	size_t i;
	bool	correct = false;
	for (i = 0; i < secretWord.length(); i++) {
		if (c == secretWord[i]) {
			discoveredChars[i] = secretWord[i];
			score += 10;
			correct = true;
		}
	}
	if (!correct)
		incFailure();
}

void	game::incFailure() {
	if (failureCount == 5)
		gameOver = true;
	else
		failureCount++;
}

std::string	game::getSecretWord() const {
	return (secretWord);
}

std::string	game::getDiscovered() const {
	return (discoveredChars);
}

int			game::getFailure() const {
	return (failureCount);
}

int			game::getScore() const {
	return (score);
}

bool		game::isGameOver() const {
	return (gameOver);
}

std::ostream	&operator<<(std::ostream &o, const game &data) {
	std::cout << "\033[2J\033[H";
	if (data.isGameOver()) {
		o << "The Secret Word Is: " << data.getSecretWord() << "\n";
		o << "GAME OVER !" << std::endl;
	}
	else {
		std::vector<std::string> frame = getFrame(data.getFailure());
		for (int i = 0; i < frame.size(); i++)
			std::cout << frame[i] << "\n";
		std::cout << "\n" << data.getDiscovered() << "\n";
	}
	return (o);
}
