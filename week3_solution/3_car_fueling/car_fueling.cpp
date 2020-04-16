#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::string;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int num_refills = 0, current_refill = 0, last_refill = 0;
    string imp = "IMPOSSIBLE";

    while (current_refill <= dist) {
        last_refill = current_refill;
        while (current_refill <= dist && (stops[current_refill + 1] - stops[last_refill]) <= tank) {
            current_refill += 1;
            if (current_refill == last_refill)  {
                return -1;
            } else if (current_refill <= dist) {
                num_refills += 1;
            }
        }
    }
    return num_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
