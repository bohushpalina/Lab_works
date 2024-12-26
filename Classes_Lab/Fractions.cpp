#include "Fractions.h"

//Fraction::Fraction() : n{ 0 }, d{ 1 }
//{}

Fraction::Fraction(int32_t a)
{
	n = a;
	d = 1;
}

Fraction::Fraction(int32_t a, int32_t b)
{
	if (b == 0)
	{
		throw std::invalid_argument("The deminator cannot be zero!");
	}
		reduce(a, b);
		this->n = a;
		this->d = b;
}

Fraction Fraction::operator+(const Fraction& rhs)
{
	Fraction temp = *this;
	temp += rhs;
	return temp;
}

Fraction Fraction::operator+(const int32_t& rhs)
{
	Fraction temp = *this;
	temp += rhs;
	return temp;
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
	n = rhs.d * n + rhs.n * d;
	d = rhs.d * d;
	reduce(n, d);
	return *this;
}

Fraction& Fraction::operator+=(const int32_t& rhs)
{
	n = n + rhs * d;
	reduce(n, d);
	return *this;
}

//clone
Fraction Fraction::operator*(const Fraction& rhs)
{
	Fraction temp = *this;
	temp *= rhs;
	return temp;
}

Fraction Fraction::operator*(const int32_t& rhs)
{
	Fraction temp = *this;
	temp *= rhs;
	return temp;
}

Fraction& Fraction::operator*=(const Fraction& rhs)
{
	n = n * rhs.n;
	d = d * rhs.d;
	reduce(n, d);
	return *this;
}

Fraction& Fraction::operator*=(const int32_t& rhs)
{
	n = n * rhs;
	reduce(n, d);
	return *this;
}

Fraction Fraction::operator-(const Fraction& rhs)
{
	Fraction temp = *this;
	temp -= rhs;
	return temp;
}

Fraction Fraction::operator-(const int32_t& rhs)
{
	Fraction temp = *this;
	temp -= rhs;
	return temp;
}

Fraction& Fraction::operator-=(const Fraction& a)
{
	n = a.d * n - a.n * d;
	d = a.d * d;
	reduce(n, d);
	return *this;
}

Fraction& Fraction::operator-=(const int32_t& rhs)
{
	n = n - rhs * d;
	reduce(n, d);
	return *this;
}

Fraction Fraction::operator/(const Fraction& rhs)//0
{
	Fraction temp = *this;
	temp /= rhs;
	return temp;
}

Fraction Fraction::operator/(const int32_t& rhs)
{
	Fraction temp = *this;
	temp /= rhs;
	return temp;
}

Fraction& Fraction::operator/=(const Fraction& rhs)
{
	if (rhs.n == 0)
	{
		throw std::invalid_argument("Can't be zero");
	}
	n = n * rhs.d;
	d = d * rhs.n;
	reduce(n, d);
	return *this;
}

Fraction& Fraction::operator/=(const int32_t& rhs)
{
	if (rhs == 0)
	{
		throw std::invalid_argument("Can't be zero");
	}
	d = d * rhs;
	reduce(n, d);
	return *this;
}

bool Fraction::operator>(const Fraction& rhs)
{
	return ((rhs.d * n) / (d * rhs.d)) > ((rhs.n * d) / (rhs.d * d));
}

bool Fraction::operator>(const int32_t& rhs)
{
	return n > rhs * d;
}

bool Fraction::operator>=(const Fraction& rhs)
{
	return ((rhs.d * n) / (d * rhs.d)) >= ((rhs.n * d) / (rhs.d * d));
}

bool Fraction::operator>=(const int32_t& rhs)
{
	return n >= rhs * d;
}

bool Fraction::operator<(const Fraction& rhs)
{
	return !(*this > rhs);
}

bool Fraction::operator<(const int32_t& rhs)
{
	return !(*this > rhs);
}

bool Fraction::operator<=(const Fraction& rhs)
{
	return !(*this >= rhs);
}

bool Fraction::operator<=(const int32_t& rhs)
{
	return !(*this >= rhs);
}

bool Fraction::operator==(const Fraction& rhs)
{
	return ((rhs.d * n) / (d * rhs.d)) == ((rhs.n * d) / (rhs.d * d));
}

bool Fraction::operator==(const int32_t& rhs)
{
	return n == rhs * d;
}

bool Fraction::operator!=(const Fraction& rhs)
{
	return !(*this == rhs);
}

bool Fraction::operator!=(const int32_t& rhs)
{
	return !(*this == rhs);
}

Fraction& Fraction::operator++()
{
	n += d;
	reduce(n, d);
	return *this;
}

Fraction& Fraction::operator--()
{
	n -= d;
	reduce(n, d);
	return *this;
}

Fraction Fraction::operator++(int32_t)
{
	Fraction temp{*this };
	n += d;
	reduce(n, d);
	return temp;
}

Fraction Fraction::operator--(int32_t)
{
	Fraction temp = *this;
	n -= d;
	reduce(n, d);
	return temp;
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
	if (this != &rhs)
	{
		this->n = rhs.n;
		this->d = rhs.d;
	}
	return *this;
}

int32_t& Fraction::operator[](int index)
{
	switch (index)
	{
	case 0:
		return n;
	case 1:
		return d;
	default:
		throw std::invalid_argument("Wrong index");
	}
}

Fraction::~Fraction()
{ }

void Fraction::reduce(int32_t& a, int32_t& b)
{
	int32_t del = gcd(a, b);
	a /= del;
	b /= del;
	if (b < 0)
	{
		a = -a;
		b = -b;
	}
}


Fraction operator+(const int32_t& lhs, const Fraction& rhs)
{
	return Fraction(rhs.n + lhs * rhs.d, rhs.d);
}

Fraction operator-(const int32_t& lhs, const Fraction& rhs)
{
	return Fraction(rhs.n - lhs * rhs.d, rhs.d);
}

Fraction operator*(const int32_t& lhs, const Fraction& rhs)
{
	return Fraction(rhs.n * lhs, rhs.d);
}

Fraction operator/(const int32_t& lhs, const Fraction& rhs)
{
	return Fraction(rhs.n, rhs.d * lhs);
}

bool operator>(const int32_t& lhs, const Fraction& rhs)
{
	return rhs.n < lhs * rhs.d;
}

bool operator>=(const int32_t& lhs, const Fraction& rhs)
{
	return rhs.n <= lhs * rhs.d;
}

bool operator<(const int32_t& lhs, const Fraction& rhs)
{
	return !(lhs > rhs);
}

bool operator<=(const int32_t& lhs, const Fraction& rhs)
{
	return !(lhs >= rhs.d);
}

bool operator==(const int32_t& lhs, const Fraction& rhs)
{
	return rhs.n == lhs * rhs.d;
}

bool operator!=(const int32_t& lhs, const Fraction& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& out, const Fraction& a)
{
	if (a.d == 1)
		out << a.n;
	else if (a.d == -1)
		out << -a.n;
	else
		out << a.n << '/' << a.d;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& a)
{
	int32_t nn, dd;
	std::cout << "¬ведите числитель: ";
	in >> nn;
	std::cout << "¬ведите знаменатель: ";
	in >> dd;
	Fraction b(nn, dd);
	a = b;
	return in;
}

int32_t Fraction::gcd(int32_t a, int32_t b)
{
	int32_t temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}