#ifndef STREAMING_MEDIAN_H
#define STREAMING_MEDIAN_H

#include <queue>
#include <vector>
#include <type_traits>

template<typename Number>
class streamingMedian {

// we require that Number is arithmetic - thus, we can add two of them and divide by 2 (to calculate median for even number of values)
static_assert(std::is_arithmetic<Number>::value, "Cannot create streamingMedian with non-numeric type!");
private:
    // first part of the sample - will contain values that are to the left of the median
    std::priority_queue<Number> left_queue;
    // second part of the sample -- will contain values that are to the right of the median
    std::priority_queue<Number, std::vector<Number>, std::greater<Number>> right_queue;

public:
    void add_number(Number a);
    double get_median();
};


template <typename Number>
void streamingMedian<Number>::add_number(Number a) {
    static_assert(std::is_arithmetic<Number>::value, "Require a number");

    // check to see in which part of the current sample the new number should go
    // if left is empty - just put it in the right part
    if ((!left_queue.empty()) && a < left_queue.top()){
        left_queue.push(a);
    } else {
        right_queue.push(a);
    }

    Number tmp;
    // rebalance the two containers so that they contain almost equal number of elements (almost meaning that the difference should be 0 or 1).
    // remove one number from the larger and put it in the smaller
    // this is checked on each number added, containers cannot grow to be too dissimmilar
    if (left_queue.size() > right_queue.size() + 1) {
        tmp = left_queue.top();
        left_queue.pop();
        right_queue.push(tmp);
    } else if (right_queue.size() > left_queue.size() + 1) {
        tmp = right_queue.top();
        right_queue.pop();
        left_queue.push(tmp);
    }   
}

template <typename Number>
double streamingMedian<Number>::get_median() {
    double result;
    if (left_queue.size() == right_queue.size()) {
        result = (static_cast<double>(left_queue.top()) + right_queue.top()) / 2;
    } else if (left_queue.size() > right_queue.size()){
        result = left_queue.top();
    } else {
        result = right_queue.top();
    }

    return result;
}

#endif // STREAMING_MEDIAN_H