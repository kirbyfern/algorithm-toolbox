#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

// // Iterative
// // high = right , low = left
// int binary_search(const vector<int> &a, int low, int high, int key) {
//   // code
//   if (low <= high)
//   {
//     // find the middle of the sorted array
//     int mid = low + (high-low) / 2;
//     if (a[mid] == key) return mid; // if key is the current floor in the array
//     if (key < a[mid]) high = mid - 1; // if key is less than the current floor, set index -1
//     else if (key > a[mid]) low = mid + 1; // if key is greater than the current floor, set index +1
//   }
//   return -1;
// }


// Recursive
int binary_search(const vector<int> &a, int low, int high, int key) {
  // code
  if (low <= high)
  {
    // find the middle of the sorted array
    int mid = low + (high - low) / 2;
    if (a[mid] == key) return mid; // if key is the current floor in the array
    if (key < a[mid]) return binary_search(a, low, mid-1, key); // if key is less than the current floor, set index -1
    return binary_search(a, mid+1, high, key);// if key is greater than the current floor, set index +1
  }
  return -1;
}

// Improved Eff. 
int linear_search(const vector<int> &a, int number_size, int key) {
  for (int i = 0; i < a.size(); ++i) 
  {
    if (a[i] == key) return i;
  }
  return -1;
}

int main() {
  int n, key, length;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
    std::cin >> a[i];

  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
    std::cin >> b[i];

  for (int i = 0; i < m; ++i) {
    key = b[i];
    //replace with the call to binary_search/linear_search when implemented
    std::cout << binary_search(a, 0, n-1, key) << ' ';
  }

  return 0;
}
