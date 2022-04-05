//
// Created by dudud on 05/04/2022.
//

#include <gtest/gtest.h>
#include "main.h"

int main(){
    std::cout << "Hello World" << std::endl;
    return 0;
}


TEST(main, doesThisWork) {
    unsigned int a = 3;
    unsigned int b = 3;
    EXPECT_EQ(a,b);
}