#pragma once
#include "stdafx.h"


class Data
{
public:
	Data() {};
	//����������, ������������ ������ ���� �� ������� ������ � ������
	Data(std::string Directory);
	//����������, ������������ �������� ���� �� ������� � �������� �������� �������
	Data(std::string name, std::string Directory);
	//���������� ���������� ����� � �������
	int ReturnAmount();
	//���������� ��������� ������ �� �������
	std::string GetRandomLine();
	//����� ����� ������� ��� ����������
	std::string GetNameWithoutExterrior();
	// ���������� ���������� ����� � �������
	void GetAmount();

private:
	/*
	* WayOfFile - ���� �� �������
	* NameOfFile - ��� ������� � �����������
	*/
	std::string WayOfFile, NameOfFile;
	// ���������� ����� � �������
	int AmountOfLine;
	
};



