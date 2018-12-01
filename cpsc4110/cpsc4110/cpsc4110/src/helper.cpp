#include <helper.h>
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

complex<double> Helper::computeSum(complex<double> cplx_num_1, complex<double> cplx_num_2)
{
    return cplx_num_1 + cplx_num_2;
}

complex<double> Helper::computeProduct(complex<double> cplx_num_1, complex<double> cplx_num_2)
{
    return cplx_num_1 * cplx_num_2;
}

complex<double> Helper::conjugate(complex<double> cplx_num)
{
    return conj(cplx_num);
}

double Helper::length(complex<double> cplx_num)
{
    return norm(cplx_num);
}

complex<double>* Helper::multiplication(complex<double> matrix_1[3][3], complex<double> matrix_2[3][3])
{
    complex<double> matrix[3][3];
    complex<double> product(0,0);
    complex<double> sum(0,0);
    vector<complex<double> > sumList;

    int i, j, incrementor = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //compute product
            for(int l = 0; l < 3; l++)
            {
                product = computeProduct(matrix_1[i][l], matrix_2[l][j]);
               // cout << product << endl;
                sumList.push_back(product);
            }
            //compute sum
            for(int k = 0; k < sumList.size(); k++)
            {
                sum = computeSum(sumList.at(k), sum);

            }
            matrix[i][j] = sum;
            sum = NULL;
            sumList.clear();
        }

    }
    cout << "done..." << endl;

    return *matrix;
}

complex<double>* Helper::addition(complex<double> matrix_1[3][3], complex<double> matrix_2[3][3])
{
    complex<double> matrix[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = computeSum(matrix_1[i][j], matrix_2[i][j]);
        }
    }

    cout << matrix[0][0] << " ";
    cout << matrix[0][1] << " ";
    cout << matrix[0][2] << " " << endl;

    cout << matrix[1][0] << " ";
    cout << matrix[1][1] << " ";
    cout << matrix[1][2] << " " << endl;

    cout << matrix[2][0] << " ";
    cout << matrix[2][1] << " ";
    cout << matrix[2][2] << " " << endl;

    return NULL;

}

vector<vector<int>> Helper::tensorProduct(vector<vector<int>> ket_1, vector<vector<int>> ket_2)
{
    vector<vector<int>> result;
    vector<int> temp;
    int incrementer = 0;

    for(int i = 0; i < ket_1.size(); i++)
    {
        for(int j = 0; j < ket_2.size(); j++)
        {
            temp.push_back(ket_1.at(i).at(0) * ket_2.at(j).at(0));
            result.push_back(temp);
            temp.clear();
        }
    }

    return result;
}

vector<vector<int>> Helper::matrixMultiplication(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    vector<vector<int>> result;
    int value = 0;
    vector<int> temp;
    int incrementer = 0;


    for(int i = 0; i < matrix1.size(); i++)
    {
        for(int k = 0; k < matrix1.size(); k++)
        {
            value += matrix1.at(i).at(k) * matrix2.at(k).at(0);
        }
        temp.push_back(value);
        result.push_back(temp);
        temp.clear();
        value = 0;
    }


    for(int x = 0; x < result.size(); x++)
    {
        cout << result.at(x).at(0) << endl;
    }

    return result;

}
