#include <gtest/gtest.h>
#include "implement-list.hpp"

TEST(implemented, one) {
    List list;
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "1");
}

TEST(implemented,twoAscending){
    List list;
    list.pushBack(1);
    list.pushBack(2);
    EXPECT_EQ(list.toString(),"1 2");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(),"2 1");
}

TEST(implemented,twoDescending){
    List list;
    list.pushBack(2);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "2 1");
    cout<<"hello"<<endl;
    list.moveSecondLargestToEnd();
    cout<<"hello 2"<<endl;
    list.print();
    EXPECT_EQ(list.toString(), "2 1");
    cout<<"hello 3"<<endl;
}

TEST(implemented,twoEqual) {
    List list;
    list.pushBack(1);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "1 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "1 1");
}

TEST(implemented,threeAscending){
    List list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.toString(),"1 2 3");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(),"1 3 2");
}

TEST(implemented,threeDescending){
    List list;
    list.pushBack(3);
    list.pushBack(2);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "3 2 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "3 1 2");
}

TEST(implemented,threeEqual) {
    List list;
    list.pushBack(1);
    list.pushBack(1);
    list.pushBack(1);
    EXPECT_EQ(list.toString(), "1 1 1");
    list.moveSecondLargestToEnd();
    EXPECT_EQ(list.toString(), "1 1 1");
}