//
// Created by 王秋城 on 2021/1/29.
//

#ifndef LEETCODE_TEST_208_H
#define LEETCODE_TEST_208_H

#include "common.h"

struct TrieNode {
    bool isWord;
    TrieNode* children[26];
    TrieNode() : isWord(false) {
        for (auto& child : children) {
            child = nullptr;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (const auto& ch : word) {
            int i = ch - 'a';
            if (!p->children[i]) {
                p->children[i] = new TrieNode();
            }
            p = p->children[i];
        }

        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (const auto& ch : word) {
            int i = ch - 'a';
            if (!p->children[i]) {
                return false;
            } else {
                p = p->children[i];
            }
        }

        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (const auto& ch : prefix) {
            int i = ch - 'a';
            if (!p->children[i]) {
                return false;
            } else {
                p = p->children[i];
            }
        }

        return true;

    }

private:
    TrieNode* root;
};

#endif //LEETCODE_TEST_208_H
