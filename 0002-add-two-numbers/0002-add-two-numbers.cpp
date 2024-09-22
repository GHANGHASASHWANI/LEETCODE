class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(0); // Dummy node
        ListNode* current = dummy; // Pointer to traverse 

        // Traverse both lists
        while (t1 || t2 || carry) {
            int sum = carry;
            if (t1) {
                sum += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                sum += t2->val;
                t2 = t2->next;
            }
            carry = sum / 10; // Update the carry 
            current->next = new ListNode(sum % 10); // Create new node
            current = current->next; // Move to the next node
        }

        return dummy->next; // Return the head next to the dummy value -1.
    }
};
