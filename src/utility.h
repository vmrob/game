#include <random>
#include <limits>
#include <type_traits>

namespace utility_detail {
	std::default_random_engine _gGenerator(std::chrono::system_clock::now().time_since_epoch().count());
}

template <typename T, typename MinType = T, typename MaxType = T>
T Random(
	MinType min = std::numeric_limits<MaxType>::min(),
	MaxType max = std::numeric_limits<MaxType>::max()
) {
	static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
	typedef typename std::conditional<
						std::is_floating_point<T>::value,
						std::uniform_real_distribution<T>,
						std::uniform_int_distribution<T>>
					::type DistributionType;
	DistributionType distribution(min, max);
	return distribution(utility_detail::_gGenerator);
}