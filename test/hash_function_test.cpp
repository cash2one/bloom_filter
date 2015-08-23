// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>

#include <iostream>

#include "bloom_filter/hash_utils/hash_function.h"

int main(int argc, char** argv) {
    std::string input = "abcdefg";

    std::cout << "ap_hash:" << baidu::bloom_filter::ap_hash(input) << std::endl;
    std::cout << "bkdr_hash:" << baidu::bloom_filter::bkdr_hash(input) << std::endl;
    std::cout << "bp_hash:" << baidu::bloom_filter::bp_hash(input) << std::endl;
    std::cout << "dek_hash:" << baidu::bloom_filter::dek_hash(input) << std::endl;
    std::cout << "djb_hash:" << baidu::bloom_filter::djb_hash(input) << std::endl;
    std::cout << "elf_hash:" << baidu::bloom_filter::elf_hash(input) << std::endl;
    std::cout << "fnv_hash:" << baidu::bloom_filter::fnv_hash(input) << std::endl;
    std::cout << "js_hash:" << baidu::bloom_filter::js_hash(input) << std::endl;
    std::cout << "pjw_hash:" << baidu::bloom_filter::pjw_hash(input) << std::endl;
    std::cout << "rs_hash:" << baidu::bloom_filter::rs_hash(input) << std::endl;
    std::cout << "sdbm_hash:" << baidu::bloom_filter::sdbm_hash(input) << std::endl;

    return 0;
}

