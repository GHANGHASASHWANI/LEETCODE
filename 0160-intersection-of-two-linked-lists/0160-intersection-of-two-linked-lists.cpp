/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int length(ListNode* temp1) {
        if (!temp1) return 0;
        int count = 0;
        while (temp1) {
            count++;
            temp1 = temp1->next;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = length(headA);
        int length2 = length(headB);

        int need = 0;
        ListNode* temp = headA;
        ListNode* dummy = headA;
        if (length1 >= length2) {
            need = length1 - length2;
            temp = headA;
            dummy = headB;
        } else {
            need = length2 - length1;
            temp = headB;
            dummy = headA;
        }

        while (need--) {
            temp = temp->next;
        }
        while (temp && dummy) {
            if(temp == dummy) return temp;
            temp = temp->next;
            dummy = dummy->next;
        }
        return NULL;
    }
};