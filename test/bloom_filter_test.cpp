// Copyright 2015, Baidu Inc. All rights reserved.
// Author: Peng Yong <pengyong@baidu.com>

#include "bloom_filter/bloom_filter.h"

int main(int argc, char** argv) {
    baidu::bloom_filter::BloomFilter bf;

    if (!bf.init()) {
        VLOG(10) << "init bloom_filter failed.";
        return -1;
    }

    std::vector<std::string> inputs;
    inputs.push_back("baidu");
    inputs.push_back("google");
    inputs.push_back("apple");
    inputs.push_back("amazon");

    std::vector<std::string>::iterator iter = inputs.begin();
    for (; iter != inputs.end(); ++iter) {
        if (bf.exists(*iter)) {
            std::cout << *iter << " exists.";
        } else {
            bf.add_ref(*iter);
        }
    }

    return 0;
}


