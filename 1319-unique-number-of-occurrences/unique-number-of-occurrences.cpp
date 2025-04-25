class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> freqMap;
    unordered_set<int> freqSet;

    
    for (int num : arr) {
        freqMap[num]++;
    }

    for (auto pair : freqMap) {
        if (freqSet.find(pair.second) != freqSet.end()) {
            return false;
        }
        freqSet.insert(pair.second);
    }

    return true; 
    }
};