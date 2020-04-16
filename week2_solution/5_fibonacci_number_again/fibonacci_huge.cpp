#include <iostream>

typedef long long  int lli;

using namespace std;

//-- Naive
lli get_fibonacci_huge_naive(lli n, lli m) {
    if (n <= 1)
        return n;

    lli previous = 0;
    lli current  = 1;

    for (lli i = 0; i < n - 1; ++i) {
        lli tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

lli find_pisano_period(lli m) {
    // previous, current, rest/remainder being initialized
    lli prev = 0, curr = 1, rest = prev + curr;

    // return the calculation of the period of pisano
    for (lli i = 0; i < m * m; ++i) {
        rest = (prev + curr) % m;
        prev = curr;
        curr = rest;
        if (prev == 0 && curr == 1) // The period always starts with 01 and is known as Pisano period. 
            return i + 1;
    }
}

// Efficient Solution
// Output Format: Output Fn mod m
lli get_fibonacci_huge_eff(lli n, lli m) {

    // Getting the priod
    lli pisano_period = n % find_pisano_period(m);
    // period length of mod n
    // n %= pisano;

    // previous as a , current as b , rest/remainder as c being initialized as pisano
    lli a = 0, b = 1, c = pisano_period;
    n = pisano_period;
    for (lli i = 1; i < n; ++i) {
        c = (a + b) % m;
        a = b;
        b = c;
    }
    return c % m;
}

int main() {
    lli n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_eff(n, m) << endl;
}
