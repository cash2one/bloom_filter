// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>

#ifndef BLOOM_FILTER_HASH_UTILS_HASH_FUNCTION_H
#define BLOOM_FILTER_HASH_UTILS_HASH_FUNCTION_H

#include <string>

namespace baidu {
namespace bloom_filter {

typedef uint64_t(*hash_function)(const std::string& input);

uint64_t ap_hash(const std::string& input);

uint64_t bkdr_hash(const std::string& input);

uint64_t bp_hash(const std::string& input);

uint64_t dek_hash(const std::string& input);

uint64_t djb_hash(const std::string& input);

uint64_t elf_hash(const std::string& input);

uint64_t fnv_hash(const std::string& input);

uint64_t js_hash(const std::string& input);

uint64_t pjw_hash(const std::string& input);

uint64_t rs_hash(const std::string& input);

uint64_t sdbm_hash(const std::string& input);

} // namespace bloom_filter
} // namespace baidu

#endif // BLOOM_FILTER_HASH_UTILS_HASH_FUNCTION_H

