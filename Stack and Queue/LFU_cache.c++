#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>

using namespace std;

struct Node {
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
        size++;
    }

    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        
        List* nextHigherFreqList;
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } else {
            nextHigherFreqList = new List();
            freqListMap[node->cnt + 1] = nextHigherFreqList;
        }

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;  
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }

            curSize++;
            minFreq = 1;
            List* listFreq;

         
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            } else {
                listFreq = new List();
                freqListMap[minFreq] = listFreq;
            }

            Node* node = new Node(key, value);  
            listFreq->addFront(node);
            keyNode[key] = node;
        }
    }
};
