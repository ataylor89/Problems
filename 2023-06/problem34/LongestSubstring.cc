#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> m;
        int max_len = 0;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                char c = s[j];
                if (m.find(c) == m.end()) {
                    m[c] = true;
                    len++;
                }
                else {                    
                    break;
                }
            }
            if (len > max_len) {
                max_len = len;
            }
            len = 0;
            m.clear();
        }
        return max_len;
    }

    void test(string s) {
        int len = lengthOfLongestSubstring(s);
        cout << "Input: " << s << "\t" << "Length of longest substring: " << len << endl;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    string s4 = " ";
    s.test(s1);
    s.test(s2);
    s.test(s3);
    s.test(s4);
    return 0;
}
