class Solution {
public:
    int Possible(vector<int>& bloomDay,int val_day,int m ,int k){
        int cnt = 0;
        int noOb = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=val_day){
                cnt++;
            }
            else{
                noOb += (cnt/k);
                cnt = 0;
            }
        }

        noOb += (cnt/k);
        return noOb >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // Not possible Case 
       long long val = m * 1LL * k * 1LL;
       int n = bloomDay.size();
       if(val > n) return -1; 

       int mini = INT_MAX ; int maxi = INT_MIN;
       for(int i=0;i<n;i++){
        mini = min(mini,bloomDay[i]);
        maxi = max(maxi,bloomDay[i]);
       }

       int low = mini; int high = maxi;
       while(low<=high){
        int mid = low + (high-low)/2;

        if(Possible(bloomDay,mid,m,k)){
            high = mid - 1;
        }
        else low = mid + 1;
       }

       return low ;
    }
};