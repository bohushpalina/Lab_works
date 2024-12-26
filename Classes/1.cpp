#include <iostream>
#include <string>

class Animal {
private:
	std::string name;
	std::string sound;
public:
	//Animal() : name("no name"), sound("no sound") //конструктор по умолчанию
	//{ }

	Animal() : name ("no name"), sound("no sound")
	{ }

	Animal(std::string a, std::string b) : name(a), sound(b)
	{ }
	void setname(std::string set_name, std::string set_sound = "no sound")
	{
		name = set_name;
		sound = set_sound;
	}
	void getinfo(std::string& a, std::string& b)
	{
		a = name;
		b = sound;
	}
};

int main() {
	Animal first;
	std::string a, b, c;
	std::cin >> a >> b;
	first.setname(a, b);
	std::string q, w, e, r;
	Animal second("mya", "pupupu");
	first.getinfo(q, w);
	second.getinfo(e, r);
	std::cout << "first: name " << q << "; sound: " << w << '\n';
	std::cout << "second: name " << e << "; sound: " << r << '\n';


	return 0;
}