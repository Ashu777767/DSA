class SmallestInfiniteSet {
public:
    int current;
    set<int> addedBack;

    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!addedBack.empty()) {
            int ans = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return ans;
        }

        return current++;
    }

    void addBack(int num) {
        if (num < current) {
            addedBack.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */