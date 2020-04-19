#include <algorithm>
#include <iostream>
#include <vector>
#include <random>


using std::vector;
using std::cin;
using std::cout;
using std::endl;

// where z is the highest value in an index
long long get_highest_value(vector<int> z) {
  // set z to max
  long long max = z[0];
  long long index = 0;
  for (long long i = 0; i < z.size(); i++)
  {
    if (max < z[i])
    {
      max = z[i];
      index = i;
    }
  }
  return index;
}

// FIXME: POINTER ALLOCATION INVALID
long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  for (long long i = 0; i < a.size(); i++) {
    long long a_max = get_highest_value(a);
    long long b_max = get_highest_value(b);
    result += (a[a_max] * b[b_max]);
    delete & a[a_max];
    delete & b[b_max];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << max_dot_product(a, b) << endl;
}

// FIXME: TEST INPUT 2
// TEST INPUT 1:
// 1
// 23
// 39
// 897
// OUTPUT: 897 - Passed

// TEST INPUT 2:
// 3
// 1 3 -5
// -2 4 1
// OUTPUT: INVALID POINTER