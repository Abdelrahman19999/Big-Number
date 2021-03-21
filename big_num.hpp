// By:
// Abdelrahman Mohammed Amr 20186014
// Bassel Yasser Al-Ashram 20176042

#ifndef BIGNUMBER_
#define BIGNUMBER_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// to_string()
template <typename T>
string to_string(const T& number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

class big_num
{
     public:
          string num;
          bool neg=false;
          big_num(string x="")
          {
               num=x;
               if(num[0]=='-')
               {
                    neg=true;
                    num.erase(0,1);
               }
          }
          big_num(double n)
          {
               num = to_string(n);
               if(n<0)
               {
                    neg=true;
                    num.erase(0,1);
               }
          }
          big_num operator+(const big_num&obj);
          big_num operator-(const big_num&obj);
          friend ostream& operator<<(ostream& os, const big_num& fi);
          friend istream& operator>>(istream& is, big_num& fi);
          int operator[](int x)
          {
               if(x<0 || x>num.length()-1)
               {
                    cout << "Index is out of range, garbage value will be returned. ";
                    return 12735765;
               }
               else if(neg) return -1*(num[x]-48);
               else return (num[x]-48);
          }
};

#endif
