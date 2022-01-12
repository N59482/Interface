#include <iostream>
#include <string>

using namespace std;

struct Interface
	{
		virtual void use() = 0;
	};

struct Car : public Interface
	{
		string name;
		Car(string name)
			{
				this->name = name;
			};
		Car() : Car("some car")
			{};

		void use() override
			{	
				cout<<"Driving "<<this->name<<endl;
			};	
	};

struct Fruct : public Interface
	{
		string name;
		Fruct(string name)
			{
				this->name = name;
			};
		Fruct() : Fruct("some fruct")
			{};
		void use() override
		{
			cout<<this->name<<" eaten\n";
		};
	};

struct User
	{
		void useObj(Interface & obj)
		{
			obj.use();
		}
	};

int main()
	{
		User mark;
		Car audi("audi 100");
		Car sc;
		Fruct sf;
		Fruct banana("banana");

		mark.useObj(audi);
		mark.useObj(sc);

		mark.useObj(banana);
		mark.useObj(sf);

		return 0;
	};