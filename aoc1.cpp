#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

// ADVENT OF CODE DAY 1
int main() {

	// Initialize the vectors
	std::vector<int> left;
	std::vector<int> right;

	std::string line;
	while (std::getline(std::cin, line)) {
		std::istringstream iss(line);
		int leftNum, rightNum;

		if (iss >> leftNum >> rightNum) {

			left.push_back(leftNum);
			right.push_back(rightNum);
		}
		else {
			std::cerr << "Error: could not parse line" << std::endl;
			return 1;
		}
	}

	// Sort the vectors
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	
	// Calculate the difference
	int difference = 0;
	for (int i = 0; i < left.size(); i++) {
		difference += std::abs(right[i] - left[i]);
	}
	std::cout << "Difference: " << difference << std::endl;

	// Count each instance of an element in the right vector
	// and save it in a hash table
	std::unordered_map<int, int> rightMap;
	for (int i = 0; i < right.size(); i++) {
		rightMap[right[i]]++;
	}

	int similarity = 0;
	for (int i = 0; i < left.size(); i++) {
		similarity += left[i] * rightMap[left[i]];
	}

	std::cout << "Similarity: " << similarity << std::endl;

	return 0;
}

