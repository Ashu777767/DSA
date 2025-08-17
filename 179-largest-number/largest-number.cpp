bool comparator(int a,int b){
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
class Solution {

public:
    string largestNumber(vector<int>& nums) {
        string output = "";
        sort(nums.begin(),nums.end(),comparator);
        for(int val:nums){
            output+=to_string(val);
        }
        if(output[0] == '0') return "0";

        return output;
    }
};