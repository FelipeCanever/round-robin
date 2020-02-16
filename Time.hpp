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

		friend auto operator << (std::ostream& ostream, Time time) -> std::ostream&;
		friend auto operator >> (std::istream& istream, Time& time) -> std::istream&;

		friend auto operator < (Time a, Time b) -> bool;

	private:
		T _value;
		static auto validate(T value) -> T;
	};
}
