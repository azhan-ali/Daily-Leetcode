class Solution {
public:
    long long sumAndMultiply(int n) {
        int temp = n;
        int sum = 0;

        // Sum of digits of original number
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        // Store non-zero digits
        string str = to_string(n);
        string newStr = "";

        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '0') {
                newStr += str[i];
            }
        }

        // If all digits were zero
        if (newStr.empty()) {
            return 0;
        }

        long long x = stoll(newStr);

        return x * 1LL * sum;
    }
};