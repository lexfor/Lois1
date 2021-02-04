//
// Created by nicola on 04/02/2021.
//
#include "gtest/gtest.h"
#include "../source/KNF.h"

TEST(TestKNF, first)
{
    EXPECT_TRUE(CheckKNF("-A&(B|C)"));
}

TEST(TestKNF, second)
{
    EXPECT_TRUE(CheckKNF("(A|B)&(-B|C|-D)&(D|-E)"));
}

TEST(TestKNF, third)
{
    EXPECT_TRUE(CheckKNF("A&B"));
}

TEST(TestKNF, four)
{
    EXPECT_FALSE(CheckKNF("-(B|C)"));
}

TEST(TestKNF, five)
{
    EXPECT_FALSE(CheckKNF("(A&B)|C"));
}

TEST(TestKNF, six)
{
    EXPECT_FALSE(CheckKNF("A&(B|(D&E))"));
}

TEST(TestKNF, seven)
{
    EXPECT_TRUE(CheckKNF("-B & -C"));
}

TEST(TestKNF, eight)
{
    EXPECT_TRUE(CheckKNF("(A|C) & (B|C)"));
}

TEST(TestKNF, nine)
{
    EXPECT_TRUE(CheckKNF("A & (B|D) & (B|E)"));
}