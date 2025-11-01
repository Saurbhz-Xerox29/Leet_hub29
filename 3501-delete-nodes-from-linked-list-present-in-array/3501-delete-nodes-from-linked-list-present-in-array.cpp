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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        ListNode* ans= NULL;
        ListNode* temp= head;
        ListNode* cnt= NULL;

        while(temp)
        {
            if(mpp.find(temp->val)==mpp.end())
            {
                if(!ans)
                {
                    ans= temp;
                    cnt= temp;
                }
                else
                {
                    cnt->next= temp;
                    cnt=temp;
                }
            }
            temp= temp->next;
        }
        cnt->next=NULL;
        return ans;    
    }
};