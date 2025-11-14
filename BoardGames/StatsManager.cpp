#include <fstream>
#include <iostream>
#include <vector>
#include "StatsManager.hpp"
#include "Player.hpp"


StatsManager::StatsManager(const std::string& file) : filename(file) {

}


void StatsManager::LoadStats(std::vector<Player>& currentPlayers) {
	allPlayers.clear();

	std::ofstream fout("game_stats.txt");
	if (!fout.is_open()) {
		std::cerr << "Ошибка создания файла!\n";
	}
	fout.close();

	std::ifstream fin(filename);
	if (!fin.is_open()) {
		std::cout << "Ошибка при открытии файла.\n";
		return;
	}

	// Получаем статистику побед из файла
	std::string name;
	int wins;
	while (fin >> name >> wins) {
			Player old(name);
			old.SetStats(wins);
			allPlayers.push_back(old);
	}
	fin.close();

	// Добавление текущих для вывода статистики
	for (Player& current : currentPlayers) {
		bool found = false;
		for (Player& saved : allPlayers) {
			if (saved.GetName() == current.GetName()) {
				current.SetStats(saved.GetStats());
				found = true;
				break;
			}
		}

		if (!found) allPlayers.push_back(current);
	}
}


void StatsManager::SaveStats(std::vector<Player>& currentPlayers) {
	// Обновление статистики в списке всех игроков
	for (Player& current : currentPlayers) {
		for (Player& saved : allPlayers) {
			if (saved.GetName() == current.GetName()) {
				saved.SetStats(current.GetStats());
				break;
			}
		}
	}

	std::ofstream fout(filename);
	if (!fout.is_open()) {
		std::cout << "Ошибка открытия файла.\n";
		return;
	}

	// Сохранение статистики в файл
	std::string name;
	int wins;
	for (Player& player : allPlayers) {
		fout << player.GetName() << " " << player.GetStats() << "\n";
	}

	fout.close();
}


void StatsManager::ShowStats() {
	std::cout << "--- Статистика побед ---\n";
	for (Player& player : allPlayers) {
		std::cout << player.GetName() << ": " << player.GetStats() << " побед\n";
	}
}
