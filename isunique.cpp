#include <iostream>

bool is_unique(std::string& st) {
        bool arr[128] = { 0 };
        for (auto& i : st) {
                if (arr[i]) {
                        return false;
                }
                arr[i] = true;
        }
        return true;
}

int main() {
        std::string str = "axper jan";
        std::cout << is_unique(str);
}

