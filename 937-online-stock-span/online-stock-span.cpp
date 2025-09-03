class StockSpanner {
public:
   stack<pair<int,int>>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(true){
            if(s.empty() || s.top().first>price){
                s.push({price,span});
                return span;
            }
            else{
                span+=(s.top().second);
                s.pop();
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */