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
	//������������
	//Fraction();
	Fraction(int32_t);
	Fraction(int32_t = 0, int32_t = 1);

	Fraction& operator=(const Fraction&);

	//������ � ��������� ��� �����������
	int32_t& operator[](int index);

	//����������
	~Fraction();

	//��������������
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

	//��������� ���������
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

	//���������� � ����������
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int32_t);
	Fraction operator--(int32_t);


	//���������� ����� � ���������� ��� ����� ���
	void reduce(int32_t&, int32_t&);
	int32_t gcd(int32_t a, int32_t b);


	//������ � �����
	friend std::ostream& operator<<(std::ostream&, const Fraction&);
	friend std::istream& operator>>(std::istream&, Fraction&);

};


#endif

