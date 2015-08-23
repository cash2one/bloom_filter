// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>

#include "bloom_filter/hash_utils/hash_function.h"

namespace baidu {
namespace bloom_filter {

uint64_t rs_hash(const std::string& input) {
    uint64_t b    = 378551;
    uint64_t a    = 63689;
    uint64_t hash = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        hash = hash * a + input[i];
        a    = a * b;
    }

    return hash;
}

} // namespace bloom_filter
} // namespace baidu

