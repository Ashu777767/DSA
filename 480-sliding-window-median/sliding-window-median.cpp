class Solution {
public:
    priority_queue<int> maxHeap; // left
    priority_queue<int, vector<int>, greater<int>> minHeap; // right

    unordered_map<int,int> delayed;

    int smallSize = 0; // valid elements in maxHeap
    int largeSize = 0; // valid elements in minHeap

    void pruneMax() {
        while(!maxHeap.empty() && delayed[maxHeap.top()]) {
            delayed[maxHeap.top()]--;
            maxHeap.pop();
        }
    }

    void pruneMin() {
        while(!minHeap.empty() && delayed[minHeap.top()]) {
            delayed[minHeap.top()]--;
            minHeap.pop();
        }
    }

    void balance() {
        // left too big
        if(smallSize > largeSize + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            smallSize--;
            largeSize++;
            pruneMax();
        }
        // right too big
        else if(smallSize < largeSize) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            largeSize--;
            smallSize++;
            pruneMin();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for(int i = 0; i < nums.size(); i++) {

            // INSERT
            if(maxHeap.empty() || nums[i] <= maxHeap.top()) {
                maxHeap.push(nums[i]);
                smallSize++;
            } else {
                minHeap.push(nums[i]);
                largeSize++;
            }

            balance();

            // REMOVE element out of window
            if(i >= k) {
                int out = nums[i-k];
                delayed[out]++;

                if(out <= maxHeap.top()) {
                    smallSize--;
                    if(out == maxHeap.top()) pruneMax();
                } else {
                    largeSize--;
                    if(out == minHeap.top()) pruneMin();
                }

                balance();
            }

            // GET MEDIAN
            if(i >= k-1) {
                pruneMax();
                pruneMin();

                if(k % 2)
                    ans.push_back(maxHeap.top());
                else
                    ans.push_back(( (double)maxHeap.top() + (double)minHeap.top() ) / 2.0);
            }
        }

        return ans;
    }
};