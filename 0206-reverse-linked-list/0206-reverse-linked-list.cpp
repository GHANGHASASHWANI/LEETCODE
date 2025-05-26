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
private:
    ListNode* reverse(ListNode* head, ListNode* &ans) {
        if (!head || !head->next) {
            ans = head;
            return head;
        }
        ListNode* currHead = head;
        ListNode* newHead = reverse(head->next, ans);
        newHead->next = currHead;
        currHead->next = NULL;
        return currHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* anss = NULL;
        ListNode* ans = reverse(head, anss);
        return anss;
    }
};