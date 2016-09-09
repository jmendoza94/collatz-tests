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
    const int v = collatz_eval(4383, 67670);
    ASSERT_EQ(340, v);}
   
TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(42, 31270);
    ASSERT_EQ(308, v);}
   
TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(437308, 453531);
    ASSERT_EQ(400, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(49464, 67329);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(29540, 34522);
    ASSERT_EQ(311, v);}
   
TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(42, 31270);
    ASSERT_EQ(308, v);}

TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(78954, 63625);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_14) {
    const int v = collatz_eval(876, 2764);
    ASSERT_EQ(209, v);}

TEST(CollatzFixture, eval_15) {
    const int v = collatz_eval(64813, 78102);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_16) {
    const int v = collatz_eval(378256, 378256);
    ASSERT_EQ(180, v);}

TEST(CollatzFixture, eval_17) {
    const int v = collatz_eval(62895, 83476);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_18) {
    const int v = collatz_eval(32413, 45341);
    ASSERT_EQ(324, v);}

TEST(CollatzFixture, eval_19) {
    const int v = collatz_eval(385, 125);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_20) {
    const int v = collatz_eval(10485, 8912);
    ASSERT_EQ(260, v);}

TEST(CollatzFixture, eval_21) {
    const int v = collatz_eval(94174, 47116);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_22) {
    const int v = collatz_eval(4109, 5013);
    ASSERT_EQ(215, v);}

TEST(CollatzFixture, eval_23) {
    const int v = collatz_eval(94145, 84124);
    ASSERT_EQ(333, v);}

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
    const int v = collatz_eval(3123, 7456);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_30) {
    const int v = collatz_eval(12313, 23890);
    ASSERT_EQ(282, v);}

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
    istringstream r("1 10\n100 200\n201 210\n900 1000\n1000 900\n10 10\n4383 67670\n42 31270\n437308 453531\n49464 67329\n29540 34522\n42 31270\n78954 63625\n876 2764\n64813 78102\n378256 378256\n62895 83476\n32413 45341\n385 125\n10485 8912\n94174 47116\n4109 5013\n94145 84124\n5719 1234\n300 255\n255 300\n25 100\n1324 960\n3123 7456\n12313 23890\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n1000 900 174\n10 10 7\n4383 67670 340\n42 31270 308\n437308 453531 400\n49464 67329 340\n29540 34522 311\n42 31270 308\n78954 63625 351\n876 2764 209\n64813 78102 351\n378256 378256 180\n62895 83476 351\n32413 45341 324\n385 125 144\n10485 8912 260\n94174 47116 351\n4109 5013 215\n94145 84124 333\n5719 1234 238\n300 255 123\n255 300 123\n25 100 119\n1324 960 182\n3123 7456 262\n12313 23890 282\n", w.str());}
