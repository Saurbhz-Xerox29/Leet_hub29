class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        // Check if it's possible to make m bouquets
        if ((long long)m * k > n) return -1;
        
        // Find minimum and maximum bloom days
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        // Binary search for the minimum days
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool isPossible(vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        
        // Count consecutive flowers that have bloomed
        for (int day : bloomDay) {
            if (day <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
};
