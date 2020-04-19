#include <algorithm>
#include <iostream>
#include <vector>


// // where z is the highest value in an index
// long long get_highest_value(vector<int> z) {
//   // set z to max
//   long long max = z[0];
//   long long index = 0;
//   for (long long i = 0; i < z.size(); i++)
//   {
//     if (max < z[i])
//     {
//       max = z[i];
//       index = i;
//     }
//   }
//   return index;
// }

// FIXME: 
long long max_dot_product(std::vector<int> a, std::vector<int> b) {
  // write your code here
  std::vector<int>::iterator a_max_pos;
  std::vector<int>::iterator b_max_pos;
  long long result = 0;
  for (long long i = 0; i < a.size(); i++) {
    auto const a_max_pos = std::max_element( a.begin( ), a.end( ) );
    auto const b_max_pos = std::max_element( b.begin( ), b.end( ) );
    result += *a_max_pos * *b_max_pos;
    a.erase( a_max_pos );
    b.erase( b_max_pos );
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}

// FIXME: 
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
// 13 - Should be 23 - Fail