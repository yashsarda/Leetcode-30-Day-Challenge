/*
Implement a trie with insert, search, and startsWith methods.
*/
struct Node
{
    char value;
    Node* arr[26];
    bool isLeaf;
    Node(int val) 
    {
        isLeaf = false;
        value = val;
        for(int i = 0; i < 26; i++)
            arr[i] = nullptr;
    }
};
class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        Node* first = root;
        for(int i = 0; i < n; i++) {
            char c = word[i];
            if(first -> arr[c - 'a'] == nullptr) {
                Node* newNode = new Node(c);
                first -> arr[c - 'a'] = newNode;
            }
            first = first -> arr[c - 'a'];
        }
        first -> isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        Node* first = root;
        for(int i = 0; i < n; i++) {
            char c = word[i];
            if(first -> arr[c - 'a'] == nullptr)
                return false;
            first = first -> arr[c - 'a'];
        }
        return first -> isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* first = root; 
        for(int i = 0; i < n; i++) {
            char c = prefix[i];
            if(first -> arr[c - 'a'] == nullptr)
                return false;
            first = first -> arr[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */