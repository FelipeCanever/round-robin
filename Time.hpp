#pragma once

#include <iostream>

namespace roundRobin
{
	class Time
	{
	public:
		using T = int;

		Time(T value);
		Time();

		friend auto operator >> (std::istream& istream, Time& time) -> std::istream&;

	private:
		T _value;
		static auto validate(T value) -> T;
	};
}
