/* ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
 * Copyright 2019 Pawel Bylica.
 * Licensed under the Apache License, Version 2.0.
 */

#pragma once

/** The ethash library version. */
// #define ETHASH_VERSION "1.0.0"
#define ABEL_ETHASH_VERSION "2.0.0-alpha.0"

#ifdef __cplusplus
namespace ethash
{
/// The ethash library version.
// constexpr auto version = ETHASH_VERSION;
constexpr auto version = ABEL_ETHASH_VERSION;

}  // namespace ethash
#endif
