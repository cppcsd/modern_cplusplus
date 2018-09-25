//modern C++ examples

template<unsigned n>
struct Get {
	template<class X, class ...Xs>
	constexpr auto operator()(X x, Xs ...xs) {
		if constexpr (n > sizeof...(xs)) {
			return;
		}
		else if constexpr (n > 0) {
			return Get<n - 1>{}(xs...);
		}
		else {
			return x;
		}
	}
};
