#include "game.hpp"
#include <random>
#include <fstream>

// static helpers

static int randomIndex() {
	std::random_device	randDev;
	std::mt19937		gen(randDev());
	std::uniform_int_distribution<> dis(1, 201);
	return (dis(gen));
}

static std::string	getFrame(int failureCount) {

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
	for (i = 0; i < secretWord.length(); i++) {
		if (c == secretWord[i]) {
			discoveredChars[i] = secretWord[i];
			score += 10;
		}
	}
	if (i != secretWord.length() - 1)
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
	
	return (o);
}
