class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>answers(2);
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int val:nums1) mp1[val]++;
        for(int val:nums2) mp2[val]++;

        for(auto [k,v]:mp1){
            if(mp2.find(k)==mp2.end()){
                answers[0].push_back(k);
            }
        }

          for(auto [k,v]:mp2){
            if(mp1.find(k)==mp1.end()){
                answers[1].push_back(k);
            }
        }
        return answers;

























    }
};