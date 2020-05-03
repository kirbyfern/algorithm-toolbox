#include <iostream>
#include <vector>
#include <limits>

using std::vector;

// Constraints 1 <= m <= 10^3
int get_change(int m) {
    vector<int> denomination{1, 3, 4}; // available coin denomination
    int least_num_coin[m + 1];
    int i, j, coin_count;
    least_num_coin[0] = 0;
    for (i = 1; i <= m; i++)
    {
        // value for int maximum would be 2,147,483,647
        least_num_coin[i] = std::numeric_limits<int>::max(); // set value to int's maximum as ∞
        for (j = 0; j <  3; j++)
        {
            if (i >= denomination[j])
            {
                coin_count = (least_num_coin[i - denomination[j]] + 1);
                if (coin_count < least_num_coin[i])
                {
                    least_num_coin[i] = coin_count;
                }
            }
        }
    }
    return least_num_coin[m];
}

// Integer money
int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}

