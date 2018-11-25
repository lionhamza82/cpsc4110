#ifndef GATES_H
#define GATES_H
#include <vector>


using namespace std;

class Gates
{
    public:
      vector<vector<int>> cnot = {  {1, 0, 0, 0},
                                    {0, 1, 0, 0},
                                    {0, 0, 0, 1},
                                    {0, 0, 1, 0}};

     vector<vector<int>> toffoli = {{1, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 1, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 1, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 1, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 1, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 0, 1, 0}};


      vector<vector<int>> uf = {{0, 1, 0, 0},
                                {1, 0, 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0, 1}};

      vector<vector<int>> cnotGate(vector<vector<int>>, vector<vector<int>>);
      vector<vector<int>> deutschAlgorithm(vector<vector<int>>, vector<vector<int>>);
      vector<vector<int>> toffoliGate(vector<vector<int>>, vector<vector<int>>, vector<vector<int>>);

};

#endif // GATES_H
