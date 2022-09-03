#include <string>
#include <iostream>

bool one_away(const std::string& orig, const std::string& changed) {
	if (orig.size() - changed.size() > 1 || changed.size() - orig.size() > 1) return false;
	if (orig.size() == changed.size()) {
		bool dif = false;
		for (int i = 0; i < orig.size(); ++i) {
			if (orig[i] != changed[i]) {
				if (dif) return false;
				else { dif = true; }
			}
		}
		return true;
	}
	bool is_change = false;
	std::string short_ = orig.size() > changed.size() ? changed : orig;
	std::string long_ = orig.size() > changed.size() ? orig : changed;
	int i = 0;
	int j = 0;
	bool dif = false;
	while (j != long_.size()) {
		if (short_[i] != long_[j]) {
			if (dif) {
				return false;
			}
			else { dif = true; }
		}
		else { ++i; }
		++j;
	}
	return true;
	
}

int main() {
	std::cout << one_away("lok", "slo");
}
