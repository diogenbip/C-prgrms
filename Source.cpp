#include <iostream>
#include <vector>

using namespace std;
//класс обработки ошибок
class Ex
{
	int num;
public:
	Ex(int k) { num = k; }
	void Check()
	{
		if (num == 1) { cout << "false count"; }
		else if (num == 2) { cout << "false k"; }
	}
};
//заполнение вектора
void Fill(vector <int>& a)
{
	int count=0;
	cout << "Eneter count: ";
	cin >> count;
	if (count > 0)
	{
		for (int i = 1; i <= count; i++)
		{
			a.push_back(i);
			cout << i << " ";
		}
		cout << endl;
	}
	else
	{
		throw Ex(1);
	}
}
//алгоритм считалочка
void _Alg_Iosifa(vector <int>& a)
{
	int k = 0;

	int *del_mass = new int[a.size() - 1];

	cout << "Eneter k: ";
	cin >> k;
	if (k <= 0)
		throw Ex(2);

	auto it = a.begin();
	int n = 0;
	for (int i = 1; a.size() != 1;)
	{
		if (it == a.end())
		{
			it = a.begin();
		}
		if (i == k)
		{
			del_mass[n] = *it;
			n++;
			it = a.erase(it);
			int curr = 0;
			for (auto it1 = a.begin(); it1 != a.end(); it1++)
			{
				if (it == a.end())
				{
					curr = *a.begin();
					if (*it1 == curr)
						cout << "[" << *it1 << "]" << " ";
					else
						cout << *it1 << " ";
				}
				else
				{
					if (*it1 == *it)
						cout << "[" << *it1 << "]" << " ";
					else
						cout << *it1 << " ";
				}	
			}

			cout << "\n";
			i = 1;
		}
		else
		{
			it++;
			i++;
		}

	}
	it = a.begin();
	cout << "Last: " << *it;
}


//главная функция
int main()
{
	vector <int> a;
	Fill(a);
	_Alg_Iosifa(a);
}