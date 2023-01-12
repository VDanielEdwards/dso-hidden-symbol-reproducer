#!/usr/bin/env python3

import subprocess as sp


def run_compiler(compiler, inputs, output, args):
    cmd = [
        compiler,

        *args,

        "-std=c++14",

        "-fPIC",

        "-fvisibility=hidden",
        "-fvisibility-inlines-hidden",

        "-o",
        output,

        *inputs,
    ]

    print("compiler:", ' '.join(cmd))
    sp.run(cmd)


def run_nm(args):
    cmd = [
        "nm",
        "-C",
        *args,
    ]

    print("symbols:", ' '.join(cmd))
    sp.run(cmd)


if __name__ == "__main__":
    parameters = [
        ("g++-9",      "gcc-9",    ["-g0", "-O0"]),
        ("g++-9",      "gcc-9",    ["-g0", "-O1"]),

        ("g++-10",     "gcc-10",   ["-g0", "-O0"]),
        ("g++-10",     "gcc-10",   ["-g0", "-O1"]),

        ("clang++-11", "clang-11", ["-g0", "-O0"]),
        ("clang++-11", "clang-11", ["-g0", "-O1"]),

        ("clang++-14", "clang-14", ["-g0", "-O0"]),
        ("clang++-14", "clang-14", ["-g0", "-O1"]),
    ]

    for compiler, name, args in parameters:
        print()
        output = "dso.{}.so".format(name)
        run_compiler(compiler, inputs=["dso.cpp", "detail.cpp"], output=output, args=["-shared", *args])
        run_nm(args=["-D", output])


# vim: set et sw=4 sts=4:
