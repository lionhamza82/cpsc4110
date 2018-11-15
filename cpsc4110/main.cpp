#include <iostream>
#include <complex>
#include <helper.h>

using namespace std;

int main()
{
    Helper h;

    complex<double> cmplx_1(5.0, 2.0);
    complex<double> cmplx_2(5.0, 2.0);

    //sum of two complex numbers
    complex<double> sum = h.computeSum(cmplx_1, cmplx_2);
    cout << real(sum) << " + " << imag(sum) << "i" << endl;

    //product of two complex numbers
    complex<double> product = h.computeProduct(cmplx_1, cmplx_2);
    cout << real(product) << " + " << imag(product) << "i" << endl;

    //conjugate of a complex number
    complex<double> conjugate = h.conjugate(cmplx_1);
    cout << real(conjugate) << " " << imag(conjugate) << "i" << endl;

    //length/modulus of a complex number
    double length = h.length(cmplx_1);
    cout << length << endl;

    return 0;
}
