class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> count;
        vector<int> res;

        int limit = cbrt(n);  

        for(int a = 1; a <= limit; a++){
            for(int b = a; b <= limit; b++){
                int sum = a*a*a + b*b*b;

                if(sum > n) break;

                count[sum]++;
            }
        }

        for(auto it : count){
            if(it.second >= 2){
                res.push_back(it.first);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};