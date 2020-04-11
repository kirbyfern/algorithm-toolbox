#include <iostream>

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

int get_fibonacci_last_digit_naive(int n) {
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

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }

    std::cout << c << '\n';