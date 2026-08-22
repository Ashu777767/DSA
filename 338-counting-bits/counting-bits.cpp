class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
    int i = 0;
    while(i<=n){
        int sum = 0;
        int num = i;
        while(num!= 0){
            sum+= (num%2);
            num/=2;
        }
        ans.push_back(sum);
     i++;
    }
    return ans;
    }
};