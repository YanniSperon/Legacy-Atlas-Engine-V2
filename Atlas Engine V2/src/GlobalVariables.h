#pragma once

#include <vector>
#include <string>
#include <chrono>

namespace Atlas {
	class GlobalVariables {
	private:

	public:
		GlobalVariables();

		std::vector<std::string> consoleLog;
		std::chrono::steady_clock::time_point systemStartTime;
	};
}