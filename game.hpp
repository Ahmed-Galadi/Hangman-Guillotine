#pragma once

#include <string>
#include <iostream>

class game {
	private:
		std::string secretWord;
		std::string	discoveredChars;
		int			failureCount;
		int			score;
		bool		gameOver;
	public:
		game();
		
		void	setDiscoveredChar(char c);
		void	incFailure();
		void	incScore();
		void	setGameOver();

		std::string	getSecretWord() const;
		std::string	getDiscovered() const;
		int			getFailure() const;
		int			getScore() const;
		bool		isGameOver() const;
};

std::ostream &operator<<(std::ostream &o, const game &data);
