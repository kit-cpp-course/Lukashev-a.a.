#pragma once
#include "stdafx.h"
#include "Data.h"



class DataSource  
{
public:
	//Словарь, к которому привязана строка
	Data date;
	DataSource(std::string Name, std::string Directory);
	DataSource() {};
	//Вывод строки
	std::string GetLine();
	//генерация строки
	void RndLine();
	
private:
	std::string Line;
};



