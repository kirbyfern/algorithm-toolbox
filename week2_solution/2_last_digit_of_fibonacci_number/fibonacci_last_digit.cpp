#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long int li;

using namespace std;

//-- Naive algorithm slower runtime
int get_fibo_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

// My Solution
// Computing Runtime: (Max time used: 0.00/1.00, max memory used: 9248768/536870912.) = Passed
li get_fibo_last_digit_eff(int n) {
    // create a vector/array fibo
    vector<long int> fibo(n+1);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
      fibo[i] = (fibo[i-1] + fibo[i-2])%10;

    return fibo[n] % 10;
}


int main() {
    int n;
    cin >> n;
    int c = get_fibo_last_digit_eff(n);
    cout << c << endl;
    }
