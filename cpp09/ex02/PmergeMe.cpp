#include <algorithm>
#include <iostream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::generateJacobsthalVec(size_t n) {
    std::vector<size_t> jacob;
    if (n == 0) 
		return (jacob);

    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < n) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return (jacob);
}

std::deque<size_t> PmergeMe::generateJacobsthalDeq(size_t n) {
    std::deque<size_t> jacob;
    if (n == 0) 
		return (jacob);

    jacob.push_back(1);
    jacob.push_back(3);
    while (jacob.back() < n) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return (jacob);
}

void PmergeMe::sortVector(std::vector<int>& vect) {
    if (vect.size() <= 1)
		return ;

    std::vector<Pair> pairs;
    int loneElement = -1;
    bool hasLone = (vect.size() % 2 != 0);

    if (hasLone) {
        loneElement = vect.back();
        vect.pop_back();
    }

    for (size_t i = 0; i < vect.size(); i += 2) {
        if (vect[i] > vect[i + 1])
            pairs.push_back(std::make_pair(vect[i + 1], vect[i]));
        else
            pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
    }

    std::vector<int>	bigger;
    for (size_t i = 0; i < pairs.size(); i++)
        bigger.push_back(pairs[i].second);
    sortVector(bigger);

    std::vector<Pair>	orderedPairs;
    for (size_t i = 0; i < bigger.size(); i++)
        for (size_t j = 0; j < pairs.size(); j++) 
            if (pairs[j].second == bigger[i]) {
                orderedPairs.push_back(pairs[j]);
                break;
            }

    std::vector<int> mainChain;
    for (size_t i = 0; i < orderedPairs.size(); i++)
        mainChain.push_back(orderedPairs[i].second);
    
    mainChain.insert(mainChain.begin(), orderedPairs[0].first);

    std::vector<size_t> jacobSeq = generateJacobsthalVec(orderedPairs.size());
    std::vector<bool> inserted(orderedPairs.size(), false);
    inserted[0] = true;

    size_t lastPos = 0;
    for (size_t j = 0; j < jacobSeq.size(); j++) {
        size_t currentPos = jacobSeq[j];
        if (currentPos >= orderedPairs.size()) 
            currentPos = orderedPairs.size() - 1;

        for (size_t k = currentPos; k > lastPos; k--) {
            if (inserted[k]) continue;

            std::vector<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), orderedPairs[k].second);
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), limit, orderedPairs[k].first);

            mainChain.insert(it, orderedPairs[k].first);
            inserted[k] = true; 
        }
        lastPos = currentPos;
    }

    if (hasLone)
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), loneElement), loneElement);

    vect = mainChain;
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    int loneElement = -1;
    bool hasLone = (deq.size() % 2 != 0);

    if (hasLone) {
        loneElement = deq.back();
        deq.pop_back();
    }

    for (size_t i = 0; i < deq.size(); i += 2) {
        if (deq[i] > deq[i + 1])
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
        else
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }

    std::deque<int> bigger;
    for (size_t i = 0; i < pairs.size(); i++)
        bigger.push_back(pairs[i].second);
    sortDeque(bigger);

    std::deque<std::pair<int, int> > orderedPairs;
    for (size_t i = 0; i < bigger.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == bigger[i]) {
                orderedPairs.push_back(pairs[j]);
                break;
            }
        }
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < orderedPairs.size(); i++)
        mainChain.push_back(orderedPairs[i].second);
    
    mainChain.push_front(orderedPairs[0].first);

    std::deque<size_t> jacobSeq = generateJacobsthalDeq(orderedPairs.size());
    std::deque<bool> inserted(orderedPairs.size(), false);
    inserted[0] = true;

    size_t lastPos = 0;
    for (size_t j = 0; j < jacobSeq.size(); j++) {
        size_t currentPos = jacobSeq[j];
        if (currentPos >= orderedPairs.size()) 
            currentPos = orderedPairs.size() - 1;

        for (size_t k = currentPos; k > lastPos; k--) {
            if (inserted[k]) continue;

            std::deque<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), orderedPairs[k].second);
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), limit, orderedPairs[k].first);

            mainChain.insert(it, orderedPairs[k].first);
            inserted[k] = true; 
        }
        lastPos = currentPos;
    }

    if (hasLone)
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), loneElement), loneElement);

    deq = mainChain;
}