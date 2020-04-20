#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

typedef long long int lli;


lli max_dot_product(std::vector<int> a, std::vector<int> b) {
  lli result = 0;
  std::sort(a.begin(), a.end(), std::greater<>());
  std::sort(b.begin(), b.end(), std::greater<>());
  for (lli i = 0; i < a.size(); i++)
  {
    // typecast
    result += ((lli) a[i]) * b[i];
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
