#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &weights) {
    // 2D Vector
    // initialize a vector containing k rows
    // vectors of size l column
    // with a value of 0
    int k = weights.size();
    int l = W + 1;
    vector<vector<int>> vec_val(k + 1, vector<int>(l, 0));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            vec_val[i][j] = vec_val[i - 1][j];
            if (weights[i - 1] <= j)
            {
                int val = vec_val[i - 1][j - weights[i - 1]] + weights[i - 1];
                if (vec_val[i][j] < val) vec_val[i][j] = val;
            }
        }
    }
    return vec_val[k][W];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        std::cin >> weights[i];

    std::cout << optimal_weight(W, weights) << '\n';

    return 0;
}