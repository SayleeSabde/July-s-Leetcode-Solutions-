/*Given a set of distinct integers, nums, return all possible subsets (the power set).*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int i = 0,j = 0;
        vector<vector<int>> res;
        vector<int>tmp;
        int count = pow(2,nums.size());
        for(int i = 0;i < count;i++) {
            for(int j = 0;j < nums.size();j++) {
               if((i & (1 << j)) > 0)
                   tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        
        return res;
    }
};