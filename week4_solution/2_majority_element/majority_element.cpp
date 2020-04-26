#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &z, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return z[left];
  std::sort(z.begin(), z.end()); // changed to normal iteration
  // test
  // for (auto a : z) std::cout << a << " ";
  int counter = 0, mid = left + (right - left) / 2, current_element = z[mid];
  for (int i = counter; i < z.size(); i++)
  {
    if (z[i] == current_element) counter++;
  }
  if (counter > z.size() / 2) return 1;

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> z(n);
  for (size_t i = 0; i < z.size(); ++i) {
    std::cin >> z[i];
  }
  std::cout << (get_majority_element(z, 0, z.size()) != -1) << '\n';
}

