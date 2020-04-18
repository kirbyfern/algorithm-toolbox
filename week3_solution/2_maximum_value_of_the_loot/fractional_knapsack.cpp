#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;           //------------
using std::min_element;   //- Algorithm
using std::iter_swap;     //------------

// FIXME: DOUBLE CHECK SWAP
template<class ForwardIt>
void swap(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt i = begin; i != end; ++i)
        std::iter_swap(i, std::min_element(i, end));
}

void selection_sort(vector<double> &c, vector<int> &w, vector<int> &v) {
  int i, j, i_min;
  for (i = 0; i < c.size(); i++) 
  {
    i_min = i; // index of min data
    for (j= 0; j < w.size(); j++)
    {
      if (c[j] > c[i_min])
      {
        i_min = j;
      }
    }
    if (i_min != i)
    {
      swap(c.begin()+i, c.begin()+i_min);
      swap(w.begin()+i, w.begin()+i_min);
      swap(v.begin()+i, v.begin()+i_min);
    }
  }
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int weight_value = weights.size(), i, w, w_try;
  vector<double> A(weight_value);
  for (i = 0; i < weight_value; i++)
  {
    A[i] = (values[i] / (double) weights[i]); // typecast to double
  }
  selection_sort(A, values, weights);
  for (i = 0; i < weight_value; i++)
  {
    w = min(capacity, weights[i]);
    w_try = capacity - w;
    if (w_try >= 0) 
    {
      capacity = w_try;
      value += A[i] * w;
    }
  }
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
// FIXME: 
// TESTS INPUT 1:
// 3 50
// 60 20
// 100 50
// 120 30
// OUTPUT 1:
// 130 , output should be 180 - Failed

// TESTS INPUT 2:
// 1 10
// 500 30
// OUTPUT 2:
// 166.6666667 , output should be 166.6667 - Passed

