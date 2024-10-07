#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include "Mercenary.h"
#include <vector>
class Guild 
{
	private:
		Mercenary** mercenaries;
		int size_mercenaries;
		int capacity_mercenaries;

		Mercenary** group;
		int size_group;
		int capacity_group;

		void resize_mercenaries_mercenaries() {
			capacity_mercenaries *= 2;
		   
			Mercenary** temp_mercenaries = new Mercenary*[capacity_mercenaries];
			for (int i = 0; i < size_mercenaries; i++) 
				temp_mercenaries[i] = mercenaries[i];
		  
			delete[] mercenaries;
			mercenaries = temp_mercenaries;
		}

		void resize_mercenariesGroup() 
		{
			capacity_group *= 2;

			Mercenary** temp_group = new Mercenary*[capacity_group];
			for (int i = 0; i < size_group; i++)
				temp_group[i] = group[i];
			
			delete[] group;
			group = temp_group;
		}

	public:
		Guild() : 
			size_mercenaries(0), 
			capacity_mercenaries(2),
			size_group(0),
			capacity_group(2) 
		{
			mercenaries = new Mercenary*[capacity_mercenaries];
			group = new Mercenary*[capacity_group];
		}

		~Guild() 
		{
			for (int i = 0; i < size_mercenaries; i++)
				delete mercenaries[i]; 

			delete[] mercenaries; 
			delete[] group; 
		}

		void set_add_mercenaries(Mercenary* mercenary) {
			if (size_mercenaries >= capacity_mercenaries) 
				resize_mercenaries_mercenaries();
			
			mercenaries[size_mercenaries++] = mercenary;
		}

		void get_random_mercenaries() {
			for (int i = 0; i < Constants::capacity; i++) 
			{ 
				int type = rand() % 3;

				switch(type)
				{
					case(0):
						set_add_mercenaries(new Mercenary(new Swordsman(), 0));
					case(1):
						set_add_mercenaries(new Mercenary(new Mage(), 1));
				
					case(2):
						set_add_mercenaries(new Mercenary(new Shooter(), 2));
				}
			}
		}

		void set_add_mercenaries_group(Mercenary* mercenary) {
			if (size_group >= capacity_group)
				resize_mercenariesGroup();

			group[size_group++] = mercenary;
		}

		void get_show_mercenaries() const { 
			for (int i = 0; i < size_mercenaries; i++) 
				mercenaries[i]->get_mercenary_characteristic();
		}

		void get_show_group() const {
			for (int i = 0; i < size_group; i++)
				group[i]->get_mercenary_characteristic();
		}

		void set_group() 
		{
			int choice = 12345;
			while (choice != 3)
			{
				std::cout << "----------------------------------------------------" << std::endl;
				std::cout << std::endl << "\tВыберите число:" << std::endl;
				std::cout << "\t\t1. Добавить наемника." << std::endl;
				std::cout << "\t\t2. Показать группу." << std::endl;
				std::cout << "\t\t3. Выход." << std::endl << std::endl;
				std::cout << "----------------------------------------------------" << std::endl;
				std::cin >> choice;

				if (choice == 1)
				{
					int counter_mercenary;
					std::cout << "Номер наемника в столбце: ";
					std::cin >> counter_mercenary;

					if (counter_mercenary > 0 && counter_mercenary <= size_mercenaries) 	{
						set_add_mercenaries_group(mercenaries[counter_mercenary - 1]);
						std::cout << "Наемник добавлен" << std::endl;
					}

					set_group();
				}
				else if (choice == 2)
				{
					std::cout << std::endl << "Группа:" << std::endl;
					get_show_group();
					set_group();
				} 
				else if (choice == 3) 
						break;
			}
		}
		 
		void get_ideal_group() {
			std::vector<Mercenary*> ideal_group; // Идеальная группа
			int max_cost = 1000; // Максимальная стоимость группы (можно изменить по желанию)
			int total_power = 0; // Общая сила группы
			int total_durability = 0; // Общая стойкость группы
			int total_cost = 0; // Общая стоимость группы
			int near_distance_count = 0; // Счетчик для близкой дистанции
			int mid_distance_count = 0; // Счетчик для средней дистанции

			for (int i = 0; i < size_mercenaries; i++) {
				// Получаем указатель на наемника
				Mercenary* merc = mercenaries[i];

				// Конкретизация указателя на персонажа для получения характеристик
				int current_power = 0;
				int current_durability = 0;
				int current_distance = 0;
				int current_cost = 0;

				// Используем switch для правильного доступа к характеристикам
				switch(merc->type) {
					case 0: // Swordsman
						current_power = static_cast<Swordsman*>(merc->character)->get_power();
						current_durability = static_cast<Swordsman*>(merc->character)->get_durability();
						current_distance = static_cast<Swordsman*>(merc->character)->get_distance();
						current_cost = static_cast<Swordsman*>(merc->character)->get_cost();
						break;
					case 1: // Mage
						current_power = static_cast<Mage*>(merc->character)->get_power();
						current_durability = static_cast<Mage*>(merc->character)->get_durability();
						current_distance = static_cast<Mage*>(merc->character)->get_distance();
						current_cost = static_cast<Mage*>(merc->character)->get_cost();
						break;
					case 2: // Shooter
						current_power = static_cast<Shooter*>(merc->character)->get_power();
						current_durability = static_cast<Shooter*>(merc->character)->get_durability();
						current_distance = static_cast<Shooter*>(merc->character)->get_distance();
						current_cost = static_cast<Shooter*>(merc->character)->get_cost();
						break;
				}

				// Проверяем, укладываемся ли мы в бюджет
				if (total_cost + current_cost <= max_cost) {
					// Добавляем наемника в группу
					ideal_group.push_back(merc);
					total_power += current_power;
					total_durability += current_durability;
					total_cost += current_cost; // Добавлено для подсчета общей стоимости

					// Проверяем дистанции
					if (current_distance == 1) {
						near_distance_count++;
					}
					if (current_distance == 2) {
						mid_distance_count++;
					}
				}

				// Проверяем, соответствует ли группа критериям
				if (ideal_group.size() >= 5 &&
					total_durability >= 0.5 * total_power &&
					near_distance_count >= 1 &&
					mid_distance_count >= 1) {
						// Группа соответствует критериям
						break;
				}
			}

			// Выводим идеальную группу
			if (ideal_group.size() > 0) {
				std::cout << "Идеальная группа:" << std::endl;
				for (auto& merc : ideal_group) {
					merc->get_mercenary_characteristic();
				}
			} else {
				std::cout << "Не удалось сформировать идеальную группу." << std::endl;
			}
}	
};
#endif // GUILD_H	
