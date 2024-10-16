#ifndef WORK_H
#define WORK_H

#include "MachineTool.h"

class Work
{
	private:
		int sum_repair_cost;
		int sum_amount_of_breakages;
		int sum_breaking_time;
		int max_sum_breaking_time;
		int sum_amount_of_part_replacements;
		int sum_repair_cost_per_machine[Constants::amount_of_machine_tools];
		int breakages_per_machine[Constants::amount_of_machine_tools]; 

	public:
		Work()
		:
			sum_repair_cost(0),
			sum_amount_of_breakages(0),
			sum_breaking_time(0),
			max_sum_breaking_time(0),
			sum_amount_of_part_replacements(0)
		{
			for (int i = 0; i < Constants::amount_of_machine_tools; i++)
			{
				sum_repair_cost_per_machine[i] = 0;
				breakages_per_machine[i] = 0;
			}
		}
		void simulating()
		{
			for (int month = 0; month < Constants::months; month++)
			{
				for (int i = 0; i < Constants::amount_of_machine_tools; i++)
				{
					MachineTool machine;

					int intensity = rand() % Constants::max_intensity + 1;

					machine.operating(intensity, i);

					sum_repair_cost += machine.get_repair_cost();
					sum_amount_of_breakages += machine.get_amount_of_breakages();
					sum_breaking_time += machine.get_breaking_time();
					max_sum_breaking_time = (max_sum_breaking_time > machine.get_sum_breaking_time()) ? max_sum_breaking_time : machine.get_sum_breaking_time();
					sum_amount_of_part_replacements += machine.get_amount_of_part_replacements();
					sum_repair_cost_per_machine[i] += machine.get_repair_cost();
					breakages_per_machine[i] += machine.get_individual_breakage(i);	

					print_parts(machine);
				}
			}
		}
		
		void get_work_characteristic()
		{
			std::cout << "Количество заменяемых запчастей - " << sum_amount_of_part_replacements << " запчастей" << std::endl;

			std::cout << "Стоимость ремонта каждого станка:" << std::endl;
			for (int i = 0; i < Constants::amount_of_machine_tools; i++)
				std::cout << "\tСтанок " << i + 1 << " - " << sum_repair_cost_per_machine[i] << " денег" << std::endl;
			
			std::cout << "Количество поломок каждого станка:" << std::endl;
			for (int i = 0; i < Constants::amount_of_machine_tools; i++)
				std::cout << "\tСтанок " << i + 1 << " - " << breakages_per_machine[i] << " поломок" << std::endl;

			std::cout << "Количество поломок всех станков - " << sum_amount_of_breakages << " поломок" << std::endl;

			std::cout << "Суммарный простой станков - " << sum_breaking_time << " часов" << std::endl;

			std::cout << "Максимальный суммарный простой одного станка - " << max_sum_breaking_time << " часов" << std::endl;
		}
};

#endif
