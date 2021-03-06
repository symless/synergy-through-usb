/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2012 Bolton Software Ltd.
 * Copyright (C) 2002 Chris Schoeneman
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file COPYING that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "CAppUtil.h"
#include "CString.h"

#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

#define ARCH_APP_UTIL CAppUtilWindows

enum AppExitMode {
	kExitModeNormal,
	kExitModeDaemon
};

class CAppUtilWindows : public CAppUtil {
public:
	CAppUtilWindows();
	virtual ~CAppUtilWindows();

	bool parseArg(const int& argc, const char* const* argv, int& i);

	int daemonNTStartup(int, char**);
	
	int daemonNTMainLoop(int argc, const char** argv);

	void debugServiceWait();

	int run(int argc, char** argv);

	void exitApp(int code);

	void beforeAppExit();

	static CAppUtilWindows& instance();

	void startNode();

private:
	AppExitMode m_exitMode;
	static BOOL WINAPI consoleHandler(DWORD CEvent);
};
