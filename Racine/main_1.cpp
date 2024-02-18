#include <iostream>
#include <array>

const int MAX_CASE = 5;

using namespace std;

void affiche_tableau (array <int,MAX_CASE> tableau)
{
  for (auto element: tableau ){
    cout << element << "  " ;
    }
}

int main()
{
  array <int, MAX_CASE > mon_tableau{ 0, 1, 2, 3, 4 };
  affiche_tableau(mon_tableau);
  
  return 0;
}