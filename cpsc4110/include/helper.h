#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <complex>

using namespace std;

class Helper
{
    public:
        //Helper();
        complex<double> computeSum(complex<double>,complex<double>);
        complex<double> computeProduct(complex<double>,complex<double>);
        complex<double> conjugate(complex<double>);
        double length(complex<double>);

};

#endif // HELPER_H
