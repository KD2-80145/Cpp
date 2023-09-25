#include <iostream>
using namespace std;

class Matrix
{
private:
    int **arr;
    int length;

    void create_Matrix(int length)
    {
        this->length = length;
        this->arr = new int *[length];

        for (int i = 0; i < length; i++)
        {
            arr[i] = new int[length];
        }
    }

public:
    Matrix()
    {
        // cout << "Matrix Object Created." << endl;
    }
    Matrix(int length)
    {

        this->create_Matrix(length);
    }

    void accept()
    {
        int length;
        cout << "Enter Rows of Array: ";
        cin >> length;

        this->create_Matrix(length);

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                cout << "Enter for "
                     << "arr[" << i << "][" << j << "]"
                     << " Column." << endl;
                cin >> arr[i][j];
            }
        }
    }
    void print()
    {
        for (int i = 0; i < this->length; i++)
        {
            for (int j = 0; j < this->length; j++)
            {
                cout << *(*(this->arr + i) + j) << " ";
            }
            cout << endl;
        }
    }

    int **getArray()
    {
        return this->arr;
    }

    int getLength()
    {
        return this->length;
    }
};

namespace matrix_operation
{
    Matrix add(Matrix *m1, Matrix *m2)
    {

        Matrix ans(m1->getLength());
        int **ans_arr = ans.getArray();

        for (int i = 0; i < m1->getLength(); i++)
        {
            for (int j = 0; j < m1->getLength(); j++)
            {
                ans_arr[i][j] = m1->getArray()[i][j] + m2->getArray()[i][j];
            }
            cout << endl;
        }

        return ans;
    }

    Matrix substract(Matrix *m1, Matrix *m2)
    {

        Matrix ans(m1->getLength());
        int **ans_arr = ans.getArray();

        for (int i = 0; i < m1->getLength(); i++)
        {
            for (int j = 0; j < m1->getLength(); j++)
            {
                ans_arr[i][j] = m1->getArray()[i][j] - m2->getArray()[i][j];
            }
            cout << endl;
        }

        return ans;
    }
    Matrix transpose(Matrix *m1)
    {
        Matrix ans(m1->getLength());

        for (int i = 0; i < m1->getLength(); i++)
        {
            for (int j = 0; j < m1->getLength(); j++)
            {
                if (i == j)
                {
                    ans.getArray()[i][j] = m1->getArray()[i][j];
                    continue;
                }
                // ans.arr[j][i] = this->arr[i][j];

                ans.getArray()[j][i] = m1->getArray()[i][j];
            }
            cout << endl;
        }
        return ans;
    }

    Matrix multiply(Matrix *m1, Matrix *m2)
    {
        Matrix ans = Matrix(m1->getLength());

        for (int i = 0; i < m1->getLength(); i++)
        {
            for (int j = 0; j < m1->getLength(); j++)
            {
                int val = 0;
                for (int k = 0; k < m1->getLength(); k++)
                {
                    val = val + (m1->getArray()[i][k] * m2->getArray()[k][j]);
                }
                ans.getArray()[i][j] = val;
            }
        }

        return ans;
    }
};
int main()
{
    Matrix m1;
    Matrix m2;

    m1.accept();
    // m2.accept();

    // Matrix m3 = matrix_block::multiply(&m1,&m2);

    // m2=matrix_operation::transpose(&m1);

    m2.print();

}