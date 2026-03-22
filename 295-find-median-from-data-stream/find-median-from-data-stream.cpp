class MedianFinder {
public:
// Left side → max heap (smaller half)
    priority_queue<int> maxHeap;

    // Right side → min heap (larger half)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         // 1. Insert into maxHeap (left side)
        maxHeap.push(num);

        // 2. Move largest of left → right (to maintain order)
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // 3. Balance sizes (left should have >= elements than right)
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
         // If equal size → even case
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // If odd → maxHeap has extra → median
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */