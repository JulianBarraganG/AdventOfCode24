#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<bits/stdc++.h>

/* Time complexity of the solution
 * is O(n*k) where n is the number of rows,
 * and k is the number of elements in each row.
 * This solution beats the naive O(n*k^2) solution
 * due to the consider function, and the breaks after
 * said function is called, with at most 4 checks per row,
 * giving O(n*4k) = O(n*k) time complexity.
 */

// Function to check if a row is safe
bool safe_row(std::vector<int> row) {
	int k = row.size();
	bool is_safe = true;	
	bool ascending = true;
	bool descending = true;
	for (int j = 0; j < (k - 1); j++) {
		int diff = row[j] - row[j+1];
		if (diff > 0) {
			ascending = false;
		}
		if (diff < 0) {
			descending = false;
		}
		if (std::abs(diff) == 0 || std::abs(diff) > 3) {
			is_safe = false;
			break; 
		}
	}
	return (is_safe && (ascending || descending));	
}

// Function to reconsider a row, after removing a bad element
void consider(const std::vector<int>& row, int i, bool& safe_version_exists) {
	std::vector<int> tester = row;
	tester.erase(tester.begin() + i);
	if (safe_row(tester)) {
		safe_version_exists = true;
	}
}

int main() {

	std::vector<std::vector<int>> table;
	std::string line;
	std::vector<int> row;

	while (std::getline(std::cin, line)) {
		int num;
		std::istringstream iss(line); // input string stream
		while (iss >> num) {
			row.push_back(num);
		}	
		table.push_back(row);
		row.clear();
	}	
	int num_safe = 0; 
	int n = table.size();
	for (int i = 0; i < n; i++) {
		bool safe_version_exists = false;
		int k = table[i].size();
		consider(table[i], 0, safe_version_exists);
		for (int j = 0; j < k - 1; j++) {
			int diff = table[i][j] - table[i][j+1];
			// |diff| <
			if (std::abs(diff) == 0 || std::abs(diff) > 3) {
				consider(table[i], j, safe_version_exists);
				consider(table[i], j+1, safe_version_exists);
				break;
			}
			if (j < k - 2) {
				int next_diff = table[i][j+1] - table[i][j+2];
				// can be 3 10 5 or 5 3 10 or 10 3 5, one needs to go.
				if ((next_diff > 0) != (diff > 0)) {
					consider(table[i], j, safe_version_exists);
					consider(table[i], j+1, safe_version_exists);
					consider(table[i], j+2, safe_version_exists);
					break;
				}
			}
		}
		if (safe_version_exists) {
			num_safe++;
		}
	}

	std::cout << "Number of safe rows: " << num_safe << std::endl;

	return 0;
}
