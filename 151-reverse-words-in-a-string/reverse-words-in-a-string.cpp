class Solution {
public:
string trim(string &s) {
        int start = s.find_first_not_of(' ');
        if (start == string::npos) {
            return "";
        }

        int end = s.find_last_not_of(' ');
        return s.substr(start, end - start + 1);
    }
void reverseword(string &s,int first ,int end){
    while(first<end){
        swap(s[first++],s[end--]);
    }
}
void stringreverse(string &s,int start,int e){
   while(start<e){
    swap(s[start++],s[e--]);
   }
}
    string reverseWords(string s) {
        s = trim(s);
        int i = 0,j = 0;
      int n = s.size();
      while(j<n){
      while(j<n && s[j] == ' '){
        j++;
      }
        if(j<n){
            if(i!= 0)
            s[i++] = ' ';
            while(j<n && s[j]!= ' '){
                s[i++] = s[j++];
            }
        }
      }
       s.resize(i);
        n = s.size();
        stringreverse(s,0,n-1);
        int first = 0;

        for(int end = 0;end<=n;end++){
            if(s[end] == ' '|| end == n){
                reverseword(s,first,end-1);
                first = end+1;
            }
        }
    return s;
    }
};