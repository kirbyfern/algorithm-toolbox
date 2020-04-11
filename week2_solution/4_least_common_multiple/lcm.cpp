#include <iostream>
#include <algorithm>

using namespace std;

// TODO:
// 1. Create a faster solution
// 2. Solution which is a better computing runtime and lesser memory

//-- Naive Algorithm w/c is much slower--//
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm_naive(a, b) << endl;
  return 0;
}
