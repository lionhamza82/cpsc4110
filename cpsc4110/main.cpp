#include <iostream>
#include <complex>
#include <helper.h>
#include <gates.h>
#include <vector>

using namespace std;

vector<vector<int>> assign_ket(int ket_choice, vector<vector<int>> v);

int main()
{
    Helper h;
    Gates g;
    int choice = 0;
    int ket_choice = 0;
    vector<vector<int>> x = {{0},{0}}, y = {{0},{0}}, z = {{0},{0}};

    cout << "~~~~~ CPSC 4110 Project ~~~~~" << endl;
    cout << " 1) CNOT Gate" << endl;
    cout << " 2) Toffoli Gate" << endl;
    cout << " 3) Deutsch's Algorithm" << endl;

    while (choice == 0){
      cout << "Select a option: ";
      cin >> choice;
      cout << endl;

      switch (choice){
        case 1: case 3:
          cout << " 0) |0> = 1" << endl;
          cout << "          0" << endl;
          cout << " 1) |1> = 0" << endl;
          cout << "          1" << endl;
          cout << "What would you like |x> to be: ";
          cin >> ket_choice;
          x = assign_ket(ket_choice, x);
          cout << "What would you like |y> to be: ";
          cin >> ket_choice;
          y = assign_ket(ket_choice, y);
          cout << endl;
          break;

        case 2:
          cout << " 0) |0> = 1" << endl;
          cout << "          0" << endl;
          cout << " 1) |1> = 0" << endl;
          cout << "          1" << endl;
          cout << "What would you like |x> to be: ";
          cin >> ket_choice;
          x = assign_ket(ket_choice, x);
          cout << "What would you like |y> to be: ";
          cin >> ket_choice;
          y = assign_ket(ket_choice, y);
          cout << "What would you like |z> to be: ";
          cin >> ket_choice;
          z = assign_ket(ket_choice, z);
          cout << endl;
          break;

        default:
          cout << "Invalid input" << endl;
          choice = 0;
      }
    }

    if (choice == 1){
      g.cnotGate(x, y);
    }
    else if (choice == 2){
      g.toffoliGate(x, y, z);
    }
    else if (choice == 3){
      g.deutschAlgorithm(x, y);
    }

    //complex<double> cmplx_1(5.0, 2.0);
    //complex<double> cmplx_2(6.0, 3.0);

    //2d array/matrix
    // complex<double> matrix_1[3][3] = {{cmplx_1, cmplx_1, cmplx_1},
    //                 {cmplx_1, cmplx_1, cmplx_1},
    //                 {cmplx_1, cmplx_1, cmplx_1}
    //                 };
    //
    // complex<double> matrix_2[3][3] = {{cmplx_2, cmplx_2, cmplx_2},
    //                 {cmplx_2, cmplx_2, cmplx_2},
    //                 {cmplx_2, cmplx_2, cmplx_2}
    //                 };

    //h.multiplication(matrix_1, matrix_2);
    //h.addition(matrix_1, matrix_2);
    //vector<vector<int>> matrix1 = {{1},{0}};
    //vector<vector<int>> matrix2 = {{1},{0}};
    //vector<vector<int>> matrix3 = {{0},{1}};
    //vector<vector<int>> result;

    //h.matrixMultiplication(matrix1, matrix2);

    //result = h.tensorProduct(h.tensorProduct(matrix1, matrix2), matrix3);


//    for(int x = 0; x < 8; x++)
//    {
//        cout << result.at(x).at(0) << endl;
//    }
//    cout << endl;

    //h.matrixMultiplication(matrix1, matrix2);
    //Gates g;
    //g.toffoliGate(matrix1, matrix2, matrix3);
    //g.deutschAlgorithm(matrix1, matrix2);


    //sum of two complex numbers
    //complex<double> sum = h.computeSum(cmplx_1, cmplx_2);
    // cout << real(sum) << " + " << imag(sum) << "i" << endl;

    //product of two complex numbers
    //complex<double> product = h.computeProduct(cmplx_1, cmplx_2);
    //cout << real(product) << " + " << imag(product) << "i" << endl;

    //conjugate of a complex number
    //complex<double> conjugate = h.conjugate(cmplx_1);
    //cout << real(conjugate) << " " << imag(conjugate) << "i" << endl;

    //length/modulus of a complex number
    //double length = h.length(cmplx_1);
    //cout << length << endl;

    return 0;
}

vector<vector<int>> assign_ket(int ket_choice, vector<vector<int>> v){
  if (ket_choice == 0){
    v = {{1},{0}};
  }
  else if (ket_choice == 1){
    v = {{0},{1}};
  }
   else{
     while (ket_choice != 0 and ket_choice != 1){
       cout << "Please enter the Input Again (0 or 1): ";
       cin >> ket_choice;
     }
     assign_ket(ket_choice, v);
   }
  return v;
}
