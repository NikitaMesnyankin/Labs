#ifndef UTILITS_H
#define UTILITS_H

#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

namespace mesnyankin
{
	typedef std::array<std::string, 3> sArray;
	typedef std::tuple<std::string, std::string, std::string, int> eTuple;
	typedef std::vector<eTuple> eTVector;

	template <size_t i = 0, typename... Ts>
	constexpr bool compareData(const std::tuple<Ts...>& tup, const sArray& arr)
	{
		if
			constexpr (i == sizeof...(Ts) - 1)
		{
			return true;
		}
		else {
			if (arr[i].compare(std::get<i>(tup)) != 0) {
				return false;
			}
			return mesnyankin::compareData<i + 1>(tup, arr);
		}
	};

	template <size_t i = 0, typename... Ts>
	constexpr void tie(std::tuple<Ts...> tup, sArray& arr)
	{
		if
			constexpr (i == sizeof...(Ts) - 1)
		{
			return;
		}
		else {
			arr[i] = std::get<i>(tup);
			mesnyankin::tie<i + 1>(tup, arr);
		}
	};

	template<typename... args>
	void outputTuple(const std::tuple<args...>& tpl)
	{
		std::apply([](auto&&... arguments)
			{
				((std::cout << arguments << ' '), ...);
			}, tpl);
		std::cout << std::endl;
	};

	template<std::size_t... Is>
	auto constexpr make_tuple(sArray const& arr, int value, std::index_sequence<(Is)...>)
	{
		return std::make_tuple(arr[Is]..., value);
	}

	auto constexpr make_tuple(sArray const& arr, int value)
	{
		auto constexpr tup_size = std::tuple_size<std::decay_t<sArray>>::value;
		return make_tuple(arr, value, std::make_index_sequence<tup_size>{});
	}

	void erase_from_eTVector(eTVector& etv, const sArray& sArr);

	void outputETVector(const eTVector& etv);

	bool verificateSArray(const sArray&);
	bool verificateETuple(const eTuple&);
	bool verificateETVector(const eTVector&);
}

#endif
