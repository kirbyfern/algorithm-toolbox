#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int> &numbers)
{
    long long result = 0;
    int n = numbers.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // cast long long data type for bigger memory
            if (((long long)numbers[i]) * numbers[j] > result)
            {
                result = ((long long)numbers[i]) * numbers[j];
            }
        }
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
