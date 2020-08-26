class MyHashSet {
public:
     unordered_set<int> s;
    /** Initialize your data structure here. */
    MyHashSet() {
       s.clear();
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(key);
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(s.count(key)) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */