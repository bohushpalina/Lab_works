#include "Train.h"
#include <iostream>

void CheckFile(std::ifstream&);
void Print(const std::vector<Train>&);
void LoadTrains(std::ifstream& file, std::vector<Train>& trains);
void SortAndPrintTrains(std::vector<Train>& trains);
void PrintTrainsInTimeRange(std::vector<Train>& trains);
void PrintTrainsToDestination(std::vector<Train>& trains);
void PrintFastTrainsToDestination(std::vector<Train>& trains);
void FindFastestTrain(std::vector<Train>& trains);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file("Input.txt");
	try
	{
		CheckFile(file);
		std::vector<Train> trains;
		LoadTrains(file, trains);
		SortAndPrintTrains(trains);
		PrintTrainsInTimeRange(trains);
		PrintTrainsToDestination(trains);
		PrintFastTrainsToDestination(trains);
		FindFastestTrain(trains);
	}
	catch (const std::exception& e) {
		std::cout << "������: " << e.what() << std::endl;
	}
	file.close();
	return 0;
}

void CheckFile(std::ifstream& file)
{
	if (!file)
		throw "���� �� ����������";
	if (!file.is_open())
		throw "���� �� ��������";
	if (file.peek() == EOF)
		throw "���� ������";
}

void Print(const std::vector<Train>& trains)
{
	for (size_t i = 0; i < trains.size(); ++i)
		std::cout << trains[i];
}


void LoadTrains(std::ifstream& file, std::vector<Train>& trains)
{
	int32_t num;
	std::string destination, type, dep_t, trav_t;

	while (file >> num >> destination >> type >> dep_t >> trav_t) {
		Train train(num, destination, type, dep_t, trav_t);
		trains.push_back(train);
	}
}

void SortAndPrintTrains(std::vector<Train>& trains)
{
	std::sort(trains.begin(), trains.end());
	std::cout << "������ ������������� ������������ ������� �����������: \n";
	Print(trains);
}

void PrintTrainsInTimeRange(std::vector<Train>& trains)
{
	std::string left, right;
	std::cout << "������� �������� �� ������� (������ ��:��), ���� ������� ������� � ����� ������: \n";
	std::getline(std::cin, left);
	std::getline(std::cin, right);
	bool found = false;
	for (size_t i = 0; i < trains.size(); ++i)
	{
		if (trains[i].is_in_time_range(left, right))
		{
			std::cout << trains[i];
			found = true;
		}
	}
	if (!found)
		std::cout << "������ �� ������ ����� �� �������!\n";
}


void PrintTrainsToDestination(std::vector<Train>& trains)
{
	std::cout << "������� ����� ����������� ��� ���� �������: \n";
	std::string place;
	std::getline(std::cin, place);
	std::cout << "������, �������������� � ������ �����: \n";
	bool found = false;
	for (size_t i = 0; i < trains.size(); ++i)
	{
		if (trains[i].to_destination(place))
		{
			std::cout << trains[i];
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "������ �� ����� � ����� �����\n";
	}
}

void PrintFastTrainsToDestination(std::vector<Train>& trains)
{
	std::string place;
	std::cout << "������� ����� ����������� ��� ������ �������: \n";
	std::getline(std::cin, place);
	std::cout << "������ ������, �������������� � ������ �����: \n";
	bool found = false;
	for (size_t i = 0; i < trains.size(); ++i)
	{
		if (trains[i].to_destination_fast(place))
		{
			std::cout << trains[i];
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "������ ������ �� ����� � ����� �����\n";
	}
}

void FindFastestTrain(std::vector<Train>& trains)
{
	std::string place;
	int32_t time = INT32_MAX;
	Train fastest_train;
	std::cout << "������� ����� ���������� ��� ���������� ����������� ������ ����: \n";
	std::getline(std::cin, place);
	for (size_t i = 0; i < trains.size(); ++i)
	{
		if (trains[i].time_in_way() < time && trains[i].to_destination(place))
		{
			time = trains[i].time_in_way();
			fastest_train = trains[i];
		}
	}
	if (time == MAXINT32)
	{
		std::cout << "������ �� ����� � ���� ���������� �����\n";
	}
	else
	{
		std::cout << "���������� ����� � ������ �����: \n" << fastest_train;
	}
}