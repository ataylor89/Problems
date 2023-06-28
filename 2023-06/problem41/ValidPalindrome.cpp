#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!isalnum(c)) {
                s.erase(i, 1);
                i--;
            }
            else if (isupper(c)) {
                s[i] = tolower(c);
            }
        }
        bool palindrome = true;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] != s[len-1-i]) {
                palindrome = false;
                break;
            }
        }
        return palindrome;
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 0;
    }
    Solution s;
    string input(argv[1]);
    bool palindrome = s.isPalindrome(input);
    if (palindrome) {
        cout << "It's a palindrome!" << endl;
    }
    else {
        cout << "It's not a palindrome" << endl;
    }
    return 0;
}
