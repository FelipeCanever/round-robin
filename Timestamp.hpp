#pragma once

#include "Process.hpp"

namespace roundRobin
{
	struct Timestamp
	{
		Process& process;
		Time time;
	};
}
