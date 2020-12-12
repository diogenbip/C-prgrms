#include <iostream>
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
        os << "("<<a.vec[0];
        for (size_t t = 1; t < a.ssize; t++)
            os <<"," << a.vec[t];
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
    int GetEl(int i,int j)
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

template<class T>
void func(Vector<T>& a, SqMat<T>& b)
{
    T max;
    bool f = true;
    for (int i = 0; i < b.GetSize(); ++i)//главн и ниже
    {
        for (int j = 0; i + j < b.GetSize(); ++j)
        {
            if (f == true) { max = b.GetEl(i + j, j); f = false; }
            if(b.GetEl(i + j, j)>max)
                max= max = b.GetEl(i + j, j);
        }
        a.push_back(max);
        f = true;
    }

    for (int i = 1; i < b.GetSize(); ++i)//выше главн
    {
        for (int j = 0; i + j < b.GetSize(); ++j)
        {
            if (f == true) { max = b.GetEl(j,i+ j); f = false; }
            if (b.GetEl(j, i+j) > max)
                max = max = b.GetEl(j,i+ j);
        }
        a.push_back(max);
        f = true;
    }

}

int main()
{
    Vector<int> a;
    SqMat<int>b(3);
    cin >> b;
    func(a, b);
    cout << a;

}

