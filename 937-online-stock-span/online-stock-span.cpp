class StockSpanner {
public:
   stack<pair<int,int>>s;
    StockSpanner() {
         
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    
    int next(int price) {
        int span = 1;
           while(!s.empty() && s.top().first<=price){
                span+=(s.top().second);
                s.pop();
           }
                s.emplace(price,span);   //directy pushed the original not the copy
                return span;
            
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */