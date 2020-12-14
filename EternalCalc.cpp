﻿
#define _CRT_SECURE_NO_WARNINGS 
/*Разработать программу, имитирующую работу функционального калькулятора, который позволяет выбрать с помощью меню какую-либо из известных ему
функций, затем предлагает ввести значение аргумента и, возможно, коэффициентов и после ввода выдает соответствующее значение функции.
В первой версии калькулятора «база знаний» содержит две функции:
1)экспоненту у = е^x;
2)линейную функцию у = ах + Ь.*/
#include <vector> 
#include<iostream> 
#include<string> 
using namespace std;

class Function
{
protected:
	float x;
public:
	virtual ~Function() {}
	void SetArg(double arg) { x = arg; }
	virtual void SetCoeff() = 0;
	virtual double GetVal() const = 0;
	virtual const std::string& GetName() const = 0;
};
double EXP(double x)
{
	float eps;
	int n = 1;
	double expf, p = 1;
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
/*класс для представления экспоненты*/
class Exp : public Function
{
private:
	std::string name; // мат. обозначение функции
public:
	Exp() :name("e ^ x") {};
	const std::string& GetName() const { return name; }
	void SetCoeff() {};

	double GetVal() const {
		return EXP(x);
	}

};
/*класс для представления функции a * x + b*/
class Line : public Function
{
public:
	Line() : name("a * x + b") {}
	const std::string& GetName() const { return name; }
	void SetCoeff();
	double GetVal() const { return (a * x + b); }
private:
	std::string name; // мат. обозначение функции
	double a;
	double b;
};
void Line::SetCoeff()
{
	cout << "Enter a = "; cin >> a;
	cout << "Enter b = "; cin >> b;
}

class Action
{
public:
	virtual~Action() {}
	virtual void Operate(Function*) = 0;
	virtual const std::string& GetName() const = 0;
};
class Calculation :public Action
{
private:
	std::string name;
public:
	Calculation() :name("Calculation") {}
	const std::string& GetName() const { return name; }
	void Operate(Function*);
};
void Calculation::Operate(Function* pFunc) {
	cout << "Calculation for function у = ";
	cout << pFunc->GetName() << endl;
	pFunc->SetCoeff();
	double x;
	cout << "Enter X = "; cin >> x;
	cin.get();
	pFunc->SetArg(x);
	cout << "y = " << pFunc->GetVal() << endl;
	cin.get();
}

class Tabulation : public Action
{
public:
	Tabulation() : name("Tabulation") {}
	const std::string& GetName() const { return name; }
	void Operate(Function*);
private:
	std::string name; // обозначение операции 
};
void Tabulation::Operate(Function* pF)
{
	cout << "TAB for func: " << pF->GetName() << endl;
	pF->SetCoeff();
	float x_beg, x_end, x_step;
	cout << "Enter x_beg = ";
	cin >> x_beg;
	cout << "Enter x_end = ";
	cin >> x_end;
	cout << "Enter x_step = ";
	cin >> x_step;
	cin.get();
	cout << "__________________" << endl;
	cout << " x\t\ty" << endl;
	cout << "__________________" << endl;
	float x = x_beg;
	while (x <= x_end)
	{
		pF->SetArg(x);
		std::cout << x << "\t\t" << pF->GetVal() << endl;
		x += x_step;
	}
}
class AnyAction : public Action
{
public:
	AnyAction() : name("Any action") {}
	const std::string& GetName() const { return name; }
	void Operate(Function*);
private:
	std::string name; // обозначение операции 
};
void AnyAction::Operate(Function*) {
	cout << "Your advertising might be here!" << endl;
}

class Menu
{
public:
	Menu(std::vector<Function*>, std::vector<Action*>);
	Function* SelectObject(int nItem) const;
	Action* SelectAction(Function*) const;
private:
	int SelectItem(int) const;
	std::vector<Function*> pObj;
	std::vector<Action*> pAct;
};
Menu::Menu(vector<Function*> _pObj, vector<Action*> _pAct) :pObj(_pObj), pAct(_pAct)
{
	pObj.push_back(0); // для выбора пункта 'Exit'
}
Function* Menu::SelectObject(int nItem) const
{
	int i;
	for (i = 0; i < nItem; i++)
	{ //После всех дейстий будет сделано следующее: 
		cout << i + 1 << ". "; //1. y=a*x+b 
		if (pObj[i] != NULL) //2. y=e^x 
			cout << pObj[i]->GetName() << endl; //Exit 
		else
			cout << "exit" << endl;
	}

	int k = SelectItem(nItem);
	return pObj[k - 1];
}

int Menu::SelectItem(int nItem) const
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

Action* Menu::SelectAction(Function* pObj) const
{
	int nItem = pAct.size();
	cout << "======================================\n";
	cout << "Select one of the following Actions:\n";
	for (int i = 0; i < nItem; ++i) {
		cout << i + 1 << ". ";
		cout << pAct[i]->GetName() << endl;
	}
	int item = SelectItem(nItem);
	return pAct[item - 1];
}


int main()
{
	setlocale(LC_ALL, "Russian");
	Line fjine;
	Exp f_exp;
	AnyAction any_action;
	Tabulation tabulation;
	Calculation calculation;
	int nItem = 2;//кол-во функций в меню
	Function* pObjs[] = { &f_exp, &fjine };
	vector<Function*> funcList(pObjs, pObjs + sizeof(pObjs) / sizeof(Function*));

	Action* pActs[] = { &calculation, &tabulation, &any_action };
	vector<Action*> operList(pActs, pActs + sizeof(pActs) / sizeof(Action*));

	Menu menu(funcList, operList);
	while (Function* pObj = menu.SelectObject(nItem))
	{
		Action* pAct = menu.SelectAction(pObj);
		pAct->Operate(pObj);
	}
	cout << "Bye!\n";
	return 0;
	system("pause");

}
