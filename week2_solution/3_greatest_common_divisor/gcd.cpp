#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//-- naive algorithm is too slow --//
// int gcd_naive(int a, int b) {
//   int current_gcd = 1;
//   for (int d = 2; d <= a && d <= b; d++) {
//     if (a % d == 0 && b % d == 0) {
//       if (d > current_gcd) {
//         current_gcd = d;
//       }
//     }
//   }
//   return current_gcd;
// }


//-- my effective solution that doesn't exceed the req. runtime
int gcd_eff(int a, int b) {
  if (b == 0)
    return a;
  // a', the remainder when a is div by b
  int a_prime = a % b;
  return gcd_eff(b,a_prime);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd_eff(a, b) << endl;
  return 0;
}

