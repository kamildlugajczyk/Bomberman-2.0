#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iterator>



int main()
{
	std::vector<int> intVector;
	std::vector<int> copy_intVector(20);
	srand(time(NULL));

	for (int i = 0; i < 20; i++)
		intVector.push_back(rand() % 50 + 1);

	copy(intVector.begin(), intVector.end(), copy_intVector.begin());

	for_each(copy_intVector.begin(), copy_intVector.end(), [&](int & value) {std::cout << value << ", "; });

	std::cout << std::endl;
	sort(copy_intVector.begin(), copy_intVector.end());

	for_each(copy_intVector.begin(), copy_intVector.end(), [&](int & value) {std::cout << value << ", "; });

	std::cout << "\nMax: " << *max_element(copy_intVector.begin(), copy_intVector.end()) << std::endl;
	std::cout << "Max: " << *min_element(copy_intVector.begin(), copy_intVector.end()) << std::endl;

	std::getchar();
	return 0;
}