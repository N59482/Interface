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
				cout<<"driving "<<this->name<<endl;
			};	
	};

struct Fruct : public Interface
	{
		Fruct(string name)
			{
				this->name = name;
			};
		Fruct() : Fruct("some fruct")
			{};
		void use() override
		{
			cout<<"eat "<<this->name<<endl;
		};
		private:
			string name;
	};

struct User
	{
		string name;
		User(string name)
			{
				this->name = name;
			};
		User() : User("someone")
			{};
		void useObj(Interface & obj)
		{
			cout<<this->name<<" ";
			obj.use();
		}
	};

int main()
	{
		User mark("Mark");
		Car audi("audi 100");
		Car sc;
		Fruct banana("banana");
		Fruct sf;

		mark.useObj(audi);
		mark.useObj(sc);

		mark.useObj(banana);
		mark.useObj(sf);



		return 0;
	};