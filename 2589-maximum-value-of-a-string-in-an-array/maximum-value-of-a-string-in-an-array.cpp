class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int n = strs.size();
        int max_value = 0;

        for (int i = 0; i < n; i++) {
            bool isNumber = true;

            for (char c : strs[i]) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }

            int x;
            if (isNumber)
                x = stoi(strs[i]);
            else
                x = strs[i].size();

            if (x > max_value)
                max_value = x;
        }

        return max_value;
    }
};