class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
   while (i < s.size()) {
    // skip spaces
    while (i < s.size() && s[i] == ' ') i++;

    // if not the first word, add one space before word
    if (j > 0 && i < s.size()) {
        s[j++] = ' ';
    }

    // copy characters of the word
    while (i < s.size() && s[i] != ' ') {
        s[j++] = s[i++];
    }
}
s.resize(j);

        reverse(s.begin(),s.end());
        int stw = 0;
        for(int enw = 0;enw<s.size();enw++){
            if(!isalnum(s[enw])){
            reverse(s.begin()+stw,s.begin()+enw);
            stw = enw+1;
            }
            
        }
        int last = s.size() -1;
        while(stw<last){
           swap(s[stw++],s[last--]);
        }

        return s;
    }
};