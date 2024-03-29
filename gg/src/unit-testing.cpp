#include <gtest/gtest.h>
#include "MyListSolution.h"
#include "StlListSolution.hpp"
#define List MyListSolution

TEST(implemented, none){
    List<int> list;
    EXPECT_EQ(list.toString(), "");
}

TEST(implemented, one) {
    List<int> list;
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "1");
    const char* error = nullptr;
    try {
        list.moveSecondLargestToEnd();
    } catch(const std::runtime_error &e) {
        error = e.what();
    }
    EXPECT_STREQ(error, "List must have at least 2 elements");
    EXPECT_EQ(list.toString(), "1");
}

TEST(implemented,twoAscending){
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    EXPECT_EQ(list.toString(),"1 2");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(),"2 1");
}

TEST(implemented,twoDescending){
    List<int> list;
    list.pushBack(2);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "2 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "2 1");
}

TEST(implemented,twoEqual) {
    List<int> list;
    list.pushBack(1);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "1 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "1 1");
}

TEST(implemented,threeAscending){
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.toString(),"1 2 3");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(),"1 3 2");
}

TEST(implemented,threeDescending){
    List<int> list;
    list.pushBack(3);
    list.pushBack(2);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "3 2 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "3 1 2");
}

TEST(implemented,threeEqual) {
    List<int> list;
    list.pushBack(1);
    list.pushBack(1);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "1 1 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "1 1 1");
}

TEST(implemented,threeTwoEqualBeginning){
    List<int> list;
    list.pushBack(2);
    list.pushBack(2);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "2 2 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "2 1 2");
}


TEST(implemented,threeTwoEqualEnd){
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(2);
    EXPECT_EQ(list.toString(), "1 2 2");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "1 2 2");
}