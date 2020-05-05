#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// n = 1st_input, m = 2nd_input
int edit_distance(const string &str1, const string &str2) {
	int str1_s = str1.size(),
        str2_s = str2.size(),
        distance_cost = 0;
    // 2D Vector
	vector<vector<int>> vec(str1_s + 1, vector<int>(str2_s + 1, 0)); // Initialize vector containing n = str1_s+1 of vector size str2_s+1
	for(int i = 0; i <= str1_s; ++i)
        vec[i][0] = i;
    for(int i = 0; i <= str2_s; ++i)
        vec[0][i] = i;
	for(int i = 1; i <= str1_s; ++i)
    {
		for(int j = 1; j <= str2_s; ++j)
        {
			if(str1[i - 1] == str2[j - 1])
				distance_cost = 0;
			else
				distance_cost = 1;
			vec[i][j] = std::min(std::min(vec[i - 1][j],
                                          vec[i][j-1]) + 1,
                                          vec[i-1][j-1] + distance_cost);
		}
	}
	return vec[str1_s][str2_s]; // returns the distance between the inputted two strings
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}