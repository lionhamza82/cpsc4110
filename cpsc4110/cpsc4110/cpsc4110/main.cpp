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
    int f_of_zero, f_of_one = 0;

    vector<vector<int>> x = {{0},{0}}, y = {{0},{0}}, z = {{0},{0}};

    cout << "~~~~~ CPSC 4110 Project ~~~~~" << endl;
    cout << " 1) CNOT Gate" << endl;
    cout << " 2) Toffoli Gate" << endl;
    cout << " 3) Deutsch's Algorithm" << endl;
    cout << endl;

    while (choice == 0){
      cout << "Select a option: ";
      cin >> choice;

      switch (choice){
        case 1:
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

        case 3:
            cout << "What would you like f(0) to be (0 or 1):";
            cin >> f_of_zero;
            cout << "What would you like f(1) to be (0 or 1):";
            cin >> f_of_one;
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
      g.deutschAlgorithm_2(f_of_zero, f_of_one);
    }

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
