#include <memory>
#include <string>
#include <type_traits>



template <typename Concrete, typename... Ts>
std::unique_ptr<Concrete>
constructArgs(Ts&&... params)
{
	if constexpr (std::is_constructible_v<Concrete, Ts...>)
		return std::make_unique<Concrete>(std::forward<Ts>(params)...);
	else
		return nullptr;
}

#include <iostream>

int main()
{
	auto up = constructArgs<std::string>(12, 'A');

	std::cout << "*up : " << *up << "\n";

	return 0;
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
