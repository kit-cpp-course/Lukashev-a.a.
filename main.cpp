#include "DataSource.h"
#include"stdafx.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;



int main() {
	srand(time(0));
	// Output - ���������� ��� ������ � �������� ������
	ofstream Output;
	/*
	* Count - ���������� ������������ �������	
	* AmountDate - ���������� �������� ��� ����������� �������
	*/
	int count, AmountDate;
	/*
	* WayOfDirectory - ������������ � �������, ��������� �� ������� � ����� ��������
	* NameCollum - ������������ � �������, �������� �� ������� � �������� ����� ������ �������
	*/
	char WayOfDirectory,NameCollum;
	/*
	* Directory - ���� �� �������(��� ��������, ���� ��� ��������� � ����� ��������)
	* NameOut - ��� ��������� �����
	* Name - �������� �������
	* GenerationLine - ������, ������������� � �������� ����
	* NameCollums - ��� �������
	*/
	string Directory, NameOut,Name, GenerationLine, NameCollums;
	cout << "������� ������ ���� �� ��������� ����� � ������ � ����������� CSV." << endl;
	cin >> NameOut;
	Output.open(NameOut);
	Output << "Index;";
	cout << "������� ���������� ��������." << endl;
	cin >> AmountDate;
	// DateSource - ������������ ������ �����, ������ �� ������� ��������� � ����������� �������
	DataSource *Source = new DataSource[AmountDate];
	cout << "������� ��������� � ����� ��������? [Y/N]" << endl;
	cin >> WayOfDirectory;
	cout << "��������! ������� ������� � ��� �������, � ������� ������ �������� ������ � �������� �����." << endl;
	if (WayOfDirectory == 'Y' || WayOfDirectory == 'y')
	{
		cout << "������� ���� �� �������� ��������" << endl;
		cin >> Directory;
		//���������� ������� ��������, ����� ������ �������, ��� ������� ��������� � ����� ��������
		for (int i = 0; i < AmountDate; i++) {
			cout << "������� ��� ������� ������ � �����������" << endl;
			cin >> Name;
			Source[i].DataSource::DataSource(Name, Directory);
			cout << "������� ������ � �������� ����� ������ �������? [Y/N]" << endl;
			cin >> NameCollum;
			if (NameCollum == 'Y' || NameCollum == 'y')
			{
				Output << Source[i].date.GetNameWithoutExterrior() + ';';
			}
			else
			{
				cout << "������� �������� �������" << endl;
				cin >> NameCollums;
				Output << NameCollums + ';';
			}
		}
	}
	else
	{
		//��������� ������� ��������, ����� ������ �������, ��� ������� �� ����� � ����� ��������
		for (int i = 0; i < AmountDate; i++) {
			cout << "������� ������ ���� �� �������." << endl;
			cin >> Directory;
			Source[i].DataSource::DataSource("NULL", Directory);
			cout << "������� ������ � �������� ����� ������ �������? [Y/N]" << endl;
			cin >> NameCollum;
			if (NameCollum == 'Y')
			{
				Output << Source[i].date.GetNameWithoutExterrior() + ';';
			}
			else
			{
				cout << "������� �������� �������." << endl;
				cin >> NameCollums;
				Output << NameCollums + ';';
			}
		}
	}
	Output << endl;
		cout << "������� ���������� ������������ ������." << endl;
		cin >> count;
		//��������� ������������ ���������� �������
		for (int i = 1; i <= count; i++)
		{
			GenerationLine = "";
			for (int k = 0; k < AmountDate; k++)
			{
				Source[k].RndLine();
				GenerationLine = GenerationLine + Source[k].GetLine() + ';';
			}
			//������ ��������� ������ � ����
			Output << to_string(i) + ';' + GenerationLine << endl;
		}
		Output.close();
		delete[] Source;
}