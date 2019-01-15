#include"DataSource.h"



DataSource::DataSource(std::string Name, std::string Directory)
{
	if (Name == "NULL")
	{
		date=Data(Directory);
	}
	else
	{
		date=Data(Name, Directory);
	}
}
std::string DataSource::GetLine() {
	return Line;
}

void DataSource::RndLine()
{
	Line = date.GetRandomLine();
}