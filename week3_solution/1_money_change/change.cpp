#include <iostream>
#include <math.h>

using namespace std;

//-- Eff Solution
//Computing Runtime: (Max time used: 0.00/1.00, max memory used: 9129984/536870912.)
int get_change(int m) {
  int a = 1, b = 5, c = 10, n = 0;

  if (m <= pow(10, 3) ) { // Constraints: 1 <= m <= 10^3, 
    // denomination
    int c_denom = m / c;
    if (c_denom >= a) {
      n += c_denom;
    } 
    m = m - (c_denom * c);
    int b_denom = m / b;
    if (b_denom >= a) {
      n += b_denom;
    }
    m = m - (b_denom * 5);
    n += m;

    return n;
  } else {
    exit(0);
  }
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}


