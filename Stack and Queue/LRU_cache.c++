#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <stack>

using namespace std; 

class LRUCache {
public:
    class Node{
        public:
            int val;
            int key;
            Node* next;
            Node* prev;
            Node(int key_, int val_){
                key = key_;
                val = val_;
            }
    };
    
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);
int cap;
unordered_map<int,Node*> mpp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newnode){
        Node* temp = head->next;
        head->next = newnode;
        newnode->next = temp;
        newnode-> prev = head;
        temp->prev = newnode;
    }
    
    void deleteNode(Node* delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* resnode = mpp[key];
            int res = resnode->val;
            mpp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mpp[key] = head->next;
            return res;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* existingNode = mpp[key];
            mpp.erase(key);
            deleteNode(existingNode);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mpp[key] = head->next;
        
    }
};