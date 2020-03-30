#include <queue>
#include <vector>
#include <type_traits>

template<typename Number>
class streamingMedian {

static_assert(std::is_arithmetic<Number>::value, "Cannot create streamingMedian with non-numeric type!");
private:
    std::priority_queue<Number> left_queue;
    std::priority_queue<Number, std::vector<Number>, std::greater<Number>> right_queue;

public:
    void add_number(Number a);
    double get_median();
};


template <typename Number>
void streamingMedian<Number>::add_number(Number a) {
    static_assert(std::is_arithmetic<Number>::value, "Require a number");

    if ((!left_queue.empty()) && a < left_queue.top()){
        left_queue.push(a);
    } else {
        right_queue.push(a);
    }

    Number tmp;
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
