#pragma once

#include <vector>
#include <string>
#include <chrono>

#include "Scene.h"

namespace Atlas {
	class GlobalVariables {
	private:

	public:
		GlobalVariables();

		std::vector<std::string> consoleLog;
		std::chrono::steady_clock::time_point systemStartTime;
		int screenWidth;
		int screenHeight;

		Scene* currentScene;
	};
}