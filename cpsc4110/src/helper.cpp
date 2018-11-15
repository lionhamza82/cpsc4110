#include <Helper.h>
#include <iostream>
#include <complex>

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

