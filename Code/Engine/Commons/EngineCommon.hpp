#pragma once
#include "Engine/Commons/ErrorWarningAssert.hpp"
#include "Engine/Commons/StringUtils.hpp"
#include "Engine/Math/Vec2.hpp"

#pragma warning( error: 4172) // Returning address of local variable or temporary variable
#pragma warning( error: 4172) //Not all control paths return a value

#define UNUSED(x) (void)(x);
#define STATIC

class NamedStrings;
class EventSystems;

extern NamedStrings g_gameConfigBlackboard; // declared in EngineCommon.hpp, defined in EngineCommon.cpp

const unsigned short KEY_ESC = 27;
const unsigned short UP_ARROW = 38;
const unsigned short LEFT_ARROW = 37;
const unsigned short RIGHT_ARROW = 39;
const unsigned short SPACE_KEY = 32;
const unsigned short A_KEY = 'A';
const unsigned short N_KEY = 'N';
const unsigned short T_KEY = 'T';
const unsigned short P_KEY = 'P';
const unsigned short F1_KEY = 112;
const unsigned short F2_KEY = 113;
const unsigned short F3_KEY = 114;
const unsigned short F4_KEY = 115;
const unsigned short F5_KEY = 116;
const unsigned short F6_KEY = 117;
const unsigned short F7_KEY = 118;
const unsigned short F8_KEY = 119;
//const unsigned char DOWN_ARROW;

constexpr float		 CONSOLE_LINE_SPACE = 0.05f;


typedef NamedStrings EventArgs;

class DevConsole;

extern DevConsole* g_devConsole;
extern EventSystems* g_eventSystem;