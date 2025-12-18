#include <ctime>
#include <sstream>
#include <vector>
#include "YahtzeeGame.hpp"
#include "Board.hpp"


YahtzeeGame::YahtzeeGame(const std::vector<PlayerPtr>& players) : Game(players) {}

int YahtzeeGame::hands = 6;

void YahtzeeGame::Start() {
	srand(static_cast<unsigned>(time(nullptr)));

	Board scoreBoard(hands + 1, players.size());

	std::cout << "\n----- Yahtzee -----\n";
	std::cout << scoreBoard << std::endl;
	for (int i = 0; i < hands; i++) {
		for (int j = 0; j < players.size(); j++) {
			std::string message = "Игрок " + players[j]->GetName() + ":\n";
			std::cout << message;
			dice.RollAll();
			std::cout << dice << std::endl;
			Process_move();

			// На данный момент не отражает реальный геймплей
			scoreBoard.SetValue(i, j, dice.Sum());
			scoreBoard.PointSum(j);
		}
		std::cout << scoreBoard << std::endl;
	}

	// Зачисление победы
	int winner = 0;
	int win_points = 0;
	bool draw = false;
	for (int j = 0; j < players.size(); j++) {
		int p = scoreBoard.GetValue(hands, j);
		if (p == win_points) draw = true;
		if (p > win_points) {
			win_points = p;
			winner = j;
			draw = false;
		}
	}

	if (!draw) {
		players[winner]->AddWin();
		std::cout << "Победил " << players[winner]->GetName();
	}
}

void YahtzeeGame::Process_move() {
	int extraRolls = 2;
	while (extraRolls > 0) {
		std::cout << "Хотите перебросить некоторые кубики? (y/n): ";
		char choice;
		std::cin >> choice;
		if (choice == 'n' || choice == 'N') break;


		std::cout << "Введите номера кубиков для переброса (1-5, через пробел): ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::string chosenLine;
		std::getline(std::cin, chosenLine);
		std::istringstream ss(chosenLine);

		std::vector<int> indices;
		int temp;
		while (ss >> temp) indices.push_back(temp);

		dice.RollSelected(indices);
		std::cout << dice << std::endl;
		extraRolls--;
	}
}


void YahtzeeGame::SetHands(int number) {
	hands = number;
}


int YahtzeeGame::GetHands() {
	return hands;
}

void YahtzeeGame::Rules() const {
	Game::Rules();
	std::cout << "Игроки по очереди бросают кубики до трех раз за ход.\nПри перебросе можно выбрать какие кубики оставить.\nЦель - выбить максимум очков.\n";
}

YahtzeeGame& YahtzeeGame::operator=(const Game& other) {
	if (this == &other) return *this;

	this->players = other.GetPlayerList();
	return *this;
}
