#ifndef FRACTIONS_H  
#define FRACTIONS_H
#include <iostream>*-*
#include <string>

class Fraction
{
private:
	int32_t n;
	int32_t d;
public:
	//конструкторы
	//Fraction();
	Fraction(int32_t);
	Fraction(int32_t = 0, int32_t = 1);

	Fraction& operator=(const Fraction&);

	//доступ к числителю или знаменателю
	int32_t& operator[](int index);

	//деструктор
	~Fraction();

	//Преобразования
	Fraction operator+(const Fraction&);
	Fraction operator+(const int32_t&);
	friend Fraction operator+ (const int32_t&, const Fraction&);
	Fraction&  operator+=(const Fraction&);
	Fraction& operator+=(const int32_t&);

	Fraction operator*(const Fraction&);
	Fraction operator*(const int32_t&);
	friend Fraction operator* (const int32_t&, const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator*=(const int32_t&);

	Fraction operator-(const Fraction&);
	Fraction operator-(const int32_t&);
	friend Fraction operator- (const int32_t&, const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator-=(const int32_t&);

	Fraction operator/(const Fraction&);
	Fraction operator/(const int32_t&);
	friend Fraction operator/ (const int32_t&, const Fraction&);
	Fraction& operator/=(const Fraction&);
	Fraction& operator/=(const int32_t&);

	//операторы сравнения
	bool operator>(const Fraction&);
	bool operator>(const int32_t&);
	friend bool operator>(const int32_t&, const Fraction&);

	bool operator>=(const Fraction&);
	bool operator>=(const int32_t&);
	friend bool operator>=(const int32_t&, const Fraction&);

	bool operator<(const Fraction&);
	bool operator<(const int32_t&);
	friend bool operator<(const int32_t&, const Fraction&);

	bool operator<=(const Fraction&);
	bool operator<=(const int32_t&);
	friend bool operator<=(const int32_t&, const Fraction&);

	bool operator==(const Fraction&);
	bool operator==(const int32_t&);
	friend bool operator==(const int32_t&, const Fraction&);

	bool operator!=(const Fraction&);
	bool operator!=(const int32_t&);
	friend bool operator!=(const int32_t&, const Fraction&);

	//инкременты и декременты
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int32_t);
	Fraction operator--(int32_t);


	//Сокращение дроби и нахождение для этого НОД
	void reduce(int32_t&, int32_t&);
	int32_t gcd(int32_t a, int32_t b);


	//вывода и ввода
	friend std::ostream& operator<<(std::ostream&, const Fraction&);
	friend std::istream& operator>>(std::istream&, Fraction&);

};


#endif

