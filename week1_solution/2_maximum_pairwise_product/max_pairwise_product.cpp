#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// not using namespace on this solution

long long MaxPairwiseProduct(const std::vector<int> &numbers)
{
    long long result = 0;
    int n = numbers.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // cast long long data type for bigger memory
            if (((long long)numbers[i]) * numbers[j] > result) {
                result = ((long long)(numbers[i])) * numbers[j];
            }
        }
    }
    return result;
}


// Efficient Solution
// Computing Runtime: (Max time used: 0.04/1.00, max memory used: 23613440/536870912.) = Passed
long long MaxPairwiseProductFast(const std::vector<int> &numbers)
{
    int n = numbers.size();

    // find the first maximum element and store its index in variable max_index1
    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
            max_index1 = i;


    // find the second maximum element and store its index in variable max_index2
    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;

     //-- Debug
    // std::cout << max_index1 << ' ' << max_index2 << "\n";

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main()
{
    /*
    // Implement Stress Test
    while (true)
    {
        int n = rand() % 1000 + 2;
        std::cout << n << "\n";
        // generate a number of arrays called a
        std::vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i)
        {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2)
        {
            std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else
        {
            std::cout << "OK\n";
        }
    }
    */
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    std::cout << result << "\n";
    return 0;
}
