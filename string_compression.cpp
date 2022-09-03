#include <string>
#include <iostream>
#include <unordered_map>

std::string compresion(const std::string& str) {
	std::unordered_map<char, int> mymap;
	for (auto& i : str) {
		mymap[i]++;
	}
	std::string newstr;
	for (auto& i : mymap) {
		newstr.push_back(i.first);
		newstr.push_back(i.second + 48);
	}
	return newstr.size() == str.size() ? str : newstr;
}

int main() {
	std::cout << compresion("hellomyfiend");
}
