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
    bool isPalindrome(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* temp1 = head;
        while (temp1) {
            ListNode* newNode = new ListNode(temp1->val);
            temp1 = temp1->next;
            newNode->next = newHead;
            newHead = newNode;
        }
        temp1 = newHead;
        ListNode* temp2 = head;

        while (temp1 and temp2) {
            if (temp1->val != temp2->val) {
                return false;
            }
            cout<<temp1->val <<" "<<temp2->val<<endl;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};