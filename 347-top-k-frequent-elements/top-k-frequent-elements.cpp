class Solution {
public:

    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> freqMap;
    for (int item : arr) {
        freqMap[item]++;
    }
    
    vector<vector<int>> buckets(arr.size() + 1);
    for (auto& pair : freqMap) {
        buckets[pair.second].push_back(pair.first);
    }
    
    vector<int> res;
    for (int i = buckets.size() - 1; i >= 0 && res.size() < k; --i) {
        for (int item : buckets[i]) {
            res.push_back(item);
            if (res.size() == k) return res;
        }
    }
    
    return res;
    }
};