// 双向链表
struct doubleLinkedNode {
    int value, key;
    doubleLinkedNode* prev;
    doubleLinkedNode* next;
    doubleLinkedNode(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
    int capacity = 0;
    // hash表用于存储数据在链表中的位置(key, pos)
    unordered_map<int, doubleLinkedNode*> cache;
    doubleLinkedNode* head;
    doubleLinkedNode* tail;

    void moveToHead(doubleLinkedNode* node) {
        // pop
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // addToHead
        addToHead(node);
    }

    void addToHead(doubleLinkedNode* node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }

    void removeTail() {
        auto oldTail = tail->prev;
        auto newTail = oldTail->prev;
        newTail->next = tail;
        tail->prev = newTail;
        cache.erase(oldTail->key);
        // delete tail->prev;
    }

public:
    LRUCache(int capacity) {
        head = new doubleLinkedNode(888, 888);
        tail = new doubleLinkedNode(-666, -666);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    ~LRUCache() {
        //TODO free cache
    }
    
    int get(int key) {
        // (查)
        if (cache.find(key) == cache.end()) return -1;
        moveToHead(cache[key]);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            // key不存在(增)
            cache[key] = new doubleLinkedNode(key, value);
            addToHead(cache[key]);
        } else {
            // key已存在(改)
            cache[key]->value = value;
            moveToHead(cache[key]);
        }
        if (cache.size() > capacity) {
            // (删)
            removeTail();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */