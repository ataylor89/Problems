#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (i == nums1.size()) {
                mergedArray.push_back(nums2[j]);
                j++;
            }
            else if (j == nums2.size()) {
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else {
                int n1 = nums1[i];
                int n2 = nums2[j];
                if (n1 <= n2) {
                    mergedArray.push_back(n1);
                    i++;
                }
                else {
                    mergedArray.push_back(n2);
                    j++;
                }
            }
        }
        if (mergedArray.size() % 2 == 1) {
            int index = mergedArray.size() / 2;
            return (double) mergedArray[index];
        }
        else {
            int index = mergedArray.size() / 2;
            double d1 = (double) mergedArray[index-1];
            double d2 = (double) mergedArray[index];
            return (d1 + d2) / 2;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1, nums2;
    for (int i = 0; i < 100; i += 2) {
        nums1.push_back(i);
        nums2.push_back(i+1);
    }
    double median = s.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    return 0;
}
