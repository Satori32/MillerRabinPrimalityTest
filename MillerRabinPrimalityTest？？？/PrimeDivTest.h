#pragma once
#include <vector>
#include <algorithm>


template<class T>
class PrimeDivTest {
public:
	PrimeDivTest() {
		Clear();
	}

	bool Clear() {
		Primes.clear();
		Count = 2;
		//Primes.push_back(2);
		return true;
	}

	std::size_t Size() const{
		return Primes.size();
	}

	bool IsPrime(const T& In) {
		Search(In);
		//std::sort(Primes.begin(), Primes.end());
		return std::binary_search(Primes.begin(), Primes.end(), In);
	}

	bool Search(const T& In) {
		for (Count; Count <= In; Count++) {
			bool F = true;
			for (auto& o : Primes) {
				if (Count % o==0) {
					F = false;
					break;
				}
				if (o * o >= Count) { break; }
			}
			if (F) {
				Primes.push_back(Count);
			}
		}

		std::sort(Primes.begin(), Primes.end());
		
		return true;
	}

	const T& operator[](std::size_t Idx) const{
		return Primes[Idx];
	}

	typename std::vector<T>::const_iterator begin() {
		return Primes.cbegin();
	}
	typename std::vector<T>::const_iterator end() {
		return Primes.cend();
	}
protected:
	std::vector<T> Primes;
	T Count=2;
};