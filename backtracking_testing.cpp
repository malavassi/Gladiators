#include <googletest/googletest-master/googletest/include/gtest/gtest.h>
#include "Backtracking.h"
#include <gmock/gmock.h>

//
// Created by malavassi on 29/05/19.
//
struct Backtracking_TEST : public testing::Test{
    Backtracking *test;
    Matriz *matriz;
    void SetUp(){test = new Backtracking();
    matriz = new Matriz();}
    void TearDown(){delete test;
    delete matriz;}
};

TEST_F(Backtracking_TEST, isVisited){
    ASSERT_EQ(test->isVisited(0,0),false);
}

TEST_F(Backtracking_TEST, fila){
    EXPECT_EQ(matriz->columna1.getHead()->getData(),test->fila(matriz->matriz,0).getHead()->getData());
}