#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &z, int left, int right, int &n) {
  if (left == right) return -1;
  if (left + 1 == right) return z[left];
  std::sort(z.begin(), z.end());
  // for (auto a : z) std::cout << a << " ";
  int current_element = z[0], counter = 0;
  for (int i = 0; i < n; i++)
  {
    if (z[i] == current_element) counter++;
  }
  if (counter > n/2) return current_element;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> z(n);
  for (size_t i = 0; i < z.size(); ++i) {
    std::cin >> z[i];
  }
  std::cout << (get_majority_element(z, 0, z.size(), n) != -1) << '\n';
}

