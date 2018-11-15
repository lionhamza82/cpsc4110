#include <Helper.h>
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

complex<double> Helper::computeSum(complex<double> cplx_num_1, complex<double> cplx_num_2)
{
    complex<double> sum(real(cplx_num_1 + cplx_num_2),
                        imag(cplx_num_1 + cplx_num_2)
                        );
    return sum;
}

complex<double> Helper::computeProduct(complex<double> cplx_num_1, complex<double> cplx_num_2)
{
    //formula:
    // (a + bi) (c + di) = (a*c - b*d) + (a*d + b*c)

    //a*c
    double ac = real(cplx_num_1) * real(cplx_num_2);
    //b*d
    double bd = imag(cplx_num_1) * imag(cplx_num_2);
    //real part = (a*c - b*d)
    double real = ac - bd;

    //a*d
    double ad = std::real(cplx_num_1) * std::imag(cplx_num_2);
    //b*c
    double bc = std::imag(cplx_num_1) * std::real(cplx_num_2);
    //complex part = (a*d + b*c)
    double complex_part = ad + bc;

    complex<double> product(real, complex_part);

    return product;
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
