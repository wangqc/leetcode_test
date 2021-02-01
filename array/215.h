//
// Created by 王秋城 on 2021/1/29.
//

#ifndef LEETCODE_TEST_215_H
#define LEETCODE_TEST_215_H

#include "../common.h"
#include "stdlib.h"
#include "time.h"

class SolutionStupid {
public:
    // https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
    // 取巧的做法，不大可取
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (nums.size() < k) {
            return INT_MIN;
        }
        int idx = nums.size() - k;
        return nums[idx];
    }
};

class SolutionQuickSort {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

class Solution {
public:
    void max_heapify(vector<int>& nums, int index, int heap_size) {
        int l = index * 2 + 1, r = index * 2 + 2, largest = index;
        if (l < heap_size && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heap_size && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != index) {
            swap(nums[index], nums[largest]);
            max_heapify(nums, largest, heap_size);
        }
    }

    void build_heap(vector<int> &nums, int heap_size) {
        for (int i = heap_size / 2; i >= 0; --i) {
            max_heapify(nums, i, heap_size);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heap_size = nums.size();
        build_heap(nums, heap_size);
        for (int i = heap_size - 1; i >= 0 && k > 1; --i, --k) {
            swap(nums[0], nums[i]);
            heap_size--;
            max_heapify(nums, 0, heap_size);
        }
        return nums[0];
    }
};

#endif //LEETCODE_TEST_215_H
