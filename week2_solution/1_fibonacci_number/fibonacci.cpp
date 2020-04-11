#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

typedef long int li;

using namespace std;

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fib_eff procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fib_eff (and the lines reading the input),
//    and submit it to the grader.

//-- Naive Algorithm w/c is much slower--//
int fib_naive(int n) {
    if (n <= 1)
        return n;

    return fib_naive(n - 1) + fib_naive(n - 2);
}

// My efficient solution
// Computing Runtime: (Max time used: 0.00/1.00, max memory used: 9142272/536870912.) = Passed
li fib_eff(int n) {
    // create a vector/array fibo
    vector<long int> fibo(n+1);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
      fibo[i] = fibo[i-1] + fibo[i-2];

    return fibo[n];
}

void test_solution() {
    assert(fib_eff(3) == 2);
    assert(fib_eff(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fib_eff(n) == fib_naive(n));
}

int main() {
    int n = 0;
    cin >> n;
    test_solution();
    cout << fib_eff(n) << endl;
    return 0;
}
