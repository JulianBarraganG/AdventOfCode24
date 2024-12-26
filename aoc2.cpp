#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<bits/stdc++.h>

bool safe_row(std::vector<int> row) {
	int k = row.size();
	bool is_safe = true;	
	bool ascending = true;
	bool descending = true;
	for (int j = 0; j < (k - 1); j++) {
		int diff =row[j] - row[j+1];
		if (diff > 0) {
			ascending = false;
		}
		if (diff < 0) {
			descending = false;
		}
		if (std::abs(diff) > 3 || std::abs(diff) == 0) {
			is_safe = false;
			break; 
		}
	}
	return (is_safe && (ascending || descending));	
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
	int num_safe = 0; // int defaults to 0
	int n = table.size();
	for (int i = 0; i < n; i++) {
		if (safe_row(table[i])) {
			num_safe++;
		}
	}

	std::cout << "Number of safe rows: " << num_safe << std::endl;

	return 0;
}
