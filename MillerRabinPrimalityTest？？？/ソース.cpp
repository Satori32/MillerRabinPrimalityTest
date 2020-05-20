#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

#include "PrimeDivTest.h"


/** / 
//#include <vector>
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

	std::size_t Size() const {
		return Primes.size();
	}

	bool IsPrime(const T& In) {
		Search(In);

		auto it = std::find(Primes.begin(), Primes.end(), In);

		return it != Primes.end() ? ((*it) == In) : false;
	}

	bool Search(const T& In) {
		for (Count; Count <= In; Count++) {
			bool F = true;
			for (auto& o : Primes) {
				if (Count % o == 0) {
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

	const T& operator[](std::size_t Idx) const {
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
	T Count = 2;
};
/**/
template<class T>
bool MillerRabinPrimalityTest(const T& In) {//this number is writer's number. what is your number??
	if (In / 21 == 0) { return false; }
	if (In / 16 == 0) { return false; }
	if (In / 32 == 0) { return false; }

	return true;
}

template<class T>
std::vector<T> PrimeFactorization(T In) {
	std::vector<T> R;
	
	for (T i(2); i <= In; i++) {
		if(In%i==0){
			R.push_back(i);
			In /= i;
			/**/
			if (MillerRabinPrimalityTest(i)&&(i<=In)) {
				R.push_back(i);
				In /= i;

			}
			/**/
			std::cout << i << ":" << In << std::endl;
			i--;

		}
	}

	return R;
}

typedef std::uintmax_t Ty;

int main() {

	auto R = PrimeFactorization<Ty>(std::numeric_limits<Ty>::max());

	PrimeDivTest<Ty> PDT;

	for (auto& o : R) {
		std::cout << o << ',';
		if (PDT.IsPrime(o)) {
			std::cout << "PDT Safe";
		}
		std::cout << std::endl;
	}

	return 0;
}
