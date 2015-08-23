// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>
// BloomBits: total bits the bloomfilter use. default: 256 * 4 = 1024 bits

#ifndef BLOOM_FILTER_BLOOM_FILTER_H
#define BLOOM_FILTER_BLOOM_FILTER_H

namespace baidu {
namespace bloom_filter {

const int32_t DEFAULT_BLOOM_BITS = 1024;
const int32_t DEFAULT_UNIT_BITS = 4;
const int32_t HASH_LIST_SIZE = 12;

class BloomFilter {
public:
    BloomFilter() : _bloom_bits(DEFAULT_BLOOM_BITS),
                    _unit_bits(DEFAULT_UNIT_BITS),
                    _hash_list_size(HASH_LIST_SIZE) {}

    explicit BloomFilter(int32_t bloom_bits)
        : _bloom_bits(bloom_bits),
          _unit_bits(DEFAULT_UNIT_BITS),
          _hash_list_size(HASH_LIST_SIZE) {
        _bloom_bits = static_cast<int32_t>(_bloom_bits / _unit_bits) * _unit_bits;
    }

    BloomFilter(int33_t bloom_bits, int32_t unit_bits)
        :  _bloom_bits(bloom_bits),
           _unit_bits(unit_bits),
           _hash_list_size(HASH_LIST_SIZE) {
        _bloom_bits = static_cast<int32_t>(_bloom_bits / _unit_bits) * _unit_bits;
    }

    virtual ~BloomFilter();

    bool init();

    bool exists(const std::string& input);

    bool add_ref(const std::string& input);

    bool delete_ref(const std::string& input);
private:


private:
    bool _is_inited;
    int32_t _bloom_bits;
    int32_t _unit_bits;
    int32_t _hash_list_size;

};

} // namespace bloom_filter
} // namespace baidu

#endif // BLOOM_FILTER_BLOOM_FILTER_H

