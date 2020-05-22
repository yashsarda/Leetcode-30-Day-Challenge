/*
Given a string, sort it in decreasing order based on the frequency of characters.
*/
class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        
        unordered_map<char, int> counter;
        map<int, vector<char> > rev;
        
        for(char c : s)
            counter[c]++;
        
        for(auto it : counter) {
            rev[it.second].emplace_back(it.first);
        }
        
        string answer = "";
        for(auto it = rev.rbegin(); it != rev.rend(); it++) {
            int freq = it -> first;
            vector<char> c = it -> second;
            
            for(char ch : c) {
                int t = freq;
                while(t--) 
                    answer += ch;
            }
        }
        
        return answer;
    }
};