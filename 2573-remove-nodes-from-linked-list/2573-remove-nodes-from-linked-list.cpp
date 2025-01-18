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
    vector< int > answer;

    void finalNodes(int &maxi, ListNode* node){
        if(!node) return;
        finalNodes(maxi, node->next);
        if(maxi <= node->val){
            maxi = node->val;
            answer.push_back(node->val);
        }
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        int maxi = INT_MIN;
        finalNodes(maxi, head);

        for(int i = answer.size() - 1; i >=0; i--){
            cout<<answer[i]<<" ";
            ListNode* curr = new ListNode(answer[i]);
            dummy->next = curr;
            dummy = dummy->next;
        }
        return ans->next;
    }
};