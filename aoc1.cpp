#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

// ADVENT OF CODE DAY 1
int main() {
	std::ifstream file("../input.txt");

	// Assert file
	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::vector<int> left;
	std::vector<int> right;

	std::string line;
	int counter = 0;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		int leftNum, rightNum;
		counter += 1;

		if (iss >> leftNum >> rightNum) {

			left.push_back(leftNum);
			right.push_back(rightNum);
		}
		else {
			std::cerr << "Error: could not parse line" << std::endl;
			return 1;
		}
	}
	file.close();
	//std::cout << "Counter: " << counter << std::endl;

	// Sort the vectors
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	
	// Calculate the difference
	int difference = 0;
	for (int i = 0; i < left.size(); i++) {
		difference += std::abs(right[i] - left[i]);
	}
	std::cout << "Difference: " << difference << std::endl;

	// Calculate similarity
	long long similarity = 0;
	for (int i = 0; i < left.size(); i++) {
		int current_counter = 0;
		for (int j = 0; j < left.size(); j++) {
			if (left[i] == right[j]) {
				current_counter += 1;
			}
		
		}
	similarity += static_cast<long long>(current_counter) * left[i];
	}
	std::cout << "Similarity: " << similarity << std::endl;

	

	return 0;
}

