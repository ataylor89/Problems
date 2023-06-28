#include "MyAtoi.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

#define MIN -1*pow(2,31)
#define MAX pow(2,31)-1

int Solution::myAtoi(string s) {
    if (s == "")
        return 0;
    double result;
    int i, sign = 1;
    vector<int> digits;
    // Ignore leading whitespace
    for (i = 0; i < s.length() && s[i] == ' '; i++) ;
    // Check for sign
    if (i < s.length() && s[i] == '-') {
        sign = -1;
        i++;
    }
    else if (i < s.length() && s[i] == '+') 
        i++;
    // Read digits
    for (; (i < s.length()) && (s[i] >= '0') && (s[i] <= '9'); i++) {
        int digit = (int) (s[i] - '0');
        digits.push_back(digit);  
    }
    // Compute the result
    int power = digits.size() - 1;
    for (int i = 0; i < digits.size(); i++) {
        result += digits[i] * pow(10, power);
        power--;
    }
    result *= sign;
    if (result < MIN) 
        result = MIN;
    else if (result > MAX)
        result = MAX;
    return (int) result; 
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 0;
    }
    Solution s;
    string input(argv[1]);
    int output = s.myAtoi(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;
    return 0;
}
