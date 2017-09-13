//#include "StdAfx.h"
#include "LogManager.h"

LogManager* LogManager::theInstance = NULL;

LogManager::LogManager(void)
{
	outStream = NULL;
	logFileName = "logfile.log";
	currentMaxSeverity = LOG_ALL;
	currentMinSeverity = LOG_NONE;
}

LogManager::~LogManager(void)
{
	close();
}

LogManager& LogManager::getInstance(void)
{
	if (theInstance == NULL)
	{
		theInstance = new LogManager();
	}
	return *theInstance;
}

void LogManager::setLogFile(std::string &fileName)
{
	close();
	outStream = new std::ofstream(fileName.c_str());
}

void LogManager::close()
{
	if (outStream != NULL)
	{
		outStream->close();
		delete outStream;
		outStream = NULL;
	}
}

void LogManager::log(LogLevel severity, std::string msg)
{
	if (severity >= currentMinSeverity && severity <= currentMaxSeverity)
	{
		if (outStream == NULL)
		{
			setLogFile(logFileName);
		}
		if (severity == LOG_INFO) {
			(*outStream) << "*INFO*: ";
		}
		else if (severity == LOG_TRACE) {
			(*outStream) << "*TRACE*: ";
		}
		else if (severity == LOG_WARN) {
			(*outStream) << "*WARNING*: ";
		}
		else if (severity == LOG_ERROR) {
			(*outStream) << "*ERROR*: ";
		}
		(*outStream) << msg << "\n";
		outStream->flush();
	}
}
