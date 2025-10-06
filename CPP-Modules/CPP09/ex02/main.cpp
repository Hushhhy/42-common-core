#include "PmergeMe.hpp"

static double getTime() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e6 + ts.tv_nsec / 1e3;
}

int main(int ac, char **av) {
    std::vector<int> vec;
    std::deque<int> deq;

    if (ac < 2 || !PmergeMe::parseInput(ac, av, vec, deq)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe::printSequence("Before: ", vec);

    double startVec = getTime();
    PmergeMe::mergeInsertSortVector(vec, 0, vec.size() - 1);
    double endVec = getTime();

    double startDeq = getTime();
    PmergeMe::mergeInsertSortDeque(deq, 0, deq.size() - 1);
    double endDeq = getTime();

    PmergeMe::printSequence("After: ", vec);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << endVec - startVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : "
              << endDeq - startDeq << " us" << std::endl;

    return 0;
}