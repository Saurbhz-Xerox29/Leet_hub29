class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mpp;
    int i = 0, r = 0;
    int ans = 0;

    while (r < s.size()) {
        mpp[s[r]]++;

        // If there's a duplicate, shrink window from the left
        while (mpp[s[r]] > 1) {
            mpp[s[i]]--;
            i++;
        }

        ans = max(ans, r - i + 1);
        r++;
    }

    return ans;
}

};