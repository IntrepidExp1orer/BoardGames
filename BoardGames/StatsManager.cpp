#include <fstream>
#include <iostream>
#include <vector>
#include "StatsManager.hpp"
#include "Player.hpp"


StatsManager::StatsManager(const std::string& file) : filename(file) {

}


void StatsManager::LoadStats(std::vector<Player>& current_players) {
	all_players.clear();

	std::ifstream fin(filename);
	if (!fin.is_open()) {
		std::cout << "Ошибка при открытии файлы.\n";
		return;
	}

	// Получаем статистику побед из файла
	std::string name;
	int wins;
	while (fin >> name >> wins) {
			Player old(name);
			old.SetStats(wins);
			all_players.push_back(old);
	}
	fin.close();

	// Добавление текущих для вывода статистики
	for (Player& current : current_players) {
		bool found = false;
		for (Player& saved : all_players) {
			if (saved.GetName() == current.GetName()) {
				current.SetStats(saved.GetStats());
				found = true;
				break;
			}
		}

		if (!found) all_players.push_back(current);
	}
}


void StatsManager::SaveStats(std::vector<Player>& current_players) {
	// Обновление статистики в списке всех игроков
	for (Player& current : current_players) {
		for (Player& saved : all_players) {
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
	for (Player& player : all_players) {
		fout << player.GetName() << " " << player.GetStats() << "\n";
	}

	fout.close();
}


void StatsManager::ShowStats() {
	std::cout << "--- Статистика побед ---\n";
	for (Player& player : all_players) {
		std::cout << player.GetName() << ": " << player.GetStats() << " побед\n";
	}
}
