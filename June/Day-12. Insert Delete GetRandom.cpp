/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 */
 class RandomizedSet {
 public:
     vector<int> numbers;
     unordered_map<int,int> mapping;
     /** Initialize your data structure here. */
     RandomizedSet() {
         numbers.clear();
         mapping.clear();
     }

     /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
     bool insert(int val) {
         if(mapping.find(val) != mapping.end())
             return false;

         mapping[val] = numbers.size();
         numbers.push_back(val);
         return true;
     }

     /** Removes a value from the set. Returns true if the set contained the specified element. */
     bool remove(int val) {
         if(mapping.find(val) == mapping.end())
             return false;
         int index = mapping[val];
         mapping[numbers.back()] = index;
         swap(numbers[index], numbers.back());
         numbers.pop_back();
         mapping.erase(val);
         return true;
     }

     /** Get a random element from the set. */
     int getRandom() {
         int index = rand() % numbers.size();
         return numbers[index];
     }
 };

 /**
  * Your RandomizedSet object will be instantiated and called as such:
  * RandomizedSet* obj = new RandomizedSet();
  * bool param_1 = obj->insert(val);
  * bool param_2 = obj->remove(val);
  * int param_3 = obj->getRandom();
  */
