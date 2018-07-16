#include <iostream>
#include <algorithm>

// for_each combinator
template <typename Collection, typename unop>
void for_each(Collection col, unop op) {
    std::for_each(col.begin(), col.end(), op);
};

// map combinator
template <typename Collection, typename unop>
Collection map(Collection col, unop op) {
    std::transform(col.begin(), col.end(), col.begin(), op);
    return col;
}

// filter combinator
template <typename Collection, typename Predicate>
Collection filterNot(Collection col, Predicate predicate) {
    auto returnIterator = std::remove_if(col.begin(), col.end(), predicate);
    col.erase(returnIterator, std::end(col));
    return col;
}

template <typename Collection, typename Predicate>
Collection filter(Collection col, Predicate predicate) {
    // capture the predicate in order to be used inside function
    auto fnCol = filterNot(col, [predicate](typename Collection::value_type i) {
        return !predicate(i);
    });
    return fnCol;
}

int main() {
    // Auto Keywords
    std::cout << "Auto Keywords" << std::endl;
    auto i = 1;
    std::cout << i << std::endl;
    std::cout << std::endl;

    // Functional data types AKA lambdas
    std::cout << "lambdas" << std::endl;
    auto println = [](const char *message) {
        std::cout << message << std::endl;
    };
    println("Hai");
    std::cout << std::endl;

    // for_each combinator
    std::cout << "for_each combinator" << std::endl;
    auto lambda_echo = [](int i) {
        std::cout << i << std::endl;
    };
    std::vector<int> col {20, 24, 37, 42, 23, 45, 37};
    for_each(col, lambda_echo);
    std::cout << std::endl;

    // map combinator
    std::cout << "map combinator" << std::endl;
    auto addOne = [](int i) {
        return i+1;
    };
    auto returnCol = map(col, addOne);
    for_each(returnCol, lambda_echo);
    std::cout << std::endl;

    // filter combinator
    std::cout << "filter combinator" << std::endl;
    auto filteredCol = filter(col, [](int value) {
        return value > 30;
    });
    for_each(filteredCol, lambda_echo);
    std::cout << std::endl;

    return 0;
}