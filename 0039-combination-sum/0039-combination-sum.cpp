class Solution {
public:

    void backtrack(int ind,vector<int> curr,vector<vector<int>> &res,vector<int> candidates,int target)
    {
        if(target==0)
        {
            res.push_back(curr);
            return ;
        }
        for(int i=ind;i<candidates.size();i++)
        {
            if(candidates[i]>target) continue;
            
            curr.push_back(candidates[i]);
            backtrack(i,curr,res,candidates,target-candidates[i]);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0,curr,res,candidates,target);
        return res;
    }
};