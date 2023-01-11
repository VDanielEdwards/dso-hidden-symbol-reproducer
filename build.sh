#!/usr/bin/env bash

compile()
{
    local CXX="$1"
    local N="$2"
    local G="0" #"$3"
    local O="$4"

    local OUTPUT="dso.$N.so"

        #-shared \

    "$CXX" \
        -c \
        -o "$OUTPUT" \
        \
        "-g$G" \
        "-O$O" \
        \
        -std=c++14 \
        \
        -fPIC \
        \
        -fvisibility=hidden \
        -fvisibility-inlines-hidden \
        \
        dso.cpp

    printf "\nFILE: %s\n\n" "$OUTPUT"
    nm -C "$OUTPUT"
}

compile g++-9  gcc-9-g3-O0  3 0 
compile g++-9  gcc-9-g3-O2  3 2 

compile g++-10 gcc-10-g3-O0 3 0
compile g++-10 gcc-10-g3-O2 3 2

compile clang++-11  clang-11-g3-O0 3 0
compile clang++-11  clang-11-g3-O2 3 2

compile clang++-14  clang-14-g3-O0 3 0
compile clang++-14  clang-14-g3-O2 3 2

# vim: set et sw=4 sts=4:
