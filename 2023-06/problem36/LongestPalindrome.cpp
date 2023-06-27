#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        map<char, vector<int>> m;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (m.find(c) == m.end()) {
                vector<int> v;
                v.push_back(i);
                m[c] = v;
            }
            else {
                vector<int> &v = m[c];
                v.push_back(i);
            }
        }
        for (const auto& [c, v] : m) {
            for (int i = 0; i < v.size(); i++) {
                for (int j = i; j < v.size(); j++) {
                    int pos = v[i];
                    int len = v[j] - v[i] + 1;
                    if (len > result.size()) {
                        string ss = s.substr(pos, len);
                        if (isPalindrome(ss)) {
                            result = ss;
                        }
                    }
                }
            }
        }
        return result;
    }

    bool isPalindrome(string s) {
        int len = s.size();
        for (int i = 0; i < len/2; i++) {
            if (s[i] != s[len-i-1]) {
                return false;
            }
        }
        return true;
    }

    string toString(vector<int> v) {
        string s;
        s += "[";
        for (int i = 0; i < v.size(); i++) {
            s += to_string(v[i]);
            if (i < v.size() - 1) {
                s += ",";
            }
        }
        s += "]";
        return s;
    }
};

int main() {
    Solution s;
    string input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopponmlkjihgfedcba123456789";
    string result = s.longestPalindrome(input);
    cout << "Input string: " << input << endl;
    cout << "Longest palindromic substring: " << result << endl;
    return 0;
}
