#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

// Two way partition
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

// Create a Three way partition that is faster than the Tw- way partition
// Divide it on three parts for multiple sequencing relation
vector<int> partition3(vector<int> &a, int left, int right){
    int x = a[left]; // { pivot }
    int y = right;
    int z = left;
    for(int i = left; i <= y; i++)
    { 
        if(a[i] < x) // if current element is < the pivot, move/swap it to the left of the pivot
        {
            swap(a[i], a[z]);
            z++; // update 
        }
        else if(a[i] > x) // if current element is > the pivot, move/swap it to the right of the pivot
        {
            swap(a[i], a[y]);
            i--; 
            y--; // update
        }
    }
    vector<int> pivot_loc(2);
    pivot_loc[0] = z; pivot_loc[1] = z;
    return pivot_loc;
}

void randomized_quick_sort(vector<int> &a, int left, int right) {
    if (left >= right) return;
    int k = left + rand() % (right - left + 1); // Random { pivot }
    swap(a[left], a[k]);
    vector<int> pivot_position(2);
    pivot_position = partition3(a, left, right);

    randomized_quick_sort(a, left, pivot_position[0] - 1);
    randomized_quick_sort(a, pivot_position[1] + 1, right);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
