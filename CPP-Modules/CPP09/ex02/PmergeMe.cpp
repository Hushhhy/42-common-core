#include "PmergeMe.hpp"

bool isPositiveInteger(const std::string &s) {
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i]))
            return false;
    }
    if (s.size() > 10)
        return false;
    long long val = std::atoll(s.c_str());
    if (val <= 0 || val > 2147483647)
        return false;
    return true;
}

bool hasDuplicate(const std::vector<int> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] == vec[j])
                return true;
        }
    }
    return false;
}

bool PmergeMe::parseInput(int ac, char **av, std::vector<int> &vec, std::deque<int> &deq) {
    for (int i = 1; i < ac; ++i) {
        std::string arg(av[i]);
        if (!isPositiveInteger(arg))
            return false;
        int val = std::atoi(arg.c_str());
        vec.push_back(val);
        deq.push_back(val);
    }
    if (hasDuplicate(vec))
        return false;
    return true;
}

void PmergeMe::printSequence(const std::string &prefix, const std::vector<int> &seq) {
    std::cout << prefix;
    for (size_t i = 0; i < seq.size(); ++i) {
        std::cout << seq[i];
        if (i + 1 < seq.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printSequence(const std::string &prefix, const std::deque<int> &seq) {
    std::cout << prefix;
    for (size_t i = 0; i < seq.size(); ++i) {
        std::cout << seq[i];
        if (i + 1 < seq.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void mergeVector(std::vector<int> &seq, int left, int mid, int right) {
    std::vector<int> leftVec(seq.begin() + left, seq.begin() + mid + 1);
    std::vector<int> rightVec(seq.begin() + mid + 1, seq.begin() + right + 1);
    size_t i = 0, j = 0;
    int k = left;
    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] <= rightVec[j]) {
            seq[k++] = leftVec[i++];
        } else {
            seq[k++] = rightVec[j++];
        }
    }
    while (i < leftVec.size())
        seq[k++] = leftVec[i++];
    while (j < rightVec.size())
        seq[k++] = rightVec[j++];
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &seq, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeInsertSortVector(seq, left, mid);
    mergeInsertSortVector(seq, mid + 1, right);
    mergeVector(seq, left, mid, right);
}

void mergeDeque(std::deque<int> &seq, int left, int mid, int right) {
    std::deque<int> leftDeq;
    std::deque<int> rightDeq;
    for (int i = left; i <= mid; ++i)
        leftDeq.push_back(seq[i]);
    for (int i = mid + 1; i <= right; ++i)
        rightDeq.push_back(seq[i]);
    size_t i = 0, j = 0;
    int k = left;
    while (i < leftDeq.size() && j < rightDeq.size()) {
        if (leftDeq[i] <= rightDeq[j]) {
            seq[k++] = leftDeq[i++];
        } else {
            seq[k++] = rightDeq[j++];
        }
    }
    while (i < leftDeq.size())
        seq[k++] = leftDeq[i++];
    while (j < rightDeq.size())
        seq[k++] = rightDeq[j++];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &seq, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeInsertSortDeque(seq, left, mid);
    mergeInsertSortDeque(seq, mid + 1, right);
    mergeDeque(seq, left, mid, right);
}