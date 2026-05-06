/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Logger.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: driemers <driemers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/17 13:59:08 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/21 14:25:55 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

std::unique_ptr<Logger> Logger::_instance = nullptr; // Initialize static instance pointer

Logger::Logger(const std::string& filename): _filename(filename) {
	_logFile.open(filename, std::ios::out | std::ios::app);
	if (!_logFile.is_open()) {
		std::cerr << "Error opening log file: " << filename << std::endl;
	}
	else
		logLog();
}

Logger::~Logger() {
	if (_logFile.is_open()) {
		_logFile.close();
	}
}

void Logger::log(const std::string& msg, LogLevel level) {
	std::time_t now = std::time(nullptr);
	if (_logFile.is_open()){
		_logFile << "[" << std::put_time(std::localtime(&now), "%F %T") << "] ";
		switch (level) {
		case INFO:
		_logFile << "INFO: ";
		break;
		case WARNING:
		_logFile << "WARNING: ";
		break;
		case ERROR:
		_logFile << "ERROR: ";
		break;
		case DEBUG:
		_logFile << "DEBUG: ";
		break;
		default:
		std::cerr << "Unknown log level" << std::endl;
		break;
	}
	_logFile << msg << std::endl;
}
}

void Logger::logLog()
{
	_logFile << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⣻⣿⠿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠰⠋⠁⠀⠀⢹⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⡰⠋⠈⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⢀⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣠⣾⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⡠⠀⠀⠀⠀⠀⠀⡀⠀⠀⢘⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⢀⡠⠊⠀⠀⠀⠀⠀⡠⠞⣻⣶⣤⣿⣻⣿⣿⣿⣿\n⣿⣿⣿⣿⡿⠋⠀⠀⠀⢀⣴⠟⠁⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⡿⠟⠛⠓⠶⣦⣾⡿⠁⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⠏⣠⠾⠿⠷⣦⣌⠻⣦⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⠀⠁⠀⠀⠀⠈⠻⣧⠹⣧⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⡄⠀⠀⡀⠀⠀⠀⣻⡇⣿⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣤⣼⠁⠀⠀⠤⠟⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣦⣤⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n";
}
