/*!
	@file
	@author		Ustinov Igor aka Igor', DadyaIgor
	@date		09/2011
*/
#ifndef MYGUI_DIRECTX11_DIAGNOSTIC_H_
#define MYGUI_DIRECTX11_DIAGNOSTIC_H_

#include "MyGUI_Prerequest.h"

#define MYGUI_PLATFORM_LOG_SECTION "Platform"
#define MYGUI_PLATFORM_LOG_FILENAME "MyGUI.log"
#define MYGUI_PLATFORM_LOG(level, text) MYGUI_LOGGING(MYGUI_PLATFORM_LOG_SECTION, level, text)

#define MYGUI_PLATFORM_EXCEPT(dest) \
{ \
	MYGUI_PLATFORM_LOG(Critical, dest); \
	MYGUI_DBG_BREAK;\
	std::ostringstream stream; \
	stream << dest << "\n"; \
	MYGUI_BASE_EXCEPT(stream.str().c_str(), "MyGUI"); \
}

#define MYGUI_PLATFORM_ASSERT(exp, dest) \
{ \
	if ( ! (exp) ) \
	{ \
		MYGUI_PLATFORM_LOG(Critical, dest); \
		MYGUI_DBG_BREAK;\
		std::ostringstream stream; \
		stream << dest << "\n"; \
		MYGUI_BASE_EXCEPT(stream.str().c_str(), "MyGUI"); \
	} \
}

#endif // MYGUI_DIRECTX11_DIAGNOSTIC_H_
