#pragma once
#include "stdafx.h"


class Data
{
public:
	Data() {};
	//Компилятор, использующий полный путь до словаря вместе с именем
	Data(std::string Directory);
	//Компилятор, использующий отдельно путь до словаря и отдельно название словаря
	Data(std::string name, std::string Directory);
	//Возвращает количество строк в словаре
	int ReturnAmount();
	//Считывание случайной строки из словаря
	std::string GetRandomLine();
	//Вывод имени словаря без расширения
	std::string GetNameWithoutExterrior();
	// Определяет количество строк в словаре
	void GetAmount();

private:
	/*
	* WayOfFile - Путь до словаря
	* NameOfFile - Имя словаря с расширением
	*/
	std::string WayOfFile, NameOfFile;
	// Количество строк в словаре
	int AmountOfLine;
	
};



