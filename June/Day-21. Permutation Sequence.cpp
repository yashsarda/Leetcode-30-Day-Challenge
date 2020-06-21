/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
 */
 class Solution {
 public:
     typedef long long ll;
     static const int N = 13;
     ll fact[N];
     void getList(int n,int k,vector<int>& v,vector<int>& ans)
     {
         if(n == 0){
             return;
         }
         int x = k / fact[n-1];
         ans.push_back(v[x]);
         v.erase(remove(v.begin(),v.end(),v[x]),v.end());
         k = k % (fact[n - 1]);
         getList(n - 1,k,v,ans);
         return;
     }
     string convert_to_string(int number)
     {
         stringstream ss;
         string s;
         ss << number;
         s = ss.str();
         return s;
     }
     string getPermutation(int n, int k) {
         fact[0] = 1;
         for(int i=1;i<10;i++)
             fact[i] = fact[i-1] * i;
         vector<int> v;
         vector<int> ans;
         for(int i=1;i<=n;i++)
             v.push_back(i);
         getList(n,k-1,v,ans);
         string an = "";
         for(int i=0;i<ans.size();i++){
             an = an + convert_to_string(ans[i]);
         }
         return an;
     }
 };
