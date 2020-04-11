#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long int li;

using namespace std;


//TODO:
// 1. Review Computing Runtimes
//    a.) Figure out how long my solution run
//    b.) Measure runtime without too much details
// 2. Create A faster algorithm vs. the currente naive
// 3. Build and make sure no error
// 4. Get output that work for large inputs

// note: increment, comparison, branch
// lookup, assignment, and add big int
// RAM LOOKUPS
// figuring out accurate runtime is impossible and a huge risk

// TEST CASE:
// Expected Output must be the same
// Input 3, Output 2
// Input 331, Output 9

// BRB TESTING RUNTIME

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
