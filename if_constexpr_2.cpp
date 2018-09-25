//if constexpr example

#include <iostream>

using namespace std;

template<int N>
constexpr int fibonacci()
{
	if constexpr (N >= 2)
		return fibonacci<N - 1>() + fibonacci<N - 2>();
	else
		return N;
}

#include <iostream>

using namespace std;


int main()
{
	cout << fibonacci<5>() << endl;

	return 0;
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
