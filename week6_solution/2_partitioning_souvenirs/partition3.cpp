#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

using std::vector;

bool partition3(vector<int>& A, int b)
{
    // Params:
    // first, last, init, op
    // returns the sum of the given value and elements in the given range
    int sum_zero = accumulate(A.begin(), A.end(), 0);
    if (sum_zero % b) return 0;
    int k = sum_zero/b;
    int a = A.size(); // w/ out discrete repition
    // 2D Vector
    // initialize a vector containing 'k' rows
    // vectors of size 'a' column
    vector<vector<int>> vec(k + 1, vector<int>(a + 1));
    for (int i = 1; i <= a; i++)
    {
        int prev = A[i - 1];
        // iterate smaller compact value problems
        for (int j = 1;j <= k; j++)
        {
            // check if j is > ji
            // used the previous value
            vec[j][i] = vec[j][i - 1];
            if (j >= prev) vec[j][i] = std::max(vec[j - prev][i - 1] + prev, vec[j][i - 1]);
        }
     }
    return vec[k][a] == k;
}

int main() {
  int n, b = 3;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) std::cin >> A[i];

  std::cout << partition3(A, b) << '\n';

  return 0;
}
