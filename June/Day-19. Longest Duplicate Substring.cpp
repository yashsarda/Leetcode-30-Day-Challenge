/*
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)
Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)
 */
 /*
 Binary search on length

 How to efficiently find if there is a duplicate string present
 We can go through all the substring of a particular length

 Calculate the hash and store in a hashset.
 If the hash is already present in a hashset then we have found a duplicate string

 Use the Rabin Karp algorithm
 Needed hints to solve this
 */
 class Solution {
 public:
     typedef long long ll;
     int mod = 1e9 + 7;
     vector<ll> ppow;
     inline ll add(ll a, ll b)
     {
         a += b;
         if(a >= mod)
             a -= mod;
         return a;
     }
     inline ll sub(ll a, ll b)
     {
         a -= b;
         if(a < 0)
             a += mod;
         return a;
     }
     inline ll mul(ll a, ll b)
     {
         return (a * b) % mod;
     }
     int checkDuplicate(string s, int len)
     {
         if(len == 0)
             return 0;
         int n = s.size();
         long long hash = 0;
         unordered_map<ll, int> hashes;
         for(int i = 0; i < len; i++) {
             hash = add(hash, mul((s[i] - 'a' + 1),ppow[len - i - 1]));
         }
         hashes[hash] = 0;

         for(int i = len; i < n; i++) {
             hash = sub(hash, mul((s[i - len] - 'a' + 1), ppow[len - 1]));
             hash = mul(hash, 26);
             hash = add(hash, s[i] - 'a' + 1);
             // If the hashes match, there might still be the possibility of collision
             // So the resolve that we have to compare character by character
             if(hashes.find(hash) != hashes.end()) {
                 bool found = true;
                 int start = hashes[hash];
                 int k = 1;
                 for(int j = start; j < start + len; j++) {
                     if(s[j] != s[i - len + k]) {
                         found = false;
                         break;
                     }
                     k++;
                 }
                 if(found)
                     return hashes[hash];
             }
             hashes[hash] = i - len + 1;
         }
         return -1;

     }
     string longestDupSubstring(string S) {
         int n = S.size();

         int lower = 0;
         int upper = n;

         string answer = "";
         ppow.clear();
         ppow.resize(n + 1, 1);

         for(int i = 1; i <= n; i++) {
             ppow[i] = mul(ppow[i - 1], 26);
         }
         while(lower <= upper) {
             int mid = lower + (upper - lower) / 2;
             int value = checkDuplicate(S, mid);
             if(value != -1) {
                 answer = S.substr(value, mid);
                 lower = mid + 1;
             }
             else {
                 upper = mid - 1;
             }
         }

         return answer;
     }
 };
