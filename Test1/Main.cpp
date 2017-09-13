#include "../Engine301A/LogManager.h"

int main(int argc, char* args[]) {
	
	LogManager::getInstance().setLogFile(std::string("logfile.log"));
	LogManager::getInstance().setMinSeverity(LogManager::LogLevel::LOG_WARN);

	LogManager::getInstance().info("stuff happened");
	LogManager::getInstance().trace("stuff started");
	LogManager::getInstance().warn("stuff is weird");
	LogManager::getInstance().error("stuff is broken");

	return 0;
}