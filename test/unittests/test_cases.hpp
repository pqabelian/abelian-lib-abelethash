// Ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
// Copyright 2018 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

/// @file
/// Shared test cases.

#pragma once

// Put in anonymous namespace to allow be include in multiple files
// but also make iteration over test cases easy with range-based for loop.
namespace
{
struct hash_test_case
{
    int block_number;
    const char* header_hash_hex;
    const char* nonce_hex;
    const char* mix_hash_hex;
    const char* final_hash_hex;
};

// NOLINTNEXTLINE(misc-definitions-in-headers)
hash_test_case hash_test_cases[] = {
    {
        56000,
        "2a8de2adf89af77358250bf908bf04ba94a6e8c3ba87775564a41d269a05e4ce",
        "5656565656565656",
        "afb35f1fdc8de02bb9374229e2ad58e6091814c12e9fc22123c9f313af1e5dd3",
        "c7bfebd9032fb399e59f17ec591cfbca658b63a1904d658e183313564be901e4",
    },
    {
        56002,
        "100cbec5e5ef82991290d0d93d758f19082e71f234cf479192a8b94df6da6bfe",
        "307692cf71b12f6d",
        "a64d4be66f254f12acd606cf06a5e2fbaa3f342cc5cf310d18268280da5b9ac4",
        "c4c929ee26d7ac84b421bfcc3c0de334f39bbacc448841f84173f78f7949b8c1",
    },
    {
        76009,
        "0313d03c5ed78694c90ecb3d04190b82d5b222c75ba4cab83383dde4d11ed512",
        "8c5eaec000788d41",
        "1cd608dc4cee9f582b4e15ebd7f3d63cb640fda8c28a27047d143078de3c57f4",
        "cb67bcb1e82bba14e416f947b05456c51e64b699db1ace8d58412e83b2e8cd6b",
    },
    {
        96017,
        "bc544c2baba832600013bd5d1983f592e9557d04b0fb5ef7a100434a5fc8d52a",
        "4617a20003ba3f25",
        "a8a766a64b8eda9fcaecc95a74edf20a6f69bebe5291d394bac679566053219a",
        "86de6f1c61bce6d5f409c3659e676317ab836147c7711a766d5c0114878cde73",
    },
    {
        404016,
        "2cd14041cfc3bd13064cfd58e26c0bddf1e97a4202c4b8076444a7cd4515f8c3",
        "1af47f2007922384",
        "b44b171c8292af960d8ac1e39ab6f4b7bd2b6abf82476cbe189924d88dbd6339",
        "b72faa5096a4698984be68ba9bad9972a670563f401276a57f0bd7e7e9562729",
    },
    {
        589005,
        "9e79bced19062baf7c47e516ad3a1bd779222404d05b4205def30a13c7d87b5b",
        "c9a044201dd998f2",
        "0bd4cc5b85000894ceedc03751d8621af6b6f5e6704d18d179afaa44cd7c4af4",
        "3572b538d3cae6f5a854aba234fc06812ca2f883c02d7bdf52c1cab47d20d6c0",
    },
    {
        589006,
        "53a005f209a4dc013f022a5078c6b38ced76e767a30367ff64725f23ec652a9f",
        "d337f82001e992c5",
        "19a82e59e236a861664a2b39d0b91813c40575f3bdb6c6920e32bdce1f642b38",
        "a5457c2a829688e4d3a5480666b4a6499c434283d6bbfe40ac409419e83b04f8",
    },
};
}  // namespace
