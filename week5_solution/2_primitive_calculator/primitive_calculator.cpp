#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
    vector<int> sequence;
	vector<int>  k(n+1);
    for(int i = 1; i < k.size(); i++)
    {
        k[i] = k[i - 1] + 1;
        if (i % 2 == 0)
            k[i] = std::min(1 + k[i/2], k[i]);
        if (i%3 == 0)
            k[i] = std::min(1 + k[i/3], k[i]);
	}
    int i = n;
	while (i>1)
    {
        sequence.push_back(i);
        if (k[i-1] == k[i]-1)
            i = i-1;
        else if (i%2 == 0 && (k[i/2] == k[i]-1))
            i = i/2;
        else if (i%3 == 0 && (k[i/3] == k[i]-1))
            i = i/3;
	}
    sequence.push_back(1);
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i)
        std::cout << sequence[i] << " ";

    return 0;
}