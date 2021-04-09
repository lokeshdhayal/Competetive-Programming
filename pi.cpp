#include <iostream>
#include <cmath>
#include <limits>

int main()
{
  long double a0=1.0, b0 = 1/sqrt(2),
   t0 = 1.0/4.0, p0 = 1.0;
  long double an,bn,pn,tn;
  int i = 0;
  long double pi;
  while(i < 4)
    {
      an = (a0 + b0)/2.0;      
      bn = sqrt(a0 * b0);
      tn = t0 - (p0 * (a0-an)*(a0-an));
      pn = 2*p0;
      a0 = an,b0 = bn,p0 = pn,t0 = tn;

      pi = (an+bn)*(an+bn) / (4*tn);
      std::cout << pi << std::endl;      
      i++;
    }
  return 0;
}