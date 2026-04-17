
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();

        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push(i);
            else d.push(i);
        }

        // Step 2: simulate rounds
        while (!r.empty() && !d.empty()) {
            int rIdx = r.front(); r.pop();
            int dIdx = d.front(); d.pop();

            if (rIdx < dIdx) {
                // R acts first → bans D
                r.push(rIdx + n);
            } else {
                // D acts first → bans R
                d.push(dIdx + n);
            }
        }

        // Step 3: result
        return r.empty() ? "Dire" : "Radiant";
    }
};