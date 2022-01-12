#include <iostream>
#include <string>

using namespace std;

class IUse
	{
		virtual void use() = 0;
		virtual void eat() = 0;
		virtual void kick() = 0;
	};

class Object : public IUse
	{
	    public:
		string name;
		void use() override
			{
				cout<<this->name<<" used\n";
			};
		void eat() override
			{
				cout<<this->name<<" is eaten\n";
			};
		void kick() override
			{
				cout<<this->name<<" is kicked\n";
			};
		Object(string name)
			{
				this->name = name;
			};
	    Object() :  Object("something")
	        {};
	};

class Car : public Object
	{
		void use() override
			{
				cout<<this->name<<" started\n";
			};
		void eat() override
			{
				cout<<"Eating a "<<this->name<<" isn't a good idea...\n";
			};
		void kick() override
			{
				cout<<"The "<<this->name<<" alarm went off\n";	
			};
	};

class User
	{
	    public:
		void use(Object obj) 
			{
				obj.use();
			};
		void eat(Object obj)
			{
				obj.eat();
			};
		void kick(Object obj)
			{
				obj.kick();
			};
	};

void Mark_test(const Object &o)
	{
		User mark;
		mark.use(o);
		mark.eat(o);
		mark.kick(o);
	};

int main()
	{
		Object thing;
		Mark_test(thing);
		Car audi;
		Mark_test(audi);
		
		return 0;
	};