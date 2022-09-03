#include <string>
#include <iostream>
#include <unordered_map>

bool is_permut_of_palindrom(const std::string& str) {
	std::unordered_map<char, int> mymap;
	for (auto& i : str) {
		if (i != ' ') {
			mymap[i]++;
		}
	}
	bool is_even = false;
	for (auto& i : mymap) {
		if (i.second % 2 != 0) {
			if (is_even) {
				return false;
			}
			is_even = true;
		}
	}
	return true;
}

int main() {
	std::cout << is_permut_of_palindrom("h helloo");
}
