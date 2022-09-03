#include <string>
#include <iostream>

//we assume that have one space between words
void replace(std::string& str, int len) {
	int space_cnt = 0;
	for (int i = 0; i < len; ++i) {
		if (str[i] == ' ') {
			++space_cnt;
		}
	}
		int index = space_cnt * 2 + len;
		if (len < str.size()) str[len] = '\0';
		for (int i = len - 1; i >= 0; --i) {
			if (str[i] == ' ') {
				str[index - 1] = '0';
				str[index - 2] = '2';
				str[index - 3] = '%';
				index -= 3;
			}
			else {
				str[index - 1] = str[i];
				--index;
			}
		}
	}

int main() {
	std::string mystring = "axper jan inch ka         ";
	replace(mystring, 17);
	std::cout << mystring;
}
