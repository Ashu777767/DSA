class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        long long ans = 0;

        int left = -1;
        int right = costs.size();

        // Initial filling
        for (int i = 0; i < candidates && left + 1 < right; i++) {

            left++;
            pq.push({costs[left], left});

            if (left + 1 < right) {
                right--;
                pq.push({costs[right], right});
            }
        }

        // k selections
        while (k--) {

            auto [cost, index] = pq.top();
            pq.pop();

            ans += cost;

            // Selected from LEFT candidate group
            if (index <= left) {

                if (left + 1 < right) {
                    left++;
                    pq.push({costs[left], left});
                }
            }

            // Selected from RIGHT candidate group
            else {

                if (left + 1 < right) {
                    right--;
                    pq.push({costs[right], right});
                }
            }
        }

        return ans;
    }
};