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
    void merge(ListNode* &list1, ListNode* &list2){
           if(list1 && list2 && list1->val <= list2->val){
            ListNode* dummy = list1->next;
            list1->next = list2;
            merge(dummy, list2);
           }
           else if(list1 && list2 && list1->val >= list2->val){
            ListNode* dummy = list2->next;
            list2->next = list1;
            merge(list1, dummy);
           }
           
            if(!list1 && list2){
            list1  = list2;
            return;
           }else if(!list2 && list1){
            list2 = list1;
            return;
           }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        if(!list1 && !list2){
            return NULL;
        }
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        if(list1-> val <= list2->val){
            ans = list1;
        }else{
            ans = list2;
        }
        merge(list1, list2);
        return ans;
    }
};