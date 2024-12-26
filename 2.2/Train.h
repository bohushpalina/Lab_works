#ifndef _TRAIN_H
#define _TRAIN_H

#include <iostream>
#include <string>
#include<windows.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <regex>
#include <iomanip>

class Train
{
private:
	/*����� ������;
	o �������� ������ ����������;
	o ��� ������(������������, ������);
	o ����� �����������(����, ������ � ������� �� : ��);
	o ����� � ����.*/
	int32_t number;
	std::string destination;
	std::string type;
	std::string departure_time; 
	std::string travel_time;             //����� � ����.
public:
	Train();
	Train(int32_t, std::string, std::string, std::string, std::string);
	~Train();

	bool operator<(const Train&);
	bool operator>(const Train&);
	int32_t time_to_minutes(const std::string& time);
	friend std::ostream& operator<<(std::ostream&, const Train&);
	bool is_in_time_range(std::string left_side, std::string right_side);
	bool to_destination(const std::string&);
	bool to_destination_fast(const std::string&);
	int32_t time_in_way();
};


#endif

