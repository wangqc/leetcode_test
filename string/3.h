//
// Created by wangqiucheng on 2020/7/20.
//

#ifndef LEETCODE_TEST_3_H
#define LEETCODE_TEST_3_H

#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 解法1: 哈希表
    // 1. 核心点在于碰撞了之后, 肯定是从碰撞之后开始记录, 但不一定是碰撞后一位, 因为之前可能已经因为其他碰撞后移了
    // 2. 由1可知, 更新当前最大长度的时候, 需要判断当前计算的开头是哪个
    // 3. 最后退出循环的时候也要考虑结束动作
    // 感觉用双指针会更方便
    int lengthOfLongestSubstringV1(string s) {
        int size = s.size();
        if (size <= 1) {
            return size;
        }

        unordered_map<char, int> ch_idx_map;
        int max_len = 0;
        int cur_max_len = 0;
        int cur_start_idx = 0;
        for (int i = 0; i < size; ++i) {
            if (ch_idx_map.find(s[i]) == ch_idx_map.end()) {
                cur_max_len += 1;
            } else {
                if (cur_max_len > max_len) {
                    max_len = cur_max_len;
                }
                int hit_idx = ch_idx_map[s[i]];
                cur_max_len = i - max(hit_idx, cur_start_idx - 1);
                cur_start_idx = max(hit_idx + 1, cur_start_idx);
            }
            ch_idx_map[s[i]] = i;
        }
        if (cur_max_len > max_len) {
            max_len = cur_max_len;
        }
        return max_len;
    }


    // 滑动窗口解法
    // 需要画图才能比较了解
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch_set;
        int size = s.size();

        int end, max_len;
        end = max_len = 0;
        for (int i = 0; i < size; ++i) {
            if (i != 0) {
                ch_set.erase(s[i-1]);
            }
            while (end < size && !ch_set.count(s[end])) {
                ch_set.insert(s[end]);
                end++;
            }
            max_len = max(max_len, end - i);
        }
        return max_len;
    }
};

#endif //LEETCODE_TEST_3_H
