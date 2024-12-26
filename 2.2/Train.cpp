#include "Train.h"
#include "Train.h"

Train::Train() : number(0), destination(""), type(""), departure_time("00:00"), travel_time("00:00")
{}

Train::Train(int32_t num, std::string des, std::string type, std::string dep_time, std::string trav_time) : number(num), destination(des), type(type), departure_time(dep_time), travel_time(trav_time) 
{
    if (type != "пассажирский" && type != "скорый") {
        throw std::invalid_argument("Неверный тип поезда");
    }
    try {
        time_to_minutes(departure_time);
        time_to_minutes(travel_time);
    }
    catch (const std::invalid_argument&) {
        throw std::invalid_argument("Неверный формат времени");
    }
}


bool Train::operator<(const Train& rhs)
{
    return time_to_minutes(departure_time) < time_to_minutes(rhs.departure_time);
}

bool Train::operator>(const Train& rhs)
{
    return !(*this < rhs);
}

int32_t Train::time_to_minutes(const std::string& time)
{
    size_t colon_pos = time.find(':');
    std::regex time_format("^([0-2][0-9]):([0-5][0-9])$");
    if (!std::regex_match(time, time_format)) {
        throw std::invalid_argument("Некорректный формат времени");
    }
    int32_t hours = std::stoi(time.substr(0, colon_pos));
    int32_t minutes = std::stoi(time.substr(colon_pos + 1));
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        throw std::invalid_argument("Некорректное время");
    }
    return hours * 60 + minutes;
}

bool Train::is_in_time_range(std::string left_side, std::string right_side)
{
    int32_t left = time_to_minutes(left_side);
    int32_t right = time_to_minutes(right_side);
    if (left > right)
        std::swap(left, right);
    return left <= time_to_minutes(departure_time) && right >= time_to_minutes(departure_time);
}

bool Train::to_destination(const std::string& dest)
{
    return destination == dest;
}

bool Train::to_destination_fast(const std::string& dest)
{
    return destination == dest && type == "скорый";
}

int32_t Train::time_in_way()
{
    return time_to_minutes(travel_time);
}

Train::~Train()
{}

std::ostream& operator<<(std::ostream& out, const Train& rhs)
{
    out << std::setw(15) << "Поезд номер " << rhs.number << std::setw(10) << ", пункт назначения: " << rhs.destination  << ", тип: " << rhs.type  << ", отправление: " << rhs.departure_time << ", время в пути: " << rhs.travel_time << "\n";
    return out;
}
