//
// Created by 王秋城 on 2021/1/28.
//

#ifndef LEETCODE_TEST_146_H
#define LEETCODE_TEST_146_H

#include "../common.h"

class LRUCache {
public:
    //https://leetcode-cn.com/problems/lru-cache/
    //最近最少使用，O（1）复杂度
    LRUCache(int capacity) : _capacity(capacity) {
        _dump_head = new DLinkdList();
        _dump_tail = new DLinkdList();
        _dump_head->next = _dump_tail;
        _dump_tail->prev = _dump_head;
    }

    int get(int key) {
        if (_hash.find(key) == _hash.end()) {
            return -1;
        }
        DLinkdList* found_node = _hash[key];
        found_node->next->prev = found_node->prev;
        found_node->prev->next = found_node->next;

        found_node->next = _dump_head->next;
        found_node->prev = _dump_head;

        _dump_head->next->prev = found_node;
        _dump_head->next = found_node;

        return found_node->value;
    }

    void put(int key, int value) {
        if (_hash.find(key) != _hash.end()) {
            _hash[key]->value = value;
            _hash[key]->prev->next = _hash[key]->next;
            _hash[key]->next->prev= _hash[key]->prev;

            _hash[key]->next = _dump_head->next;
            _hash[key]->prev = _dump_head;

            _dump_head->next->prev = _hash[key];
            _dump_head->next = _hash[key];
        } else {
            DLinkdList* new_node = new DLinkdList(key, value);
            _hash[key] = new_node;
            new_node->prev = _dump_head;
            new_node->next = _dump_head->next;

            _dump_head->next->prev = new_node;
            _dump_head->next = new_node;

            if (_hash.size() > _capacity) {
                DLinkdList* to_deleted_node = _dump_tail->prev;
                DLinkdList* new_tail_node = _dump_tail->prev->prev;
                new_tail_node->next = _dump_tail;
                _dump_tail->prev = new_tail_node;
                _hash.erase(to_deleted_node->key);
                delete(to_deleted_node);
            }
        }
    }

private:
    struct DLinkdList {
        int key, value;
        DLinkdList* prev;
        DLinkdList* next;
        DLinkdList() : key(0), value(0), prev(nullptr), next(nullptr) {}
        DLinkdList(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
    };

    DLinkdList* _dump_head;
    DLinkdList* _dump_tail;
    unordered_map<int, DLinkdList*> _hash;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LEETCODE_TEST_146_H
