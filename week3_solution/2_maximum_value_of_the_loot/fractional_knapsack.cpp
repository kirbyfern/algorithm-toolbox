#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

template<class ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt i = begin; i != end; ++i)
        std::iter_swap(i, std::min_element(i, end));
}

// void selection_sort(vector<int> &c, vector<int> &w, vector<int> &v) {
//   int i, j, i_min;
//   for (i = 0; i < c.size(); i++) 
//   {
//     i_min = i; // index of min data
//     for (j= 0; j < w.size(); j++)
//     {
//       if (c[j] > c[i_min])
//       {
//         i_min = j;
//       }
//     }
//     if (i_min != i)
//     {

//     }
//   }
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}

