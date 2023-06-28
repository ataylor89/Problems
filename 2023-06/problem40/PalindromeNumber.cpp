#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        vector<int> digits;
        while (x > 0) {
            int digit = x % 10;
            digits.push_back(digit);
            x /= 10;
        }
        int len = digits.size();
        bool is_palindrome = true;
        for (int i = 0; i < len; i++) {
            if (digits[i] != digits[len-1-i]) {
                is_palindrome = false;
                break;
            }
        }
        return is_palindrome;
    }
};

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 0;
    }
    Solution s;
    int x = atoi(argv[1]);
    bool is_palindrome = s.isPalindrome(x);
    if (is_palindrome)
        cout << x << " is a palindrome" << endl;
    else
        cout << x << " is not a palindrome" << endl;
    return 0;
}
