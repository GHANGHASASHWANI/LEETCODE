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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> arr;

        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
        map<int,int> mp;
        for(int i=0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        vector<int> last;
        for(auto i : mp){
            if(i.second == 1){
                last.push_back(i.first);
            }
        }
        for(auto i : last){
            cout<<i<<" ";
        }
        ListNode * dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int i=0; i < last.size(); i++){
            ListNode* temp = new ListNode(last[i]);
            dummy->next = temp;
            dummy = dummy->next;
        }

        return curr->next;
    }
};