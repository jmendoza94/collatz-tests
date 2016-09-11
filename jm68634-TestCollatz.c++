// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}      // was (1, v)

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(1000, 900);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(10, 10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(4383, 7672);
    ASSERT_EQ(262, v);}
   
TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(42, 270);
    ASSERT_EQ(128, v);}
   
TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(7308, 6531);
    ASSERT_EQ(257, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(9464, 7329);
    ASSERT_EQ(260, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(540, 522);
    ASSERT_EQ(124, v);}
   
TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(42, 70);
    ASSERT_EQ(113, v);}

TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(4954, 3625);
    ASSERT_EQ(238, v);}

TEST(CollatzFixture, eval_14) {
    const int v = collatz_eval(876, 1764);
    ASSERT_EQ(182, v);}

TEST(CollatzFixture, eval_15) {
    const int v = collatz_eval(4813, 6102);
    ASSERT_EQ(236, v);}

TEST(CollatzFixture, eval_16) {
    const int v = collatz_eval(8256, 9256);
    ASSERT_EQ(247, v);}

TEST(CollatzFixture, eval_17) {
    const int v = collatz_eval(895, 476);
    ASSERT_EQ(179, v);}

TEST(CollatzFixture, eval_18) {
    const int v = collatz_eval(413, 341);
    ASSERT_EQ(134, v);}

TEST(CollatzFixture, eval_19) {
    const int v = collatz_eval(385, 125);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_20) {
    const int v = collatz_eval(9485, 8912);
    ASSERT_EQ(260, v);}

TEST(CollatzFixture, eval_21) {
    const int v = collatz_eval(6174, 7116);
    ASSERT_EQ(257, v);}

TEST(CollatzFixture, eval_22) {
    const int v = collatz_eval(4109, 5013);
    ASSERT_EQ(215, v);}

TEST(CollatzFixture, eval_23) {
    const int v = collatz_eval(4145, 5124);
    ASSERT_EQ(215, v);}

TEST(CollatzFixture, eval_24) {
    const int v = collatz_eval(5719, 1234);
    ASSERT_EQ(238, v);}

TEST(CollatzFixture, eval_25) {
    const int v = collatz_eval(300, 255);
    ASSERT_EQ(123, v);}

TEST(CollatzFixture, eval_26) {
    const int v = collatz_eval(255, 300);
    ASSERT_EQ(123, v);}

TEST(CollatzFixture, eval_27) {
    const int v = collatz_eval(25, 100);
    ASSERT_EQ(119, v);}

TEST(CollatzFixture, eval_28) {
    const int v = collatz_eval(1324, 960);
    ASSERT_EQ(182, v);}

TEST(CollatzFixture, eval_29) {
    const int v = collatz_eval(3123, 4456);
    ASSERT_EQ(238, v);}

TEST(CollatzFixture, eval_30) {
    const int v = collatz_eval(2313, 2890);
    ASSERT_EQ(209, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n1000 900\n10 10\n4383 7672\n42 270\n7308 6531\n9464 7329\n540 522\n42 70\n4954 3625\n876 1764\n4813 6102\n8256 9256\n895 476\n413 341\n385 125\n9485 8912\n6174 7116\n4109 5013\n4145 5124\n5719 1234\n300 255\n255 300\n25 100\n1324 960\n3123 4456\n2313 2890\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n1000 900 174\n10 10 7\n4383 7672 262\n42 270 128\n7308 6531 257\n9464 7329 260\n540 522 124\n42 70 113\n4954 3625 238\n876 1764 182\n4813 6102 236\n8256 9256 247\n895 476 179\n413 341 134\n385 125 144\n9485 8912 260\n6174 7116 257\n4109 5013 215\n4145 5124 215\n5719 1234 238\n300 255 123\n255 300 123\n25 100 119\n1324 960 182\n3123 4456 238\n2313 2890 209\n", w.str());}
