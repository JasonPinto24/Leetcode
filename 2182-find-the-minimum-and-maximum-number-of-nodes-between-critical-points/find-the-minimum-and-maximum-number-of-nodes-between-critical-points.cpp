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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};
        if(!head||!head->next||!head->next->next){
            return ans;
        }
        int first=-1;
        int last=-1;
        int index=1;
        int mindist=INT_MAX;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr->next){
            int value=curr->val;
            if((value>prev->val && value>curr->next->val) ||(value<prev->val && value<curr->next->val) ){
                if(first==-1) first=index;
                else{
                    mindist=min(mindist,index-last);
                }
                last=index;
            }
            prev=curr;
            curr=curr->next;
            index++;
        }
        if(first==-1||first==last) return ans;
        ans[0]=mindist;
        ans[1]=last-first;
        return ans;
    
    }
};