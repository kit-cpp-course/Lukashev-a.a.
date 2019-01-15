#include "Data.h"
#include "stdafx.h"



Data::Data(std::string Directory)
{
	//Находит название словаря в полном пути до него
	int i=Directory.length() - 1;
	while (Directory[i] != '/')
	{
		i--;
	} 
	for (int k = 0; k < i; k++)
	{
		WayOfFile = WayOfFile + Directory[k];
	}
	for (int k = i+1 ; k <= Directory.length() - 1; k++)
	{
		NameOfFile = NameOfFile +Directory[k];
	}
	AmountOfLine = 0;
	GetAmount();
}
Data::Data(std::string name, std::string Directory)
{
	NameOfFile = name;
	WayOfFile = Directory;
	AmountOfLine = 0;
	GetAmount();
}
int Data::ReturnAmount() {
	return AmountOfLine;
}
void Data::GetAmount() {
	std::ifstream Input;
	std::string line;
	Input.open(WayOfFile+ '/' +NameOfFile);
	while (Input.eof() != 1) {
		std::getline(Input, line);
		AmountOfLine++;
	}
}
std::string Data::GetRandomLine() {
	//генерирует случайный номер строки, который будет считан из словаря
	int random = rand() % AmountOfLine + 1;
	std::ifstream Input;
	std::string line;
	Input.open(WayOfFile + '/' + NameOfFile);
	for (int i = 0; i <= random+1; i++)
	{
		std::getline(Input, line);
	}
	Input.close();
	return line;
}
std::string Data::GetNameWithoutExterrior()
{
	int i = 0;
	std::string rt;
	while (NameOfFile[i] != '.')
	{
		rt = rt + NameOfFile[i];
		i++;
	}
	return rt;
}




