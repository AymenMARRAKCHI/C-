#include <iostream>
using namespace std;

int main () 
{
  double *pt_1, *pt_2;
  double n = 1.1;
  double p = 2.2;
  
  pt_1 = &n;
  pt_2 = &p;
  
  *pt_1 = *pt_2 + 2;
  (*pt_1) += 3;
  (*pt_1) ++;
  
  cout << "n = " << n  << endl;
  cout << "p = " << p << endl;
  
  cout << "pt_1 = " << *pt_1 << endl;
  cout << "pt_2 = " << *pt_2 << endl;
  
  return 0;
  
}