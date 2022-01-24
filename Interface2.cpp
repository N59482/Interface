#include <iostream>
#include <string>

using namespace std;

struct Interface
	{
		virtual void use() = 0;
		virtual void kick() = 0;
	};

struct Object : public Interface
    {
       	protected:
		string name;
		public:
		Object(string name)
			{
				// cout<<"constructor Object(string name)\n";
				this->name = name;
			};
		Object() : Object("Something")
			{
				// cout<<"constructor Object()\n";
			};
    };

struct Car : public Object
	{
		Car(string name) : Object(name)
			{
				// cout<<"constructor Car(string name)\n";
			};
		Car() : Object("some car")
			{
				// cout<<"constructor Car()\n";
			};

		void use() override
			{	
				cout<<"driving "<<this->name<<endl;
			};	
		void kick() override
			{	
				cout<<"*Alarm sound*\n";
			};
	};

struct Audi : public Car
    {
		Audi(string name) : Car(name)
			{
	// 			cout<<"constructor Audi(string name)\n";
			};
		Audi() : Car("Audi")
			{
	// 			cout<<"constructor Audi()\n";
			};
	};

struct Fruct : public Object
	{
		Fruct(string name) : Object (name)
			{
				// cout<<"constructor Fruct(string name)\n";
			};
		Fruct() : Object("some fruct")
			{
				// cout<<"constructor Fruct()\n";
			};
		void use() override
			{
				cout<<"eat "<<this->name<<endl;
			};
		void kick() override
			{	
				cout<<this->name<<" flew far away\n";
			};
	};

struct Banana : public Fruct
	{
		Banana(string name) : Fruct(name) 
			{
	// 			cout<<"constructor Banana(string name)\n";
			};
		Banana() : Fruct("Banana")
			{
	// 			cout<<"constructor Banana()\n";
			};
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
		void kick(Interface & obj)
			{
				obj.kick();
			}
	};

int main()
	{
		User mark("Mark");
		Audi a("a100");
		Audi a1;

		mark.useObj(a);
		mark.useObj(a1);

		Banana b("BIG banana");
		Banana b1;

		mark.useObj(b);
		mark.useObj(b1);

		User Kira("Kira");
		Kira.kick(a);
		Kira.kick(a1);
		Kira.kick(b);
		Kira.kick(b1);
		return 0;
	};