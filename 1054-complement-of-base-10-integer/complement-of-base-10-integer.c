int bitwiseComplement(int n) {
    if(n == 0){
        return 1;
    }
    int x = 1;
    while(x<=n)
    {
        n = n^x;
       x = x << 1;
    }
    return n;
}