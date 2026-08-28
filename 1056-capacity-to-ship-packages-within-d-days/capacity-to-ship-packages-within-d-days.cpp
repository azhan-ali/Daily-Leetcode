
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;

        // Minimum capacity = heaviest package
        // Maximum capacity = total weight
        for (int w : weights) {
            low = max(low, w);
            high += w;
        }

        // Binary Search on answer
        while (low < high) {
            int mid = low + (high - low) / 2;

            int requiredDays = 1;
            int currentWeight = 0;

            for (int w : weights) {
                if (currentWeight + w > mid) {
                    requiredDays++;
                    currentWeight = 0;
                }

                currentWeight += w;
            }

            // If we can ship within 'days',
            // try a smaller capacity
            if (requiredDays <= days) {
                high = mid;
            }
            // Need more capacity
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};

