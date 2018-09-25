//modern C++ examples

#include <vector>
#include <string>

class Myclass {
public:
	template <std::size_t N>
	auto get()const;
	Myclass(int x, double dval, const std::string &s, std::initializer_list<int> list):
	mx{x}, md{dval}, ms{s}, mvec{list} {}
private: //don't want anyone messing with my insides
	int mx;
	double md;
	std::string ms;
	std::vector<int> mvec;
};

template <>
auto Myclass::get<0>() const
{
	return mx;
}

template <>
auto Myclass::get<1>() const
{
	return md;
}

template <>
auto Myclass::get<2>() const
{
	return ms;
}

template <>
auto Myclass::get<3>() const
{
	return mvec;
}

#include <iostream>

using namespace std;


int main()
{
	Myclass m{ 12, 2.3, "neco", {1, 2, 3, 4} };

	cout << m.get<0>() << endl;
	cout << m.get<1>() << endl;
	cout << m.get<2>() << endl;

	for (auto val : m.get<3>())
		cout << val << " ";
	cout << endl;

	return 0;
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
