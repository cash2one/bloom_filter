// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>

#include "bloom_filter/hash_utils/hash_function.h"

namespace baidu {
namespace bloom_filter {

uint64_t pjw_hash(const std::string& input) {
    uint64_t bits = sizeof(uint64_t) * 8;
    uint64_t three_quarters = static_cast<uint64_t>((bits  * 3) / 4);
    uint64_t one_eighth = static_cast<uint64_t>(bits / 8);
    uint64_t high_bits = static_cast<uint64_t>((0xFFFFFFFF) << (bits - one_eighth));
    uint64_t hash = 0;
    uint64_t test = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        hash = (hash << one_eighth) + input[i];

        if ((test = hash & high_bits)  != 0) {
            hash = ((hash ^ (test >> three_quarters)) & (~high_bits));
        }
    }

    return hash;
}

} // namespace bloom_filter
} // namespace baidu

