#include <iostream>
#include <vector>

typedef long long int lli;

using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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

int get_fibonacci_partial_sum_eff(lli from, long to) {
    return (get_fibonacci_huge_eff(to+2, 10) + 10) - (get_fibonacci_huge_eff(from+1, 10) % 10);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_eff(from, to) << '\n';
}
