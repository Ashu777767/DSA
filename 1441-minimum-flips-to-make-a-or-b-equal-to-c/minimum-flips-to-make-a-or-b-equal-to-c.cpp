class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a>0 || b>0 || c>0){
            int bita = a & 1;
            int bitb = b & 1;
            int bitc = c & 1;
            if((bita == 1 && bitb == 1) && bitc == 0){
              count+=2;
            }else if((bita | bitb) != bitc){
                count++;
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return  count;
    }
};