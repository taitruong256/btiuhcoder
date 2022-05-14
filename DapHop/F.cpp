#include <iostream>
using namespace std;

int main()
{
   long long  n,k;
   cin>> n >> k;
   if(n%k==0)
   {
      cout << n ;
      return 0;
   }else
   cout << 0;
}