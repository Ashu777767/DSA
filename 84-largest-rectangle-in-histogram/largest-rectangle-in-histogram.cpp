class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>right(heights.size(),0);
        vector<int>left(heights.size(),0);
        stack<int>s;
        //for right
        for(int i = heights.size()-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
           right[i] = s.empty()?heights.size():s.top() ;
            s.push(i);  //we store only index;
        }
        //for left
        while(!s.empty()){
            s.pop();
        }
        for(int i = 0;i<heights.size();i++){
             while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            left[i] = s.empty()?-1:s.top();
            s.push(i);
        }
        int ans = INT_MIN;
        for(int i = 0;i<heights.size();i++){
            int width =  (right[i]-left[i]-1);
            int height = heights[i];
            ans =  max(ans,(height*width));
        }
        return ans;
    }
};