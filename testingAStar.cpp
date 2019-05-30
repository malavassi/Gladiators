//
// Created by kevin on 29/05/19.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AStar.h"
#include "Quadrant.h"

struct A1: testing::Test{
    AStar* astar;
    A1(){
        LinkedList<LinkedList<int>>* matriz = new LinkedList<LinkedList<int>>();
        for(int i=0;i<10;i++){
            LinkedList<int> col = LinkedList<int>();
            for(int j=0;j<10;j++){
                col.push_back(0);
            }
            matriz->push_back(col);
        }
        astar = new AStar(10, 0, 0);
        astar->setMapMatrix(matriz);
    }
    ~A1(){
        delete astar;
    }
};

TEST_F(A1, PruebaValid){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            EXPECT_TRUE(astar->isValid(i,j));
            EXPECT_TRUE(astar->isUnblocked(i,j));
        }
    }
}

TEST_F(A1, PruebaCamino){
    EXPECT_TRUE(astar->aStarSearch(9,9));
    LinkedList<LinkedList<Quadrant*>> matrix = LinkedList<LinkedList<Quadrant*>>();
    for(int i =0;i<10;i++){
        LinkedList<Quadrant*> quads;
        for(int j=0;j<10;j++){
            quads.push_back(new Quadrant());
        }
        matrix.push_back(quads);
    }
}

TEST_F(A1, CalH){
    ASSERT_EQ((int)astar->calcH(2,3),3);
}



int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}