#include <iostream>
#include "big_num.hpp"

using namespace std;

int main()
{
     while(true)
     {
          big_num num1;
          big_num num2;
          int indx;
          cout << "Enter the first number: ";
          cin >> num1;
          cout<< "Enter the second number: ";
          cin >> num2;
          cout << "Enter an index: ";
          cin >> indx;
          big_num num3=num1+num2;
          big_num num4=num1-num2;
          cout << "Sum = " << num3 << endl;
          cout << "Difference = " << num4 << endl;
          cout << "In the sum, the digit at the index you entered is: " << num3[indx] << endl;
          cout << endl;
    }
}
