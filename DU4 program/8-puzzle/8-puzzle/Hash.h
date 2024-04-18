#pragma once

#include<iostream>
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

struct VectorEqual {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        return a == b;
    }
};