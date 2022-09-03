#include <utility>
#include <cmath>

int hash_func(const std::string& str, int q = 5371) {
        int hash = 0;
        int degree = 0;
        for (auto i = str.rbegin(); i < str.rend(); ++i) {
                hash += (*i - 'A' + 1) * pow(26, degree);
                hash %= q;
                ++degree;
        }
        return hash;
}

bool checkpermut(const std::string& pattern, const std::string& str) {
        int q = 5371;
        int pat_hash = hash_func(pattern, q);
        int p_len = pattern.size();
        std::string tox;
        auto it = str.begin();
        std::copy(it, it + p_len, std::back_inserter(tox));
        std::cout << tox;
        int hash = hash_func(tox, q);
        int degree = p_len - 1;
        for (int i = p_len; i < str.size(); ++i) {
                hash -= int((str[i - p_len] - 'A' + 1) * pow(26, degree)) % q;
                hash *= 26;
                hash += (str[p_len] - 'A' + 1);
                if (hash == pat_hash) {
                        int j = 0;
                        for (int k = i - p_len + 1; j < p_len; ++j, ++k) {
                                if (pattern[j] != str[k]) { break; }
                        }
                        if (j == p_len) return true;
                }
        }
        return false;
}

int main() {
        std::cout << (checkpermut("AAB", "AAABAAC"));
        std::cout << 'A' - 'A';
        //std::cout << hash_func("hello");
}

