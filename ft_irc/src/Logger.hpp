/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: driemers <driemers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:55:54 by jovieira          #+#    #+#             */
/*   Updated: 2025/07/16 16:51:15 by driemers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <memory>

enum LogLevel {
	INFO,
	WARNING,
	ERROR,
	DEBUG // not implemented yet
};

class Logger {

	private:
		std::ofstream 	_logFile;
		std::string 	_filename;
		static std::unique_ptr<Logger> 	_instance; // singleton instance

	public:
		Logger(const std::string& filename);
		~Logger();
		// used unique_ptr so i dont have to delete class instance
		static Logger* get() {
			if (_instance == nullptr) {
				_instance = std::unique_ptr<Logger>(new Logger("Server.log")); // default log file name
			}
			return _instance.get();
		}
		void	log(const std::string& msg, LogLevel level);
		void	logLog();
};

#endif
