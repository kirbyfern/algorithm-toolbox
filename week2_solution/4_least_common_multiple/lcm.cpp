#include <iostream>

typedef long long int lli;
typedef long int li;

using namespace std;

//-- Naive Algorithm w/c is much slower
lli lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_eff(int a, int b) {
  if (b == 0)
    return a;
  // a', the remainder when a is div by b
  int a_prime = a % b;
  return gcd_eff(b,a_prime);
}


//-- Efficient Solution
lli lcm_eff(int a, int b) {
  return (lli) a * (b / gcd_eff(a, b));
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm_eff(a, b) << endl;
  return 0;
}
