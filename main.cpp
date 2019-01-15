#include "DataSource.h"
#include"stdafx.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;



int main() {
	srand(time(0));
	// Output - переменная для работы с конечным файлом
	ofstream Output;
	/*
	* Count - количество генерируемых записей	
	* AmountDate - количество словарей для составления записей
	*/
	int count, AmountDate;
	/*
	* WayOfDirectory - используется в вопросе, находятся ли словари в одном каталоге
	* NameCollum - используется в вопросе, называть ли столбец в конечном файле именем словаря
	*/
	char WayOfDirectory,NameCollum;
	/*
	* Directory - путь до словаря(или словарей, если все находятся в одном каталоге)
	* NameOut - имя конечного файла
	* Name - название словаря
	* GenerationLine - запись, сохраняющаяся в конечный файл
	* NameCollums - имя столбца
	*/
	string Directory, NameOut,Name, GenerationLine, NameCollums;
	cout << "Введите полный путь до конечного файла с именем и расширением CSV." << endl;
	cin >> NameOut;
	Output.open(NameOut);
	Output << "Index;";
	cout << "Введите количество словарей." << endl;
	cin >> AmountDate;
	// DateSource - динамический массив строк, каждая из которых привязана к конкретному словарю
	DataSource *Source = new DataSource[AmountDate];
	cout << "Словари находятся в одном каталоге? [Y/N]" << endl;
	cin >> WayOfDirectory;
	cout << "Внимание! Вводите словари в том порядке, в котором хотите получить данные в конечном файле." << endl;
	if (WayOfDirectory == 'Y' || WayOfDirectory == 'y')
	{
		cout << "Введите путь до каталога словарей" << endl;
		cin >> Directory;
		//Заполнение массива словарей, когда выбран вариант, что словари находятся в одном каталоге
		for (int i = 0; i < AmountDate; i++) {
			cout << "Введите имя словаря вместе с расширением" << endl;
			cin >> Name;
			Source[i].DataSource::DataSource(Name, Directory);
			cout << "Назвать стобец в исходном файле именем словаря? [Y/N]" << endl;
			cin >> NameCollum;
			if (NameCollum == 'Y' || NameCollum == 'y')
			{
				Output << Source[i].date.GetNameWithoutExterrior() + ';';
			}
			else
			{
				cout << "Введите названия столбца" << endl;
				cin >> NameCollums;
				Output << NameCollums + ';';
			}
		}
	}
	else
	{
		//зполнение массива словарей, когда выбран вариант, что словари не лежат в одном каталоге
		for (int i = 0; i < AmountDate; i++) {
			cout << "Введите полный путь до словаря." << endl;
			cin >> Directory;
			Source[i].DataSource::DataSource("NULL", Directory);
			cout << "Назвать стобец в исходном файле именем словаря? [Y/N]" << endl;
			cin >> NameCollum;
			if (NameCollum == 'Y')
			{
				Output << Source[i].date.GetNameWithoutExterrior() + ';';
			}
			else
			{
				cout << "Введите название столбца." << endl;
				cin >> NameCollums;
				Output << NameCollums + ';';
			}
		}
	}
	Output << endl;
		cout << "Введите количество генерируемых данных." << endl;
		cin >> count;
		//генерация необходимого количества записей
		for (int i = 1; i <= count; i++)
		{
			GenerationLine = "";
			for (int k = 0; k < AmountDate; k++)
			{
				Source[k].RndLine();
				GenerationLine = GenerationLine + Source[k].GetLine() + ';';
			}
			//запись созданной записи в файл
			Output << to_string(i) + ';' + GenerationLine << endl;
		}
		Output.close();
		delete[] Source;
}