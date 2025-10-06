#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>

class PmergeMe {
    public:
        static bool parseInput(int ac, char **av, std::vector<int> &vec, std::deque<int> &deq);
        static void printSequence(const std::string &prefix, const std::vector<int> &seq);
        static void printSequence(const std::string &prefix, const std::deque<int> &seq);
        static void mergeInsertSortVector(std::vector<int> &seq, int left, int right);
        static void mergeInsertSortDeque(std::deque<int> &seq, int left, int right);
};

#endif