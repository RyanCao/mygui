/*!
	@file
	@author		Albert Semenov
	@date		04/2010
*/
/*
	This file is part of MyGUI.

	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "MyGUI_Precompiled.h"
#include "MyGUI_FileLogListener.h"
#include <iomanip>
//#include <time.h>

namespace MyGUI
{

	FileLogListener::FileLogListener(const std::string& _fileName) :
		mFileName(_fileName)
	{
	}

	void FileLogListener::open()
	{
		mStream.open(mFileName.c_str(), std::ios_base::out);
	}

	void FileLogListener::close()
	{
		if (mStream.is_open())
			mStream.close();
	}

	void FileLogListener::flush()
	{
		if (mStream.is_open())
			mStream.flush();
	}

	void FileLogListener::log(const std::string& _section, LogLevel _level, const struct tm* _time, const std::string& _message, const char* _file, int _line)
	{
		if (mStream.is_open())
		{
			const char* separator = "  |  ";
			mStream << std::setw(2) << std::setfill('0') << _time->tm_hour << ":"
				<< std::setw(2) << std::setfill('0') << _time->tm_min << ":"
				<< std::setw(2) << std::setfill('0') << _time->tm_sec << separator
				<< _section << separator << _level.print() << separator
				<< _message << separator << _file << separator << _line << std::endl;
		}
	}

}
