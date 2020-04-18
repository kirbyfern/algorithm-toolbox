#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::string;


// x = vector<int> stops
// n = dist
// L = tank

// Efficient Solution
// Computing Runtime: (Max time used: 0.00/1.00, max memory used: 9187328/536870912.)
int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int num_refills = 0, current_refill = 0, last_refill = 0, pos_refill = -2;
    bool ref = true;
    // add a new element at the end of the last element of stops array
    stops.push_back(dist);
    while (ref)
    {
        if (dist <= (current_refill + tank))
        {
            return num_refills;
        }
        if ((stops[last_refill] - current_refill) > tank)
        {
            pos_refill = last_refill - 1;
            if (current_refill == stops[pos_refill])
            {
                return -1;
            }
            num_refills++;
            current_refill = stops[last_refill - 1];
            last_refill -= 1;
            continue;
        }
        ++last_refill;
    }
    return -1;
}


int main() {
    int d = 0, m = 0, n = 0;
    cin >> d;
    cin >> m;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
