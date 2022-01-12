#include <iostream>
#include <string>

using namespace std;

struct IUse
	{
		virtual void use() = 0;
	};

struct Object1 : public IUse
	{
		void use() override
		{
			cout<<"Object1 used\n";
		};
	};

struct Object2 : public IUse
	{
		void use() override
		{
			cout<<"Object2 used\n";
		};
	};

struct User
	{
		void kick(IUse & obj)
		{
			obj.use();
		}
	};

int main()
	{
		User mark;
		Object1 o1;
		Object2 o2;

		mark.kick(o1);
		mark.kick(o2);

		return 0;
	};