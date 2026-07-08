class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int tsz = t.size();
        int count = 0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(n==tsz){
            for(int i=0;i<n;i++){
            if(s[i] == t[i]) count++;
        }
            if(count==n) return true;
            else{
                return false;
            }
        } else{
            return false;
        }
        
    }
};