# abelethash: C/C++ implementation of AbelEthash, the Abelian Proof of Work algorithm.
# Copyright 2022-2023 Abelian Foundation.
# Licensed under the Apache License, Version 2.0.


cmake_minimum_required(VERSION 3.16.2)

include(cmake/cable/bootstrap.cmake)

include(CableBuildType)
include(CableCompilerSettings)
include(CableToolchains)
include(CMakeDependentOption)
include(CMakePackageConfigHelpers)
include(HunterGate)

cable_configure_toolchain(DEFAULT cxx14)
cable_set_build_type(DEFAULT Release CONFIGURATION_TYPES Release RelWithDebInfo Debug)

include(cmake/Hunter/init.cmake)

project(abelethash)
set(PROJECT_VERSION 2.0.0-alpha.0)

cable_configure_compiler(NO_STACK_PROTECTION)
if(CABLE_COMPILER_GNULIKE)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Og")

    add_compile_options(
        # -Wcast-align  #TODO: Build fails on mips64
        -Wcast-qual
        -Wmissing-declarations
        -Wsign-conversion
        -Wundef
        -Wunreachable-code
        $<$<COMPILE_LANGUAGE:C>:-Wmissing-prototypes>
        $<$<CXX_COMPILER_ID:Clang>:-Wduplicate-enum>
        $<$<CXX_COMPILER_ID:Clang>:-Wnewline-eof>
        $<$<CXX_COMPILER_ID:Clang>:-Wunreachable-code-aggressive>
    )

    if(MSVC) # clang-cl
        add_compile_options(
            -Wno-exit-time-destructors
            -Wno-global-constructors
            $<$<COMPILE_LANGUAGE:CXX>:-Wno-c++98-compat-pedantic>
            $<$<COMPILE_LANGUAGE:CXX>:-Wno-old-style-cast>
        )
    endif()
elseif(MSVC AND CMAKE_SIZEOF_VOID_P EQUAL 4)
    # For Win32 builds allow allocating more than 2 GB of memory.
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
endif()

option(ETHASH_INSTALL_CMAKE_CONFIG "Install CMake configuration scripts for find_package(CONFIG)" ON)

set(include_dir ${PROJECT_SOURCE_DIR}/include)

option(ETHASH_BUILD_ETHASH "Build abelethash::ethash library (if NO only abelethash::keccak is built)" YES)

cmake_dependent_option(ETHASH_BUILD_GLOBAL_CONTEXT "Build abelethash::global-context library" YES "ETHASH_BUILD_ETHASH" NO)

# enable test, if necessary, turn off it
option(ETHASH_TESTING "Build unit tests" NO)
#option(ETHASH_TESTING "Build unit tests" YES)

add_subdirectory(lib)

if(ETHASH_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()


install(
    DIRECTORY
    ${include_dir}/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(ETHASH_INSTALL_CMAKE_CONFIG)
    write_basic_package_version_file(abelethashConfigVersion.cmake COMPATIBILITY SameMajorVersion)
    configure_package_config_file(cmake/Config.cmake.in abelethashConfig.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/abelethash)

    install(
        EXPORT abelethashTargets
        NAMESPACE abelethash::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/abelethash
    )
    install(
        FILES
        ${CMAKE_CURRENT_BINARY_DIR}/abelethashConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/abelethashConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/abelethash
    )
endif()
