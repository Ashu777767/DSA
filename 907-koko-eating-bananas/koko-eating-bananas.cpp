class Solution {
public:
    bool isminimum(vector<int>& piles, int h, int mid, int n) {
        long long hours = 0;
        for (int i = 0; i < n; i++) {
            hours += (piles[i] + mid - 1) / mid;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());  // max speed needed
        int ans = e;
        int n = piles.size();

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isminimum(piles, h, mid, n)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};