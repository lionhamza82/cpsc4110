#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

class Helper
{
    public:
        //Helper();
        complex<double> computeSum(complex<double>,complex<double>);
        complex<double> computeProduct(complex<double>,complex<double>);
        complex<double> conjugate(complex<double>);
        complex<double>* multiplication(complex<double>[3][3], complex<double>[3][3]);
        double length(complex<double>);


};

#endif // HELPER_H
