class Solution {
public:
void reverseit(string &s,int start,int val){
    while(start<val){
        swap(s[start++],s[val--]);
    }
}
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        for(int val = 0;val<=n;val++){
            if(s[val] == ' ' || val == n){
                reverseit(s,start,val-1);
                start = val+1;
            }

        }
        return s;
    }
};