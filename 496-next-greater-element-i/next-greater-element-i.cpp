class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;//to store nums2 element and next greater element pair
        stack<int>s;
        for(int i = (nums2.size()-1) ;i>=0;i--){
             while(s.size()>0 && s.top()<=nums2[i]){   //right element exist karta hai lekin greater nhi hai toh pop
                s.pop();
             }
             if(s.empty()){   //matlab mila hi nahi greater element right side
                 map[nums2[i]] = -1;
             }
             else{   //mil gaya greater element
                 map[nums2[i]] = s.top();
             }
             s.push(nums2[i]);
        }
         vector<int>ans;       //
        for(int val:nums1){
             ans.push_back(map[val]);
        }
        return ans;
    }
};