struct node
{
    int val;
    node* prev;
    node* next;
    
    node(int v) {
        val = v;
        prev = next = nullptr;
    }
};
class DLL 
{
    node* head;
    node* rear;
    int counter;
    public:
        
        DLL() {
            head = nullptr;
            rear = nullptr;
            counter = 0;
        }
        node* add_to_head(int value)
        {
            node* new_node = new node(value);
            counter++;
            if(head == nullptr) {
                head = new_node;
                rear = new_node;
                
                return new_node;
            }
            
            new_node -> prev = head;
            head -> next = new_node;
            head = new_node;
            return new_node;
        }
    
        void remove(node* x)
        {
            if(x -> next) {
                if(x -> prev) {
                    x -> next -> prev = x -> prev;
                    x -> prev -> next = x -> next;
                }
                else {
                    x -> next -> prev = nullptr;
                    rear = x -> next;
                }
            }
            else {
                if(x -> prev) {
                    x -> prev -> next = nullptr;
                    head = x -> prev; 
                }
                else {
                    rear = head = nullptr;
                }
            }
            counter--;
            delete x;
        }
        
        bool isEmpty() {
            return (counter == 0);
        }
        node* get_rear() {
            return rear;
        }
};



class FirstUnique {
    unordered_map<int, node*> isPresent;
    DLL* dll;
public:
    FirstUnique(vector<int>& nums) {
        dll = new DLL();
        for(int i = 0; i < nums.size(); i++) {
            if(isPresent.find(nums[i]) != isPresent.end()) {
                node* x = isPresent[nums[i]];
                if(x -> val == -1)
                    continue;
                dll -> remove(x);
                isPresent[nums[i]] = new node(-1);
            }
            else {
                node* n = dll -> add_to_head(nums[i]);
                isPresent[nums[i]] = n;
            }
        }
    }

    int showFirstUnique() {
        if(dll -> isEmpty())
            return -1;
        
        return dll -> get_rear() -> val;
    }
    
    void add(int value) {
        if(isPresent[value]) {
            node* x = isPresent[value];
            if(x -> val == -1)
                return;
            dll -> remove(x);
            isPresent[value] = new node(-1);
        }
        else {
            node* n = dll -> add_to_head(value);
            isPresent[value] = n;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */