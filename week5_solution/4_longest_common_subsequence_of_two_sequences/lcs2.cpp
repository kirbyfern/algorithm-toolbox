#include <iostream>
#include <vector>

using std::vector;

// Constrainst 1 ≤ n, m ≤ 100; −10 9 < a subscript i , b superscript i < 10 9 .
// k = a, b = m
int lcs2(vector<int> &a, vector<int> &b) {
    // 2D Vector
    vector<vector<int>> vec(a.size() + 1, vector<int>(b.size() + 1, 0)); // Initialize vector containing n = a.size()+1 of size = b.size()+1
    for (int i = 1; i <= a.size(); ++i)
    {
        for (int j = 1; j <= b.size(); ++j)
        {
            if (a[i - 1] == b[j - 1])
                vec[i][j] = vec[i - 1][j - 1] + 1;
            else
                vec[i][j] = std::max(vec[i - 1][j],
                                    vec[i][j - 1]);
        }
    }
    return vec[a.size()][a.size()];
}

int main() {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++)
        std::cin >> a[i];

    size_t bm;
    std::cin >> bm;
    vector<int> b(bm);
    for (size_t i = 0; i < bm; i++)
        std::cin >> b[i];

    std::cout << lcs2(a, b) << std::endl;

    return 0;
}
