#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include "PmergeMe.hpp"

bool isValidInput(char* str) {
    std::string s(str);
    if (s.empty())
		return (false);
    for (size_t i = 0; i < s.length(); ++i)
        if (!isdigit(s[i]))
			return (false);
    return (true);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./" << std::endl;
        return (1);
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        if (!isValidInput(argv[i])) {
            std::cerr << "Error" << std::endl;
            return (1);
        }
        int val = std::atoi(argv[i]);
        if (val < 0) {
            std::cerr << "Error" << std::endl;
            return (1);
        }
        if (std::find(vec.begin(), vec.end(), val) != vec.end()) {
            std::cerr << "Error" << std::endl;
            return (1);
        }
        vec.push_back(val);
        deq.push_back(val);
    }

	std::cout << "Before: ";
    printContainer(vec);
	
    PmergeMe		sorter;
    struct timeval	start;
	struct timeval	end;

    gettimeofday(&start, NULL);
    sorter.sortVector(vec);
    gettimeofday(&end, NULL);
    long long vecTime = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    sorter.sortDeque(deq);
    gettimeofday(&end, NULL);
    long long deqTime = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);

	std::cout << "After:  ";
    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
    return (0);
}