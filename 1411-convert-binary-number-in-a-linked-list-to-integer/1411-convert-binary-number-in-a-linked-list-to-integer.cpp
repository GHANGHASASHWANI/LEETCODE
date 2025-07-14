/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> findEle(ListNode* head) {
        vector<int> result;

        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }
    int getDecimalValue(ListNode* head) {
        vector<int> binary = findEle(head);

        int number = 0, n = binary.size();

        for (int i = n - 1; i >= 0; i--) {
            if (binary[i] == 1) number += pow(2, n - i - 1);
        }
        return number;
    }
};