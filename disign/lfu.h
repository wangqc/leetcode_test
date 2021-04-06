//
// Created by 王秋城 on 2021/4/6.
//

#ifndef LEETCODE_TEST_LFU_H
#define LEETCODE_TEST_LFU_H

#include "../common.h"

// 460:https://leetcode-cn.com/problems/lfu-cache/
class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        min_freq = 0;
        key_map.clear();
        freq_map.clear();
    }

    int get(int key) {
        if (_capacity == 0) return -1;
        auto it = key_map.find(key);
        if (it == key_map.end()) return -1;
        auto node = it->second;
        int val = node->value, freq = node->freq;
        freq_map[freq].erase(node);
        if (freq_map[freq].empty()) {
            freq_map.erase(freq);
            if (min_freq == freq) {
                min_freq++;
            }
        }
        Node cache(key, val, ++freq);
        freq_map[freq].push_front(cache);
        key_map[key] = freq_map[freq].begin();
        return val;
    }

    void put(int key, int value) {
        if (_capacity == 0) return;
        auto it = key_map.find(key);
        if (it == key_map.end()) {
            if (key_map.size() == _capacity) {
                key_map.erase(freq_map[min_freq].back().key);
                freq_map[min_freq].pop_back();
                if (freq_map[min_freq].empty()) {
                    freq_map.erase(min_freq);
                }
            }
            Node cache(key, value, 1);
            freq_map[1].push_front(cache);
            key_map[key] = freq_map[1].begin();
            min_freq = 1;
        } else {
            auto node = it->second;
            int freq = node->freq;
            freq_map[freq].erase(node);
            if (freq_map[freq].empty()) {
                freq_map.erase(freq);
                if (min_freq == freq) {
                    min_freq++;
                }
            }
            Node cache(key, value, ++freq);
            freq_map[freq].push_front(cache);
            key_map[key] = freq_map[freq].begin();
        }
    }

private:
    struct Node {
        int key, value, freq;
        Node(int _key, int _value, int _freq) : key(_key), value(_value), freq(_freq) {}
    };
    int _capacity, min_freq;
    unordered_map<int, list<Node>::iterator> key_map;
    unordered_map<int, list<Node>> freq_map;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //LEETCODE_TEST_LFU_H
