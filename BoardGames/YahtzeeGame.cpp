#include <ctime>
#include <sstream>
#include <vector>
#include "YahtzeeGame.hpp"
#include "Board.hpp"


YahtzeeGame::YahtzeeGame(std::vector<Player>& currentPlayers) : Game(currentPlayers) {}

void YahtzeeGame::Start() {
	srand(static_cast<unsigned>(time(nullptr)));

	Board scoreBoard(HANDS + 1, players.size());

	std::cout << "\n----- Yahtzee -----\n";
	scoreBoard.Show();
	for (int i = 0; i < HANDS; i++) {
		for (int j = 0; j < players.size(); j++) {
			std::cout << "\n- Игрок " << players[j].GetName() << ":\n";
			dice.RollAll();
			dice.Show();
			Process_move();

			// На данный момент не отражает реальный геймплей
			scoreBoard.SetValue(i, j, dice.Sum());
			scoreBoard.PointSum(j);
		}
		scoreBoard.Show();
	}

	// Зачисление победы
	int winner = 0;
	int win_points = 0;
	bool draw = false;
	for (int j = 0; j < players.size(); j++) {
		int p = scoreBoard.GetValue(HANDS, j);
		if (p == win_points) draw = true;
		if (p > win_points) {
			win_points = p;
			winner = j;
			draw = false;
		}
	}

	if (!draw) {
		players[winner].AddWin();
		std::cout << "Победил " << players[winner].GetName();
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
		dice.Show();
		extraRolls--;
	}


}