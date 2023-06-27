#include "ReverseInteger.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MIN -1*pow(2, 31)
#define MAX pow(2,31)-1

int Solution::reverse(int x) {
    vector<int> digits;
    while (x != 0) {
        int digit = x % 10;
        digits.push_back(digit);
        x /= 10;
    }
    double result;
    for (int i = 0; i < digits.size(); i++) {
        int power = digits.size() - 1 - i;
        result += digits[i] * pow(10, power); 
    }
    if (result < MIN || result > MAX)
        return 0;
    return (int) result;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 0;
    }
    int x = atoi(argv[1]);
    cout << "x: " << x << endl;
    Solution s;
    int result = s.reverse(x);
    cout << "Result: " << result << endl;
    return 0;
}
