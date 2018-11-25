#include "gates.h"
#include <helper.h>
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

vector<vector<int>> Gates::cnotGate(vector<vector<int>> x, vector<vector<int>> y)
{
    Helper h;
    vector<vector<int>> tensor;

    tensor = h.tensorProduct(x, y);
    h.matrixMultiplication(cnot, tensor);
}

vector<vector<int>> Gates::toffoliGate(vector<vector<int>> x, vector<vector<int>> y, vector<vector<int>> z)
{
    Helper h;
    vector<vector<int>> result;

    result = h.tensorProduct(h.tensorProduct(x, y), z);

    h.matrixMultiplication(toffoli, result);

    return result;

}

vector<vector<int>> Gates::deutschAlgorithm(vector<vector<int>> x, vector<vector<int>> y)
{
    Helper h;
    vector<vector<int>> result;

    result = h.matrixMultiplication(uf, h.tensorProduct(x, y));

    return result;

}


