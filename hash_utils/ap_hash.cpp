// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>

#include "bloom_filter/hash_utils/hash_function.h"

namespace baidu {
namespace bloom_filter {

uint64_t ap_hash(const std::string& input) {
    uint64_t hash = 0xAAAAAAAA;

    for (size_t i = 0; i < input.length(); ++i) {
        hash ^= ((i & 1) == 0) ? ((hash <<  7) ^ input[i] * (hash >> 3)) :
            (~((hash << 11) + (input[i] ^ (hash >> 5))));
    }

    return hash;
}

} // namespace bloom_filter
} // namespace baidu

