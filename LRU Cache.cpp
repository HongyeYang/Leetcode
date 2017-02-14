class LRUCache {
public:
    //node structure for two-linked list
    struct node{
        int key;
        int val;
        node* pre;
        node* next;
        node(int k,int v):key(k),val(v),pre(NULL),next(NULL){};
    };
    //init data_structure
    unordered_map<int,node*>roc;
    node* head;
    node* tail;
    int size;
    
    
    LRUCache(int capacity) {
        if(capacity<0)return;
        size=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->pre=head;
        roc.clear();
    }
    
    int get(int key) {
        unordered_map<int,node*>::iterator it=roc.find(key);
        if(it!=roc.end()){
            node* cur=it->second;
            cur->pre->next=cur->next;
            cur->next->pre=cur->pre;
            to_head(cur);
            return cur->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(roc.find(key)!=roc.end()){
            node* cur=roc[key];
            cur->val=value;
            cur->pre->next=cur->next;
            cur->next->pre=cur->pre;
            to_head(cur);
        }
        else{
            node * newNode=new node(key,value);
            to_head(newNode);
            roc[key]=newNode;
            if(roc.size()>size){
                node* d=tail->pre;
                d->pre->next=tail;
                tail->pre=d->pre;
                roc.erase(d->key);
                delete d;
            }
        }
    }
    
    void to_head(node* cur){
        cur->next=head->next;
        cur->next->pre=cur;
        head->next=cur;
        cur->pre=head;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
