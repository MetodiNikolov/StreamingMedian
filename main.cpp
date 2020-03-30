#include "streamingMedian.h"
#include <iostream>

int main() {

    streamingMedian<int> sh;

    sh.add_number(5);
    sh.add_number(15);
    sh.add_number(25);

    // print 15
    std::cout << sh.get_median();
}