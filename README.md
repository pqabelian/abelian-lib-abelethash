# Abelethash

[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![readme style standard](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

C/C++ implementation of AbelEthash, the Abelian Proof of Work algorithm.

Abelethash is a fork of the C/C++ implementation of Ethash – the Ethereum Proof of Work algorithm (Ethash Copyright 2018 Pawel Bylica. Ethash is licensed under the Apache License, Version 2.0.). Ethash Github Source Code : https://github.com/ethereum/ethash

For more details about Abelian Blockchain, please checkout the Abelian Foundation official website: https://www.abelian.info


## Table of Contents

- [Abelethash](#abelethash)
  - [Table of Contents](#table-of-contents)
  - [Install](#install)
  - [Usage](#usage)
  - [Optimizations](#optimizations)
    - [Seed hash is computed on the fly.](#seed-hash-is-computed-on-the-fly)
    - [Dataset size is computed on the fly](#dataset-size-is-computed-on-the-fly)
  - [License](#license)


## Install

Build from source using CMake.

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

See [ethash.hpp] for list of exported function and documentation.


## Optimizations

This section describes the optimizations, modification and tweaks applied
in this library in relation to [Ethash reference implementation].

The library contains a set of micro-benchmarks.Build and run the `ethash-bench`
tool.

### Seed hash is computed on the fly.

Seed hash is sequence of keccak256 hashes applied the epoch number of times.
Time needed to compute seed hash is negligible comparing to time needed to build
light cache. Computing seed hash for epoch 10000 takes ~ 5 ms, building light
cache for epoch 1 takes ~ 500 ms.

### Dataset size is computed on the fly

Computing the size of full dataset and light cache requires finding the largest
prime number given an upper bound. For similar reasons as with seed hash, this
is computed on the fly. The procedure used is quite naive and forks well only
up to 40-bit number, so some additional improvement can be done in the future.

## License

Licensed under the [Apache License, Version 2.0].
