/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i = 0;i < nums.size();i++) {
            if(i < nums.size()-1 && nums[i] == nums[i+1])
                i++;
            else {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        nums.erase(nums.begin()+2,nums.end());
        
        return nums;
    }
};