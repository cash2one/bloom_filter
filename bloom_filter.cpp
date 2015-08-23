// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>

#include "bloom_filter/bloom_filter.h"

#include "thirdparty/glog/logging.h"

#include "bloom_filter/hash_utils/hash_function.h"

namespace baidu {
namespace bloom_filter {

bool BloomFilter::init() {
    if (_is_inited) {
        VLOG(20) << "the bloom filter has inited.";
        return true;
    }

    // TODO: unexpeced _bloom_bits size
    _bloom_map = new char[_bloom_bits / 8];
    if (_bloom_map == NULL) {
        VLOG(10) << "new bloom_map failed.";
        return false;
    }

    _hash_value_map = new uint64_t[_hash_list_size];
    if (_hash_value_map == NULL) {
        VLOG(10) << "new hash_map failed.";
        return false;
    }

    _hash_function_list = new hash_function[_hash_list_size];
    if (_hash_function_list == NULL) {
        VLOG(10) << "new hash_function_list failed.";
        return false;
    }

    _is_inited = true;
}

void BloomFilter::uninit() {
    if (_is_inited) {
        delete[] _bloom_map;
        delete[] _hash_value_map;
        _bloom_map = NULL;
        _hash_value_map = NULL;
    }
}

bool BloomFilter::init_hash_function() {
    if (_is_inited) {
        VLOG(20) << "the hash function has inited.";
        return true;
    }

    if (_hash_list_size != 11) {
        return false;
    }

    _hash_function_list[0] = &ap_hash;
    _hash_function_list[1] = &bkdr_hash;
    _hash_function_list[2] = &bp_hash;
    _hash_function_list[3] = &dek_hash;
    _hash_function_list[4] = &djb_hash;
    _hash_function_list[5] = &elf_hash;
    _hash_function_list[6] = &fnv_hash;
    _hash_function_list[7] = &js_hash;
    _hash_funciton_list[8] = &pjw_hash;
    _hash_function_list[9] = &rs_hash;
    _hash_function_list[10] = &sdbm_hash;

    return true;
}

void BloomFilter::do_hash(const std::string& input) {
    for (int i = 0; i < _hash_list_size) {
        _hash_value_map[i] = _hash_function_list[i](input);
    }
}

bool BloomFilter::exists(const std::string& input) {

}

bool BloomFilter::add_ref(const std::string& input) {

}

bool BloomFilter::delete_ref(const std::string& input) {

}

} // namespace bloom_filter
} // namespace baidu


