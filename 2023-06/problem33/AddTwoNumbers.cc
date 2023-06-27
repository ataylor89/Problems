#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* tail = head;
        int remainder = 0;
        while (l1 != NULL || l2 != NULL || remainder > 0) {
            int sum = remainder;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            tail->val = sum % 10;
            remainder = (sum - tail->val)/10;
            if (l1 != NULL || l2 != NULL || remainder > 0) {
                tail->next = new ListNode;
                tail = tail->next;
            }
        }
        return head;
    }

    ListNode* toList(int n) {
        ListNode* head = new ListNode;
        ListNode* tail = head;
        while (n > 0) {
            int ones_digit = n % 10;
            n -= ones_digit;
            n /= 10;
            tail->val = ones_digit;
            tail->next = new ListNode;
            tail = tail->next;
        }
        return head;
    }

    int toInt(ListNode* l) {
        int n = 0;
        int multiplier = 1;
        while (l != NULL) {
            n += l->val * multiplier;
            multiplier *= 10;
            l = l->next;
        }
        return n;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode *num1 = s.toList(342);
    ListNode *num2 = s.toList(465);
    ListNode *sum = s.addTwoNumbers(num1, num2);
    int op1 = s.toInt(num1);
    int op2 = s.toInt(num2);
    int result = s.toInt(sum);
    cout << op1 << "+" << op2 << "=" << result << endl;   
    return 0;
}
