#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stdio.h>
using namespace std;



class employee  //КЛАСС СОТРУДНИК
{
public:

	char name[80];
	char dateofbirth[11];
	char dateofemployment[11];
	int salary;

	employee()
	{
		name[0] = '\0';
		dateofbirth[0] = '\0';
		dateofemployment[0] = '\0';
		salary = 0;
	}
	employee(const char* n, const char* dob, const char* doe, int s)
	{
		SetName(n);
		SetDateBir(dob);
		SetDateEmp(doe);
		SetSal(s);
	}

	~employee()
	{
		delete[]name;
		delete[]dateofbirth;
		delete[]dateofemployment;
		salary = 0;
	}



	//функции SET
	void SetName(const char* n) { strcpy(name, n); }
	void SetSal(const int sal) { salary = sal; }
	void SetDateBir(const char* dateBir) { strcpy(dateofbirth, dateBir); }
	void SetDateEmp(const char* dateEmpl) { strcpy(dateofemployment, dateEmpl); }

	void print()    //Печать сотрудника
	{
		{
			cout << name << "	|	" << dateofbirth << "	|	" << dateofemployment << "	|	" << salary << endl;
		}
	}
};


class Base //КЛАСС БАЗА сотрудников
{
	int N;
	employee* e;

public:


	int CreateBaz(Base A, const char* f_name, int& k)//создание и заполнение базы
	{
		FILE* f;

		if ((f = fopen(f_name, "r")) == NULL)
		{
			cout << "Cann't open";
			return -1;
		}
		else
		{
			int i = 0;
			while (!feof(f))
			{
				char n[80];
				char cpy[80];
				char dob[11];
				char doe[11];
				int s;
				fscanf(f, "%s", n);
				fscanf(f, "%s", cpy);
				strcat(n, " ");
				strcat(n, cpy);
				strcat(n, " ");
				fscanf(f, "%s", cpy);
				strcat(n, cpy);
				fscanf(f, "%s", dob);
				fscanf(f, "%s", doe);
				fscanf(f, "%d", &s);
				strcpy(e[i].name, n);
				strcpy(e[i].dateofbirth, dob);
				strcpy(e[i].dateofemployment, doe);
				e[i].salary = s;
				i++;
			}
			fclose(f);
			return 1;
		}
	}

	Base()
	{
		employee* e = NULL;
	}

	Base(int N)
	{
		e = new employee[N];
		this->N = N;
	}


	void RedactN(int i, const char* str)//	редактирует имя в базе
	{
		strcpy(e[i].name, str);
		e[i].name[strlen(str) + 1] = '\0';
	}
	void RedactBr(int i, const char* str)//	редактирует год рождения в базе
	{

		strcpy(e[i].dateofbirth, str);
		e[i].dateofbirth[strlen(str) + 1] = '\0';

	}
	void RedactYE(int i, const char* str)//	редактирует год устройства на работу в базе
	{

		strcpy(e[i].dateofemployment, str);
		e[i].dateofemployment[strlen(str) + 1] = '\0';

	}
	void RedactSr(int i, int s)//	редактирует зарплату
	{
		e[i].salary = s;
	}


	int Search(const char* str) //	Поиск по базе (возвращает индекс сотрудника)
	{
		for (int i = 0; i < N; i++)
		{
			if (strcmp(e[i].name, str) == 0)
			{
				return i;
			}
		}
	}
	int Add(const char* n, const char* br, const char* yw, int s) //добавление сотрудника в базу(возвращает индекс строки в которую добавили)
	{
		int i = 0;
		while (i < N)
		{
			if (e[i].name[0] == '\0' && e[i].dateofbirth[0] == '\0' && e[i].dateofemployment[0] == '\0' && e[i].salary == 0)
			{
				e[i].SetName(n);
				e[i].SetDateBir(br);
				e[i].SetDateEmp(yw);
				e[i].SetSal(s);
				break;
			}
			i++;
		}
		return i;

	}

	void Delete(int i)
	{
		e[i].name[0] = '\0';
		e[i].dateofbirth[0] = '\0';
		e[i].dateofemployment[0] = '\0';
		e[i].salary = 0;
		
	}
	void Print()
	{
		{
			puts("/=============================== Base of employee ===============================/" );
			for (int i = 0; i < N; i++)
			{
				e[i].print();//печать сотрудников
			}
			cout << endl;
		}
	};

	/*~Base()
	{
		delete[]e;
	}*/
};




int main()
{
	Base A(6);
	char nameT[] = "Текст.txt";
	int k = 0;
	if (A.CreateBaz(A, "Текст.txt", k) == 1)
	{
		puts("Base is created :");
		A.CreateBaz(A, "Текст.txt", k);
	}
	else puts("Base isn't created");
	// 2.Печать базы
	{A.Print(); }
	int z = A.Search("Aliev I M");
	printf("\n%d\n", z);
	A.RedactN(3, "Noname B I");
	A.RedactBr(3, "01.02.2003");
	A.RedactYE(3, "21.02.2020");
	A.RedactSr(3, 50000);
	A.Print();
	// 3. Добавление нового сотрудника
	A.Add("Davidov F I", "02.03.1990", "01.09.2019", 30000);
	A.Print();
	// 4. Удаление
	A.Delete(3);
	A.Print();
	system("pause");
}
