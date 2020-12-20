#include <iostream>


//class exeption floatmatrix
//

using namespace std;
template<class T>
class Vector
{
	T* vec;
	int ssize;
public:
	Vector(int s_ssize = 0)
	{
		if (s_ssize > 0)
		{
			ssize = s_ssize;
			vec = new T[ssize];
		}
		else
		{
			ssize = 0;
			vec = nullptr;
		}
	}
	 Vector<T>& operator = (const Vector<T>& v)
	{
		delete[] vec;
		ssize = v.ssize;
		vec = new T[ssize];
		for (int i = 0; i < ssize; i++)
			vec[i] = v.vec[i];
		return *this;
	}
	void prisv(T dta,int indx)
	{
		vec[indx] = dta;
	}
	void push_back(T dta)
	{
		T* _result = new T[++this->ssize];

		for (int index = 0; index < this->ssize; index++)
		{
			if (index != this->ssize - 1)
			{
				_result[index] = this->vec[index];
			}
			else
			{
				_result[index] = dta;
				break;
			}
		}
		delete[] this->vec;
		this->vec = _result;
	}
	friend ostream& operator<<(ostream& os, const Vector<T>& a)
	{
		os << "(" << a.vec[0];
		for (size_t t = 1; t < a.ssize; t++)
			os << "," << a.vec[t];
		os << ")";
		return os;

	}
	~Vector()
	{
		delete[]vec;
	}
};

template <class T>
class SqMat
{
	T** matr;
	int size;
public:

	SqMat(int s_size = 0)
	{
		if (s_size > 0)
		{
			size = s_size;
			matr = new T * [size];
			for (size_t i = 0; i < size; i++)
				matr[i] = new T[size];

			for (size_t i = 0; i < size; i++)
				for (size_t j = 0; j < size; j++)
					matr[i][j] = 0;
		}
		else
		{
			size = s_size;
			matr = nullptr;
		}
	}
	T GetEl(int i, int j)
	{
		return matr[i][j];
	}
	~SqMat()
	{
		for (int i = 0; i < size; i++)
			delete[]matr[i];
		delete[]matr;
	}
	int GetSize()
	{
		return size;
	}


	friend istream& operator>>(istream& is, const SqMat<T>& m)
	{
		cout << "Enter elements of matrix" << endl;
		for (size_t i = 0; i < m.size; i++)
			for (size_t j = 0; j < m.size; j++)
				is >> m.matr[i][j];
		cout << "the matrix was filled" << endl;
		return is;

	}
};
/*
* Vector tmp(b.GetSize*2-1);
*
for(int i=b.GetSize()-1,k=1;i>=0&&k<b.GetSize();--i;++k)

*/
template<class T>
void func(Vector<T>& a, SqMat<T>& b)
{
	T max1;
	T max2;
	bool f1 = true,f2=true;
	int indx1 = 0,indx2=b.GetSize()+1;
	for (int i = 0; i < (b.GetSize() * 2 - 1); i++)
		a.push_back(0);

	

	for (int i = b.GetSize() - 1, k = 1; i >= 0 || k < b.GetSize(); --i, ++k)
	{
		for (int j = 0; i + j < b.GetSize(); ++j)
		{
			if (f1 == true) { max1 = b.GetEl(i + j, j); f1 = false; }
			if (b.GetEl(i + j, j) > max1)
				max1 = max1 = b.GetEl(i + j, j);
			if (f2 == true) { max2 = b.GetEl(j, i + j); f2 = false; }
			if (b.GetEl(j, i + j) > max2)
				max2 = max2 = b.GetEl(j, i + j);
		}
		a.prisv(max1, indx1);
		indx1++;
		a.prisv(max2, indx2);
		indx2--;
		f1 = true;
		f2 = true;
	}
	//for (int i = b.GetSize() - 1; i >= 0; --i)//????? ? ????
	//{
	//	for (int j = 0; i + j < b.GetSize(); ++j)
	//	{
	//		
	//	}
	//	a.push_back(max);
	//	f = true;
	//}

	//for (int i = 1; i < b.GetSize(); ++i)//???? ?????
	//{
	//	for (int j = 0; i + j < b.GetSize(); ++j)
	//	{
	//		
	//	}
	//	a.push_back(max);
	//	f = true;
	//}

}


int main()
{

	Vector<float> a;
	SqMat<float>b(3);
	cin >> b;
	func(a, b);
	cout << a;

}