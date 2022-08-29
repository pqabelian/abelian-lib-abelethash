# ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
# Copyright 2021 Pawel Bylica.
# Licensed under the Apache License, Version 2.0.

# abelethash: C/C++ implementation of AbelEthash, the Abelian Proof of Work algorithm.
# Copyright 2022-2023 Abelian Foundation.
# Licensed under the Apache License, Version 2.0.


add_library(experimental STATIC)
add_library(abelethash::experimental ALIAS experimental)
target_link_libraries(experimental PUBLIC abelethash::ethash)
target_sources(
    experimental PRIVATE
    difficulty.cpp
    difficulty.h
)
