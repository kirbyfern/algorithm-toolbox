#include <iostream>

typedef long long int lli;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
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

lli fibonacci_sum_eff(lli n) {
    return (get_fibonacci_huge_eff(n+2, 10) - 1 + 10) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_eff(n) << std::endl;
}
