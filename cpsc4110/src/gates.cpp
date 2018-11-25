#include "gates.h"
#include <helper.h>
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

vector<vector<int>> Gates::cnotGate(vector<vector<int>> x, vector<vector<int>> y)
{
    Helper h;
    vector<vector<int>> result, tensor;

    tensor = h.tensorProduct(x, y);

    cout << "~~|x> Tensor |y> ~~ " << endl;
    for (int i = 0; i < x.size(); i++){
      cout << x.at(i).at(0);
      cout << "      ";
      cout << y.at(i).at(0) << endl;
    }
    cout << endl;
    cout << "~~ CNOT * |xy> ~~ " << endl;
    for (int i = 0; i < cnot.size(); i++){
      for (int j = 0; j < tensor.size(); j++){
        cout << cnot.at(i).at(j);
        cout << " ";
      }
      cout << "      ";
      cout << tensor.at(i).at(0) << endl;
    }
    cout << endl;

    cout << "~~ Result ~~ " << endl;
    result = h.matrixMultiplication(cnot, tensor);

    return result;
}

vector<vector<int>> Gates::toffoliGate(vector<vector<int>> x, vector<vector<int>> y, vector<vector<int>> z)
{
    Helper h;
    vector<vector<int>> result, tensor1, tensor2;

    tensor1 = h.tensorProduct(x, y);
    tensor2 = h.tensorProduct(tensor1, z);

    cout << "~~|x> Tensor |y> Tensor |z> ~~ " << endl;
    for (int i = 0; i < x.size(); i++){
      cout << x.at(i).at(0);
      cout << "      ";
      cout << y.at(i).at(0);
      cout << "      ";
      cout << z.at(i).at(0) << endl;
    }
    cout << endl;
    cout << "~~ Tofolli * |xyz> ~~ " << endl;
    for (int i = 0; i < toffoli.size(); i++){
      for (int j = 0; j < tensor2.size(); j++){
        cout << toffoli.at(i).at(j);
        cout << " ";
      }
      cout << "      ";
      cout << tensor2.at(i).at(0) << endl;
    }
    cout << endl;

    cout << "~~ Result ~~ " << endl;
    result = h.matrixMultiplication(toffoli, tensor2);

    return result;
}

vector<vector<int>> Gates::deutschAlgorithm(vector<vector<int>> x, vector<vector<int>> y)
{
    Helper h;
    vector<vector<int>> result, tensor;

    tensor = h.tensorProduct(x, y);

    cout << "~~|x> Tensor |y> ~~ " << endl;
    for (int i = 0; i < x.size(); i++){
      cout << x.at(i).at(0);
      cout << "      ";
      cout << y.at(i).at(0) << endl;
    }
    cout << endl;
    cout << "~~ Uf * |xy> ~~ " << endl;
    for (int i = 0; i < uf.size(); i++){
      for (int j = 0; j < tensor.size(); j++){
        cout << uf.at(i).at(j);
        cout << " ";
      }
      cout << "      ";
      cout << tensor.at(i).at(0) << endl;
    }
    cout << endl;

    cout << "~~ Result ~~ " << endl;
    result = h.matrixMultiplication(uf, tensor);

    return result;

}
