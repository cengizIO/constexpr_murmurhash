// The MIT License (MIT)
//
// Copyright (c) 2015, Tamás Szelei
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define CATCH_CONFIG_MAIN

#include "catch/src/catch/include/catch.hpp"

#include "constexpr_murmur3.h"

using ce_mm3::mm3_x86_32;

TEST_CASE("Empty string without seed should produce zero", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("", 0)==0);
}

TEST_CASE("Empty string should ignore most math", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("", 1)==0x514E28B7);
}

TEST_CASE("Empty string with seed should use unsigned math", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("", 0xffffffff)==0x81F16F39);
}

TEST_CASE("One character should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("a", 0x9747b28c)==0x7FA09EA6);
}

TEST_CASE("Two characters should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("aa", 0x9747b28c)==0x5D211726);
}

TEST_CASE("Three characters should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("aaa", 0x9747b28c)==0x283E0130);
}

TEST_CASE("Four characters should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("aaaa", 0x9747b28c)==0x5A97808A);
}

TEST_CASE("Four characters in Endian order should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("abcd", 0x9747b28c)==0xF0478627);
}

TEST_CASE("Three characters in Endian order should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("abc", 0x9747b28c)==0xC84A62DD);
}

TEST_CASE("Three characters in Endian order without seed should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("abc", 0)==0xB3DD93FA);
}

TEST_CASE("Two characters in Endian order should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("ab", 0x9747b28c)==0x74875592);
}

TEST_CASE("'Hello, world!' should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("Hello, world!", 0x9747b28c)==0x24884CBA);
}

TEST_CASE("Long string should produce valid hash", "[mm_x86_32_test]")
{
    REQUIRE(mm3_x86_32("The quick brown fox jumps over the lazy dog", 0x9747b28c)==0x2FA826CD);
}
