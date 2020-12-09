// FloatMatrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

using namespace std;

class FloatMatrix
{
protected:
    int count_columns;
    int count_strings;

    float **matrix;
public:

    FloatMatrix(const int constructor_columns = 0, const int constructor_strings = 0)
    {
        if (constructor_columns > 0 || constructor_strings > 0)
        {
            count_columns = constructor_columns;
            count_strings = constructor_strings;

            matrix = new float*[count_strings];
            for (size_t i = 0; i < count_strings; i++)
                matrix[i] = new float[count_columns];

            for (size_t i = 0; i < count_strings; i++)
                for (size_t j = 0; j < count_columns; j++)
                    matrix[i][j] = 0;
        }
        else
        {
            count_columns = count_strings = 0;
            matrix = nullptr;
        }
    }

    FloatMatrix(const FloatMatrix& M)
    {
        count_columns = M.count_columns;
        count_strings = M.count_strings;

        matrix = new float* [count_strings];
        for (size_t i = 0; i < count_strings; i++)
            matrix[i] = new float[count_columns];

        for (size_t i = 0; i < count_strings; i++)
            for (size_t j = 0; j < count_columns; j++)
                matrix[i][j] = M.matrix[i][j];
    }
    void operator+=(const FloatMatrix& m)
    {
        for (size_t i = 0; i < count_strings; i++)
            for (size_t j = 0; j < count_columns; j++)
                matrix[i][j] += m.matrix[i][j];
    }
    void operator-=(const FloatMatrix& m)
    {
        for (size_t i = 0; i < count_strings; i++)
            for (size_t j = 0; j < count_columns; j++)
                matrix[i][j] -= m.matrix[i][j];
    }
    FloatMatrix operator*(const FloatMatrix& m)
    {
        FloatMatrix c(m.count_columns, count_strings);
        for (size_t i = 0; i < count_strings; i++)
        {
            for (size_t j = 0; j < m.count_columns; j++)
            {
                c.matrix[i][j] = 0;
                for (size_t k = 0; k < count_columns; k++)
                {
                    c.matrix[i][j] += matrix[i][k]*m.matrix[k][j];
                }
            }
        }
        return c;
    }
   
    void operator=(const FloatMatrix& M)
    {
        count_columns = M.count_columns;
        count_strings = M.count_strings;

        matrix = new float* [count_strings];
        for (size_t i = 0; i < count_strings; i++)
            matrix[i] = new float[count_columns];

        for (size_t i = 0; i < count_strings; i++)
            for (size_t j = 0; j < count_columns; j++)
                matrix[i][j] = M.matrix[i][j];
    }
    bool operator==(const FloatMatrix& m)
    {
        for (size_t i = 0; i < count_strings; i++)
            for (size_t j = 0; j < count_columns; j++)
                if (matrix[i][j] != m.matrix[i][j])
                {
                    return false;
                }
        return true;

    }
    bool operator!=(const FloatMatrix& m)
    {
        for (size_t i = 0; i < count_strings; i++)
            for (size_t j = 0; j < count_columns; j++)
                if (matrix[i][j] != m.matrix[i][j])
                {
                    return true;
                } 
        return false;


    }
    friend istream& operator>>(istream& is, const FloatMatrix& m)
    {
        cout << "Enter elements of matrix" << endl;
        for (size_t i = 0; i < m.count_strings; i++)
            for (size_t j = 0; j < m.count_columns; j++)
                is >> m.matrix[i][j];
        cout << "the matrix was filled" << endl;
        return is;
        
    }
    friend ostream& operator<<(ostream& os, const FloatMatrix& m)
    {
        for (size_t i = 0; i < m.count_strings; i++)
        {
            
            for (size_t j = 0; j < m.count_columns; j++)
                os << m.matrix[i][j] << "  ";
            os << "\t\n";
        }
        return os;

    }
    void RandM();
    void PowM(const int n);


    ~FloatMatrix()
    {
        
            for (int i = 0; i < count_strings; i++)
                delete[]matrix[i];
            delete[]matrix;
    }

};




void FloatMatrix::RandM()
{
    for (size_t i = 0; i < count_strings; i++)
        for (size_t j = 0; j < count_columns; j++)
            matrix[i][j] = rand() % 10;
}

void FloatMatrix::PowM(const int n) {
    if (count_columns != count_strings)
    {
        cout << "I'can't do it" << endl;
        return;
    }
    else
    {
        FloatMatrix c = *this;
        for (int i = 1; i < n; i++)
        {
            *this = *this * c;
        }
    }
   
    
    
}

class SquareMatrix : public FloatMatrix {
    int size;
public:

    SquareMatrix(const int _size = 0)
    {
        size = _size;
        count_columns = size;
        count_strings = size;
        matrix = new float* [size];
        for (int i = 0; i < size; i++)
            matrix[i] = new float[size];
    }
    int GetSize()
    {
        return size;
    }
    float GetMinor(int i, int j)
    {
        SquareMatrix b(size - 1);
        int di=0;
        int dj = 0;
        for (int ki = 0; ki < size-1; ki++) {
            if (ki == i)
                di = 1;
            dj = 0;
            for (int kj = 0; kj < size - 1; kj++) {
                if (kj == j)dj = 1;
                b.matrix[ki][kj] = matrix[ki + di][kj + dj];
            }
        }
        return b.det();


    }
    void Transp()
    {
        SquareMatrix Res(this->count_columns);
        Res.count_strings= this->count_columns;
        Res.count_columns =this->count_strings;
        float s;
        for (int i = 0; i < this->count_strings; i++)
            for (int j = 0; j < this->count_columns; j++)
            {
                Res.matrix[i][j] = matrix[j][i];
            }
        *this = Res;
    }
    float det()
    {
        float d = 0;
        
        int k = 1;
        if (size == 1)
        { return matrix[0][0];}
        else if (size == 2)
        {
            return  matrix[0][0] * matrix[1][1] -(matrix[1][0] * matrix[0][1]);
        }
        else if (size > 2)
        {
            for (int i = 0; i < size; i++)
            {
                d = d + k * matrix[i][0] * this->GetMinor(i,0);
                k = -k;
            }
            return d;
        }
            

    }
};

int main()
{
    //FloatMatrix A(2,2), B(3,2),C(2,2);

    SquareMatrix K(3);
    cin >> K;
    cout << K.det()<<endl;
    K.Transp();
    cout << K;
    /*cout << B << endl;

    A = A * B;
    cout << A << endl;
    A.PowM(2);*/

  //  if (A != C)
   //     cout << "a!=c" << endl;
}

