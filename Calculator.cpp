﻿#define _CRT_SECURE_NO_WARNINGS 

#include<iostream> 
#include<string> 


using namespace std;

class Function
{
protected:
	float x;
	string name;
public:
	~Function() {}
	virtual const string& GetName() const = 0;
	virtual void Calculate() = 0;
};
/*класс для представления экспоненты*/
class Exponenta :public Function
{
public:
	Exponenta()
	{
		name = "e^x";
	}
	const string& GetName() const { return name; }
	void Calculate();
};
float EXP(float x)
{
	float eps;
	int n = 1;
	float expf, p = 1;
	cout << "Введите заданую точность = ";
	cin >> eps;
	expf = 1.0;
	while (abs(p) >= eps)
	{
		p = p * x / n;
		expf = expf + p;

		n++;
	}
	return expf;
}
void Exponenta::Calculate()
{
	cout << "Вычисление функции y = " << name << endl;
	cout << "Введите x = ";
	cin >> x;
	cout << "y = " << EXP(x) << endl;
}
/*класс для представления многочлена*/
class Polynom :public Function
{
protected:
	float* step;
	float* k;
	int size;
public:
	Polynom()
	{
		step = NULL;
		k = NULL;
		size = 0;
		name = "Pn(x)";
	}
	const string& GetName() const { return name; }
	void Calculate();
};
void Polynom::Calculate()
{
	cout << "Введите x : ";
	cin >> x;
	cout << "Введите размер многочлена: ";
	cin >> size;
	k = new float[size];
	step = new float[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Введите коэффициент при x" << i << " : ";
		cin >> k[i];
		cout << "Введите степень при " << k[i] << "x^ : ";
		cin >> step[i];
		cout << endl;
	}
	float P = 0;
	for (int i = 0; i < size; i++)
	{
		P = P + k[i] * pow(x, step[i]);
	}
	cout << "P" << size << "(x) = " << P << endl;
}
/*класс для представления функции a * x + b*/
class Line : public Function
{
protected:
	float a, b;
public:
	Line()
	{
		name = "a * x + b";
	}
	const string& GetName() const { return name; }
	void Calculate();
};
void Line::Calculate()
{
	//cout « "Вычисление функции y = " « name « endl; 
	cout << "Введите a, b, x" << endl;
	cin >> a >> b >> x;
	cout << "y = " << (a * x + b) << endl;
}
class Menu
{
private:
	Function** pObject;
	int nItem;
public:
	Menu(int m, Function** adr)/*Конструктор*/
	{
		nItem = m + 1;
		pObject = new Function * [nItem];
		for (int i = 0; i < m; i++)
			pObject[i] = adr[i];
		pObject[m] = NULL;
	}
	Function* SelectObject() /*Выбрать обьект*/
	{
		int i;
		for (i = 0; i < nItem; i++)
		{ //После всех дейстий будет сделано следующее: 
			cout << i + 1 << ". "; //1. y=a*x+b 
			if (pObject[i] != NULL) //2. y=e^x 
				cout << pObject[i]->GetName() << endl; //Exit 
			else
				cout << "exit" << endl;
		}

		int k = SelectItem();
		return pObject[k - 1];
	}
	int SelectItem() const
	{
		cout << "Выберите пункт меню." << endl;

		int punct;

		while (true)
		{
			cin >> punct;
			if (punct > 0 && punct <= nItem)
				return punct;
			else
				cout << "Ошибка. Поторите ввод." << endl;
		}
	}

};
int main()
{
	setlocale(LC_ALL, "Russian");
	Line f1;
	Exponenta f2;
	Polynom f3;
	/*Формируем массив адресов*/
	Function* adrObject[] = { &f1, &f2, &f3 };

	int size = sizeof(adrObject) / sizeof(Function*);
	Menu mn(size, adrObject);
	Function* p;
	while (p = mn.SelectObject())
		p->Calculate();
	system("pause");
	return 0;
}