
#include <gtest/gtest.h>
#include "dataReader.h"

#define TRUCK_PATH "data/input/carrinhas.txt"
#define REQUEST_PATH "data/input/encomendas.txt"

int main(){
    dataReader data(TRUCK_PATH,REQUEST_PATH);
    data.readFixed(10);
    return 0;
}


TEST(main, doesThisWork) {
    unsigned int a = 3;
    unsigned int b = 3;
    EXPECT_EQ(a,b);
}