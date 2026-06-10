class SmallestInfiniteSet {
public:
    int number = 1;
    unordered_set<int>s;
    SmallestInfiniteSet() {
        number = 1;
    }
    
    int popSmallest() {
         int val = number;
         bool flag = 0;
         while(s.count(number)){
            flag = 1;
         number++;
         }
        if(flag) val = number;
         number++;

         s.insert(val);
         return val;
    }
    
    void addBack(int num) {
        if(num<number ) {
        number = num;
        s.erase(number);
        }else if(s.count(num)) s.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */