/*
 * Лабораторная работа 4
 * Вариант 4
 *
 * 1) Создайте классы Мечник, Маг, Стрелок (различие между магом и стрелком в стойкости и силе, маг сильнее, но менее вынослив, стрелок наоборот) со свойствами сила, стойкость, дистанция, стоимость.
 * 2) Создайте класс Наемник, который хранит объект персонаж за указателем на пустоту и его тип.
 * 3) Создайте класс Гильдия, которая хранит список наемников.
 * 4) Заполните массив случайными наемниками так, чтобы в гильдии были наемники всех типов, при этом был хотя бы один мечник танк, хотя бы один мечник, наносящий значительный урон, маги и стрелки средних и дальних дистанций.
 * 5) Добавьте метод просмотра списка наемников и наполнения группы, в котором пользователь получает сводную таблицу всех наемников в гильдии и добавляет их в свою группу.
 * 6) (Усложнение) Создайте метод автоматического формирования идеальной группы на основании ее предельной стоимости, с учетом максимизации их силы. Идеальной группой будем называть такую группу, которая состоит из не менее 5 человек, способна сражаться на близкой и средней дистанции (дальняя не является обязательной, но желательна), а их суммарная стойкость не менее половины от их силы.
 */

#include <iostream>

#include "../include/Guild.h"

int main()
{
	srand(time(nullptr));
		
	Guild guild;
	
	guild.get_random_mercenaries();
	guild.get_show_mercenaries();
	guild.set_group();	
	guild.get_ideal_group();

	return 0;
}
