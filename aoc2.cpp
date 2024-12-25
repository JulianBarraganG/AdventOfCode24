#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<bits/stdc++.h>

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
	for (int i = 0; i < table.size(); i++) {
		bool is_safe = true;	
		bool ascending = true;
		if (table[i][0] == table[i][1]) {
			is_safe = false;
		}
		else if (table[i][0] > table[i][1]) {
			ascending = false;
		}
		if (ascending) {
			for (int j = 0; j < (table[i].size() - 1); j++) {
				if (((table[i][j] - table[i][j+1]) < -3) 
						|| (table [i][j] >= table[i][j+1])) {
					is_safe = false;
					break; 
				}
			}
		}
		else {
			for (int j = 0; j < (table[i].size() - 1); j++) {
				if (((table[i][j] - table[i][j+1]) > 3) 
						|| (table [i][j] <= table[i][j+1])) {
					is_safe = false;
					break; 
				}
			}
		}
		if (is_safe) { 
			num_safe++; 
		}
	}

	std::cout << "Number of safe rows: " << num_safe << std::endl;

	return 0;
}
