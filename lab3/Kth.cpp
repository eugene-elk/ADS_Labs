#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int partition(vector<int> &mas, int l, int r) {
  if (l!=r)
    swap(mas[l + rand() % (r - l)], mas[r]);
  int x = mas[r];
  int i = l-1;
  for (int j = l; j <= r; j++) {
    if (mas[j] <= x)
      swap(mas[++i],mas[j]);
  }
  return i;
}

int nth(vector<int> mas, int n) {
  int l = 0, r = mas.size() - 1;
  for(;;) {
    int pos = partition(mas,l,r);
    if (pos < n)
      l = pos + 1;
    else if (pos > n)
      r = pos - 1;
    else return mas[n];
  }
}

int main()
{

}
