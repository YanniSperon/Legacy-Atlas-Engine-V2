#include "GlobalVariables.h"

Atlas::GlobalVariables::GlobalVariables()
{
	// Initialize default values

	consoleLog = std::vector<std::string>();
	systemStartTime = std::chrono::high_resolution_clock::now();
}
