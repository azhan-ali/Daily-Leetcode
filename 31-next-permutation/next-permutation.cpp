class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // Find the breakpoint
        int idx = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        // Edge Case [5,4,3,2,1]
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // Find the smallest element greater than nums[idx]
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        // Reverse the suffix 
        reverse(nums.begin() + idx + 1, nums.end());

        return;
    }
};