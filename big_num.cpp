// By:
// Abdelrahman Mohammed Amr 20186014
// Bassel Yasser Al-Ashram 20176042

#include "big_num.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

void decimalilty(string &x)
{
     bool t=false;
     int c=0;
     for(int i=0; i<x.length(); i++)
     {
          if(c==5)
          {
               x.erase(i);
               break;
          }
          if(t) c++;
          if(x[i]=='.') t=true;
     }
     if(!t) x=(x+".00000");
     else if(c<5)
     {
          for(int i=0; i<5-c; i++) x+='0';
     }
 }

string add(string num1,string num2)
{
     string result="";
     decimalilty(num1);
     decimalilty(num2);
     for(int i=0; i<num1.length(); i++)
     {
          if(num1[i]=='.') num1.erase(i,1);
     }
     for(int i=0; i<num2.length(); i++)
     {
          if(num2[i]=='.') num2.erase(i,1);
     }
     deque<int>a;
     deque<int>b;
     deque<int>c;
     int l = max(num1.length(),num2.length());
     int l2 = min(num1.length(),num2.length());
     for(int i=0; i<l-l2; i++)
     {
          if(num1.length()==l2) a.push_back(0);
          else b.push_back(0);
     }
     for(int i=0;i<num1.length();i++) a.push_back(num1[i]-48);
     for(int i=0;i<num2.length();i++) b.push_back(num2[i]-48);
     int sum=0, r=0;
     for(int i=0;i<l;i++)
     {
          sum += a[l-i-1] + b[l-i-1];
          if(sum>=10)
          {
               sum-=10;
               r=1;
          }
          else r=0;
          c.push_front(sum);
          if(r==1) sum=1;
          else sum=0;
     }
     int k;
     bool t = false;
     if(sum==1) c.push_front(1);
     for(auto e : c)
     {
          result+=char(e+48);
     }
     // for result presentation
     bool zero=true;
     for(int i=0; i<result.length(); i++)
     {
          if(result[i]!='.' && result[i]!='0')
          {
               zero=false;
               break;
          }
     }
     if(zero) return "0";
     result.insert(result.length()-5, ".");
     for(int i=0; i<result.length(); i++)
     {
          if(result[i]=='0' && result[i+1]=='.') break;
          else if(result[i]=='0')
          {
               result.erase(i,1);
               i--;
          }
          else if(result[i]!='-') break;
     }
     int decimal=0;
     for(int i=0; i<result.length(); i++)
     {
          if(t) decimal+=result[i]-48;
          if(result[i]=='.') t=true;
     }
     if(decimal==0)
     {
          for(int i=0; i<result.length(); i++)
          {
               if(result[i]=='.')
               {
                    result.erase(i);
                    break;
               }
          }
     }
     return result;
}

string subtract(string num1,string num2)
{
     decimalilty(num1);
     decimalilty(num2);
     for(int i=0;i<num1.length();i++)
     {
          if(num1[i]=='.') num1.erase(i,1);
     }
     for(int i=0;i<num2.length();i++)
     {
          if(num2[i]=='.') num2.erase(i,1);
     }
     deque<int>a;
     deque<int>b;
     deque<int>d;
     int sub;
     string result="";
     bool neg=false;
     int l=max(num1.length(),num2.length());
     int l2=min(num1.length(),num2.length());
     for(int i=0; i<l-l2; i++)
     {
          if(num1.length()==l2)a.push_back(0);
          else b.push_back(0);
     }
     for(int i=0; i<num1.length(); i++) a.push_back(num1[i]-48);
     for(int i=0; i<num2.length(); i++) b.push_back(num2[i]-48);
     for(int i=0; i<l; i++)
     {
          if(a[i] < b[i])
          {
               neg=true;
               break;
          }
          else if(a[i] > b[i]) break;
     }
     if(!neg)
     {
          for(int i=0; i<l; i++)
          {
               if(a[l-i-1] < b[l-i-1])
               {
                    a[l-i-1]+=10;
                    a[l-i-2]--;
               }
               sub=a[l-i-1]-b[l-i-1];
               d.push_front(sub);
          }
     }
     else
     {
          for(int i=0;i<l;i++)
          {
               if(b[l-i-1] < a[l-i-1])
               {
                    b[l-i-1]+=10;
                    b[l-i-2]--;
               }
               sub=b[l-i-1]-a[l-i-1];
               d.push_front(sub);
          }
     }
     if(neg) result+="-";
     bool t=false;
     for(auto e : d)
     {
          result+=char(e+48);
     }
     // for result presentation
     bool zero=true;
     for(int i=0; i<result.length(); i++)
     {
          if(result[i]!='.' && result[i]!='0')
          {
               zero=false;
               break;
          }
     }
     if(zero) return "0";
     result.insert(result.length()-5, ".");
     for(int i=0; i<result.length(); i++)
     {
          if(result[i]=='0' && result[i+1]=='.') break;
          else if(result[i]=='0')
          {
               result.erase(i,1);
               i--;
          }
          else if(result[i]!='-') break;
     }
     int decimal=0;
     for(int i=0; i<result.length(); i++)
     {
          if(t) decimal+=result[i]-48;
          if(result[i]=='.') t=true;
     }
     if(decimal==0)
     {
          for(int i=0; i<result.length(); i++)
          {
               if(result[i]=='.')
               {
                    result.erase(i);
                    break;
               }
          }
     }
     return result;
}

istream& operator>>(istream& is, big_num& fi)
{
     fi.neg=false;
     is >> fi.num;
     if(fi.num[0]=='-')
     {
          fi.neg=true;
          fi.num.erase(0,1);
     }
     return is;
}

ostream& operator<<(ostream& os, const big_num& fi)
{
     string c;
     if(fi.neg) c="-";
     else c="";
     os<< c << fi.num;
     return os;
}

big_num  big_num::operator+(const big_num&obj)
{
     string result;
     bool t=false;
     if(!neg && !obj.neg) result=add(num, obj.num);
     else if(!neg && obj.neg) result=subtract(num, obj.num);
     else if(neg && !obj.neg) result=subtract(obj.num, num);
     else if(neg && obj.neg)
     {
          result=add(num, obj.num);
          t=true;
     }
     big_num temp(result);
     if(t) temp.neg=true;
     return temp;
}

big_num big_num::operator-(const big_num&obj)
{
     string result;
     bool t=false;
     if(!neg && !obj.neg) result=subtract(num, obj.num);
     else if(!neg && obj.neg) result=add(num, obj.num);
     else if(neg && !obj.neg)
     {
          result=add(num, obj.num);
          t=true;
     }
     else if(neg && obj.neg) result=subtract(obj.num, num);
     big_num temp(result);
     if(t) temp.neg=true;
     return temp;
}
