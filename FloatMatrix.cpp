// FloatMatrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

using namespace std;

class FloatMatrix
{
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
        FloatMatrix c(m.count_columns,m.count_strings);
        for (size_t i = 0; i < count_strings; i++)
        {
            for (size_t j = 0; j < count_columns; j++)
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
                if (matrix[i][j] == m.matrix[i][j])
                {
                    return true;
                }
                else
                {
                    return false;
                }
                   

    }
    bool operator!=(const FloatMatrix& m)
    {
        for (size_t i = 0; i < count_strings; i++)
            for (size_t j = 0; j < count_columns; j++)
                if (matrix[i][j] != m.matrix[i][j])
                {
                    return true;
                }
                else
                {
                    return false;
                }


    }
    void Enter();
    void Print();
    void RandM();
    void PowM(const int n,FloatMatrix &m);


    ~FloatMatrix()
    {
        if (count_strings > 0)
        {
            for (int i = 0; i < count_columns; i++)
                delete[]matrix[i];
        }
        if (count_columns > 0)
            delete[]matrix;
    }

};

void FloatMatrix::Enter()
{
    cout << "Enter elements of matrix" << endl;
    for (size_t i = 0; i < count_strings; i++)
        for (size_t j = 0; j < count_columns; j++)
            cin >> matrix[i][j];
    cout << "the matrix was filled" << endl;
}

void FloatMatrix::Print()
{
    for (size_t i = 0; i < count_strings; i++)
    {
        for (size_t j = 0; j < count_columns; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << "---------------------" << endl << endl;
       
}

void FloatMatrix::RandM()
{
    for (size_t i = 0; i < count_strings; i++)
        for (size_t j = 0; j < count_columns; j++)
            matrix[i][j] = rand() % 10;
}

void FloatMatrix::PowM(const int n,FloatMatrix &m) {
    FloatMatrix c=m;

        for (int i = 1; i < n; i++)
        {
            m = m * c;
        }
    
    
}

int main()
{
    FloatMatrix A(2,2), B(2,2),C(2,2);

    A.RandM();
    //B.Enter();
    A.Print();
    B.Print();
    A.PowM(5,A);
    A.Print();
    if (A != C)
        cout << "a!=c" << endl;
}

