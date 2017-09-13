#pragma once
#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <fstream>
#include <iomanip>
#include <string>

class LogManager
{
public:
	// Severity Levels
	enum LogLevel { LOG_NONE, LOG_INFO, LOG_TRACE, LOG_WARN, LOG_ERROR, LOG_ALL };
	// File name
	std::string logFileName;
	
	// Getter and destroyer for Logmanager
	static LogManager& getInstance();
	~LogManager(void);

	// Creates/ Opens/ Closes logfile
	void setLogFile(std::string &fileName);
	void close();

	// Severity setters
	// One
	void setSeverity(LogLevel severity)
	{ currentMinSeverity = severity; currentMaxSeverity = severity; }
	// Min
	void setMinSeverity(LogLevel minSeverity) { currentMinSeverity = minSeverity; }
	// Max
	void setMaxSeverity(LogLevel maxSeverity) { currentMaxSeverity = maxSeverity; }
	// Min & Max
	void setSeverity(LogLevel minSeverity, LogLevel maxSeverity) 
	{ currentMinSeverity = minSeverity; currentMaxSeverity = maxSeverity; }
	
	// Severity getters
	LogLevel getMaxSeverity() { return currentMaxSeverity; }
	LogLevel getMinSeverity() { return currentMinSeverity; }

	// Log functions
	void log(LogLevel severity, std::string msg);
	void error(std::string msg)	{ log(LOG_ERROR, msg); }
	void warn(std::string msg) { log(LOG_WARN, msg); }
	void trace(std::string msg) { log(LOG_TRACE, msg); }
	void info(std::string msg) { log(LOG_INFO, msg); }

private:
	// Constructor
	LogManager(void);

	// Variables
	static LogManager *theInstance;
	std::ofstream *outStream;
	LogLevel currentMinSeverity;
	LogLevel currentMaxSeverity;
};

#endif 

