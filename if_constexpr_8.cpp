//modern c++ examples

#include <type_traits>

class X {
public:
	double a_function_that_exists_only_for_X()
	{
		return 2.3;
	}
};

#include <iostream>

template <class T>
auto foo(T t) 
{
	if constexpr (std::is_same_v<T, X>) {
		return t.a_function_that_exists_only_for_X();
	}
	else {
		std::cout << t << '\n';
		return;
	}
}

int main() 
{
	X x;
	auto i = foo(x);
	foo(23);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

