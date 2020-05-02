/*
Given an array of strings, group anagrams together.
*/

/*
Consider every string, find it's characters frequency
Then for that string loop over all the other string, and check it they have same frequency of character
But this will take O(n * k)
*/
class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string> > answer;
        int n = s.size();
        if(n == 0)
            return answer;
        if(n == 1) {
            answer.push_back(s);
            return answer;
        }
        
        map<vector<int>, vector<string> > m;
        for(int i=0;i<n;i++) {
            vector<int> freq(26, 0);
            int si = s[i].size();
            for(int j=0;j<si;j++)
                freq[s[i][j] - 'a']++;
            m[freq].push_back(s[i]);
        }
        
        for(auto it=m.begin();it!=m.end();it++) {
            answer.push_back(it -> second);
        }
        return answer;
        
    }
};