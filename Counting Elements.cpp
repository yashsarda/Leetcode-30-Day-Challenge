/*
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1)
            return 0;
        unordered_map<int,int> m;
        for(int element : arr)
            m[element]++;
        
        int answer = 0;
        for(auto it=m.begin();it!=m.end();it++) {
            int value = it -> first;
            if(m.find(value + 1) != m.end())
                answer += it -> second;
        }
        return answer;
    }
};