#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

using namespace std;

class exep
{
	int n;
public:
	exep(){}
	exep(int k) { n = k; }
	string getErr() { if (n == 1) { cout << "err"; } }
};

class Auto
{
protected:
	string str;

public:
	Auto() { str = ""; }
	Auto(string str) { this->str = str; }
	~Auto() {}
};

class constant_MB : public Auto
{
	typedef void (constant_MB::* fptr)(char);
	int rch;
	int rp;
	int rs;
	int rz;
	fptr func;
public:
	constant_MB()
	{
		func = &constant_MB::q0;
		rch = 0;//reg num
		rp = 0;//reg order
		rs = 0;//reg count
		rz = 1;//reg sign
	}
	constant_MB(string str)
	{
		this->str = str;
		func = &constant_MB::q0;
	}
	void q0(char ch)
	{
		if (isdigit(ch))//1a
		{
			rch = ch - '0';
			func = &constant_MB::_1;
		}
		else if(ch=='.')
		{
			func = &constant_MB::_7;
		}
		else
		{
			throw exep(1);
		}
	}

	void _1(char ch) {

		if (isdigit(ch))//1b
		{
			rch *= 10;
			rch = rch+ (ch - '0');
			func = &constant_MB::_1;
		}
		else if (ch == 'E')//4a
		{
			rs = 0;
			func = &constant_MB::_4;
		}
		else if (ch == '.')//23c
		{
			rs = 0;
			func = &constant_MB::_23;
		}
		else if (ch == '\0')//da1
		{
			rp = 0;
			//end?
		}
		else
		{
			throw exep(1);
		}
	}
	void _23(char ch) {
		if (isdigit(ch))//23a
		{
			rs++;
			rch *= 10;
			rch =rch+ (ch - '0');
			func = &constant_MB::_23;
		}
		else if (ch == 'E')//4b
		{
			func = &constant_MB::_4;
		}
		else if (ch == '\0')//da2
		{
			rp = rs * -1;
		}
		else
		{
			throw exep(1);
		}
	}
	void _4(char ch) {

		if (isdigit(ch))//6a
		{
			rz = 1;
			rp = ch - '0';
			func = &constant_MB::_6;
		}
		else if (ch == '+' || ch == '-')//5
		{
			ch == '+' ? rz = 1 : rz = -1;
			func = &constant_MB::_5;
		}
		else
		{
			throw exep(-1);
		}
	}
	void _5(char ch) {
		if (isdigit(ch))//6b
		{
			rp = ch - '0';
			func = &constant_MB::_6;
		}
		else
		{
			throw exep(1);
		}
	}
	void _6(char ch) {
		if (isdigit(ch))//6c
		{
			rp *= 10;
			rp =rp+ (ch - '0');
			func = &constant_MB::_6;
		}
		else if (ch == '\0')//da3
		{
			rp *= rz;
			rp -= rs;
		}
		else
		{
			throw exep(1);
		}
	}
	void _7(char ch) {
		if (isdigit(ch))//23b
		{
			rs = 1;
			rch = ch - '0';
			func = &constant_MB::_23;
		}
		else
		{
			throw exep(1);
		}
	}
	void parce()
	{
		for (int i = 0; i < str.size() + 1; i++)
			(this->*func)(str[i]);
	}

	friend std::ostream &operator <<(std::ostream &out,const constant_MB &a)
	{
		out << a.rch<<"*"<<10<<"^"<<a.rp;
		return out;
	}

};
	
	


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file("1.txt");
	
	while (!file.eof())
	{
		string str;
		getline(file, str);
		constant_MB A(str);
		A.parce();
		cout << A<<endl;
	}

	return 0;
}