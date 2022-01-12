#include <iostream>
#include <string>

using namespace std;

// class IUse
// 	{
// 		virtual void use(Object obj) = 0;
// 	};

class Object
	{
		string name;
		public:
		void print()
			{
				cout<<this->name<<" used\n";
			};
		Object() :  name
			{
				this->name = "no_name";
			};
		Object(string name)
			{
				this->name = name;
			};
	};

class User //: public IUse
	{
	    public:
		void use(Object obj) //override
			{
				obj.print();
			};
	};

int main()
	{
		Object pen("pen");
		User mark;
		mark.use(pen);
		return 0;
	};