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

    ListNode* reverse(ListNode* curr, int k, int need, ListNode* head){
        if(need == 0){
            return curr;
        }
        ListNode* prev = head;
        ListNode* temp;
        int itr = k;
        while(k > 0 && curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            k--;
        } 
        head->next = reverse(curr, itr, need -1, curr);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;

        int length = 0;
        while(curr){
            curr = curr->next;
            length++;
        }
        int need = length / k;
        cout<<need<<" ";
        ListNode* ans = reverse(head, k, need, head);

        return ans;
    }
};