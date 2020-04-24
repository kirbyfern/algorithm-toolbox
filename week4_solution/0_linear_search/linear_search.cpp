#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using std::vector;

int linear_search(int numbers[], int number_size, int key) {
	int i = 0;
	for(i = 0; i < number_size; i++)
    {
		if(numbers[i] == key) 
        {
			return i;
		}
	}
	return -1;
}

int main() {
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	vector<int> A_numbers;
	int a_random_numbers = std::rand() % 20 + 1; // 1 to 20
	for (int i = 0; i < a_random_numbers; i++)
	{
		int b_random_numbers = std::rand() + 20 + 1;
		A_numbers.push_back(b_random_numbers);
		std::cout << A_numbers[i] << std::endl; // generate random test numbers
	}
	std::cout << "\n";

	// hardcoded random numbers
	int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
	const int NUMBERS_SIZE = 8;
	int i = 0, key = 0, key_index = 0;

	std::cout << "NUMBERS: ";
	for (i = 0; i < NUMBERS_SIZE; i++) 
    {
		std::cout << numbers[i] << ' ';
	}
	std::cout << "\n";
	std::cout << "Enter a value: ";
	std::cin >> key;

	key_index = linear_search(numbers, NUMBERS_SIZE, key);

	if (key_index == -1) {
		std::cout << key << " was not found." << std::endl;
	}
	else {
		std::cout << "Found " << key << " at index " << key_index << "." << std::endl;
	}

	return 0;
}