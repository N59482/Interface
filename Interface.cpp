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
				cout<<"Object constructor with param\n";
			};
	    Object() :  Object("something")
	        {
	            cout<<"Object constructor\n";
	        };
	};

class Car : public Object
	{
	    public:
	    Car(string n)
	    {
	        this->name = n;
	    };
	    Car() : Car("car")
	    {
	      cout<<"Car constructor\n";  
	    };
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

class Fruct : public IUse
    {
        public:
        string name;
        Fruct(strint name)
            {
                this->name = name;  
            };
        Fruct() : Fruct("some fruct")
            {
                cout<<"Fruct constructor\n";
            };
        void eat() override
        	{
				cout<<this->name<<" is tasty\n";
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
		Object thing("thing");
		Mark_test(thing);
		Car audi("AUDI");
		Mark_test(audi);
		User Ann;
		Fruct apple("apple");
		Ann.kick(audi);
		Ann.eat(apple);
		return 0;
	};