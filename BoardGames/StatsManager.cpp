#include <fstream>
#include <iostream>
#include <vector>
#include "StatsManager.hpp"
#include "Player.hpp"


StatsManager::StatsManager(const std::string& file) : filename(file) {

}


void StatsManager::LoadStats(std::vector <std::shared_ptr<Player>>& currentPlayers) {
	allPlayers.clear();


	std::ifstream fin(filename);
	if (!fin.is_open()) {
		std::ofstream fout("game_stats.txt");
		return;
	}

	// Получаем статистику побед из файла
	std::string name;
	int wins;
	while (fin >> name >> wins) {
		auto old = std::make_shared<Player>(name);
		old->SetStats(wins);
		allPlayers.push_back(old);
	}
	fin.close();

	// Добавление текущих для вывода статистики
	for (auto& current : currentPlayers) {
		bool found = false;
		for (auto& saved : allPlayers) {
			if (saved->GetName() == current->GetName()) {
				current->SetStats(saved->GetStats());
				found = true;
				break;
			}
		}

		if (!found) allPlayers.push_back(current);
	}
}


void StatsManager::SaveStats(const std::vector<std::shared_ptr<Player>>& currentPlayers) {
	// Обновление статистики в списке всех игроков
	for (auto& current : currentPlayers) {
		for (auto& saved : allPlayers) {
			if (saved->GetName() == current->GetName()) {
				saved->SetStats(current->GetStats());
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
	for (auto& player : allPlayers) {
		fout << player->GetName() << " " << player->GetStats() << "\n";
	}

	fout.close();
}


void StatsManager::ShowStats() {
	std::cout << "--- Статистика побед ---\n";
	for (auto& player : allPlayers) {
		std::cout << player->GetName() << ": " << player->GetStats() << " побед\n";
	}
}
