#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProductFast(const std::vector<int> &numbers)
{
    int n = numbers.size();

    // find the first maximum element and store its index in variable max_index1
    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
    {
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
        {
            max_index1 = i;
        }
    }

    // find the second maximum element and store its index in variable max_index2
    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
    {
        if ((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
        {
            max_index2 = j;
        }
    }

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main()
{
    // int n;
    // std::cin >> n;
    // std::vector<int> numbers(n);

    // for (int i = 0; i < n; ++i)
    // {
    //     std::cin >> numbers[i];
    // }

    long long result = MaxPairwiseProductFast(std::vector<int>(100000, 0));
    std::cout << result << "\n";
    return 0;
}
