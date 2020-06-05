/*
Given an array w of positive integers, where w[i] describes the weight of index i,
write a function pickIndex which randomly picks an index in proportion to its weight.
*/
class Solution {
public:
    vector<int> prefix;
    int total;
    Solution(vector<int>& w) {
        for(int weight : w) {
            if(prefix.empty()) {
                prefix.push_back(weight);
            }
            else {
                prefix.push_back(weight + prefix.back());
            }
        }
        total = prefix.back();
    }

    int pickIndex() {
        int value = rand() % total + 1;
        return lower_bound(prefix.begin(), prefix.end(), value) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
