class Solution {
public:
    int PossibleDivision(vector<int>& nums,int val){
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum = sum +  ceil((double)(nums[i])/(double) (val));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(nums[i],maxi);
        }

        int low = 1;
        int high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(PossibleDivision(nums,mid)<=threshold){
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return low ;
    }
};