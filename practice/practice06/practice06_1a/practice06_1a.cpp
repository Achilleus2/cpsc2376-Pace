#include <iostream>

class Person
{
private:
	int age;
public:
	int getAge()
	{
		return age;
	}
	void setAge(int age)
	{
		this->age = age;
	}
};



int main()
{
	Person p{ Person() };
	p.setAge(23);
	std::cout << p.getAge() << "\n";
}