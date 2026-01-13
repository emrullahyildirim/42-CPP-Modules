#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sys/time.h>

typedef std::pair<int, int>	Pair;

class PmergeMe {
	private:
		std::vector<size_t> generateJacobsthalVec(size_t n);
		std::deque<size_t> generateJacobsthalDeq(size_t n);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
	
		void sortVector(std::vector<int>& vect);
		void sortDeque(std::deque<int>& deq);
};

template <typename T>
void printContainer(const T& container) {
    typename T::const_iterator it = container.begin();
	size_t count = 0;
    for (; it != container.end(); it++) {
		if (count < 5 || container.size() <= 5) {
			std::cout << *it << " ";
		}
		else if (count == 5) {
			std::cout << "[...]";
			break ;
		}
		count++;
    }
    std::cout << std::endl;
}

#endif