#ifndef __MENU__LOCALES__
#define __MENU__LOCALES__

#include <avr/pgmspace.h>
#include <string.h>

//#define FRENCH 1

const static PROGMEM prog_uchar ON_MSG[] =      "ON ";
const static PROGMEM prog_uchar OFF_MSG[] =     "OFF";

const static PROGMEM prog_uchar ON_CELCIUS_MSG[] = "/   C";
const static PROGMEM prog_uchar CELCIUS_MSG[] =    "C    ";
const static PROGMEM prog_uchar BLANK_CHAR_MSG[] = " ";
const static PROGMEM prog_uchar BLANK_CHAR_4_MSG[] = "    ";

const static PROGMEM prog_uchar CLEAR_MSG[]     =  "                ";

#ifdef LOCALE_FR
#include "Menu.FR.hh"
#else // Use US ENGLISH as default

//single(xAxis173,yAxis225),dual(xAxis140,yAxis225)
#define LEVEL_PLATE_SINGLE const static uint8_t LevelPlateSingle[] PROGMEM = {\
		137,  8,  153,  0,  0,  0,  0,  82,  101,  112,\
		71,  32,  66,  117,  105,  108,  100,  0,  150,  0,\
		255,  132,  3,  105,  1,  0,  0,  20,  0,  131,\
		4,  136,  0,  0,  0,  20,  0,  140,  0,  0,\
		0,  0,  0,  0,  0,  0,  48,  248,  255,  255,\
		0,  0,  0,  0,  0,  0,  0,  0,  155,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  165,\
		28,  0,  0,  24,  0,  0,  160,  64,  149,  4,\
		131,  4,  220,  5,  0,  0,  20,  0,  144,  31,\
		139,  0,  0,  0,  0,  0,  0,  0,  0,  160,\
		15,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  128,  0,  0,  0,  155,  0,  0,  0,  0,\
		0,  0,  0,  0,  164,  15,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  165,  28,  0,  0,\
		24,  10,  215,  35,  60,  149,  4,  155,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  160,  15,\
		0,  0,  24,  246,  40,  32,  65,  128,  2,  137,\
		27,  149,  0,  0,  0,  0,  66,  121,  32,  104,\
		97,  110,  100,  32,  109,  111,  118,  101,  32,  116,\
		104,  101,  32,  101,  120,  45,  0,  149,  1,  0,\
		0,  0,  116,  114,  117,  100,  101,  114,  32,  116,\
		111,  32,  100,  105,  102,  102,  101,  114,  101,  110,\
		116,  32,  0,  149,  1,  0,  0,  0,  112,  111,\
		115,  105,  116,  105,  111,  110,  115,  32,  111,  118,\
		101,  114,  32,  116,  104,  101,  32,  32,  0,  149,\
		7,  0,  0,  0,  98,  117,  105,  108,  100,  32,\
		112,  108,  97,  116,  102,  111,  114,  109,  46,  46,\
		46,  46,  0,  149,  0,  0,  0,  0,  65,  100,\
		106,  117,  115,  116,  32,  116,  104,  101,  32,  115,\
		112,  97,  99,  105,  110,  103,  32,  32,  0,  149,\
		1,  0,  0,  0,  98,  101,  116,  119,  101,  101,\
		110,  32,  116,  104,  101,  32,  101,  120,  116,  114,\
		117,  100,  101,  114,  0,  149,  1,  0,  0,  0,\
		110,  111,  122,  122,  108,  101,  32,  97,  110,  100,\
		32,  112,  108,  97,  116,  102,  111,  114,  109,  32,\
		0,  149,  7,  0,  0,  0,  119,  105,  116,  104,\
		32,  116,  104,  101,  32,  107,  110,  111,  98,  115,\
		46,  46,  46,  0,  149,  0,  0,  0,  0,  117,\
		110,  100,  101,  114,  32,  116,  104,  101,  32,  112,\
		108,  97,  116,  102,  111,  114,  109,  32,  32,  0,\
		149,  1,  0,  0,  0,  97,  110,  100,  32,  97,\
		32,  115,  104,  101,  101,  116,  32,  111,  102,  32,\
		112,  97,  112,  101,  114,  0,  149,  1,  0,  0,\
		0,  112,  108,  97,  99,  101,  100,  32,  98,  101,\
		116,  119,  101,  101,  110,  32,  116,  104,  101,  32,\
		32,  0,  149,  7,  0,  0,  0,  112,  108,  97,\
		116,  102,  111,  114,  109,  32,  97,  110,  100,  32,\
		116,  104,  101,  46,  46,  46,  0,  149,  0,  0,\
		0,  0,  110,  111,  122,  122,  108,  101,  46,  32,\
		87,  104,  101,  110,  32,  121,  111,  117,  32,  97,\
		114,  101,  0,  149,  1,  0,  0,  0,  100,  111,\
		110,  101,  44,  32,  112,  114,  101,  115,  115,  32,\
		116,  104,  101,  32,  32,  32,  32,  32,  0,  149,\
		7,  0,  0,  0,  99,  101,  110,  116,  101,  114,\
		32,  98,  117,  116,  116,  111,  110,  46,  0,  137,\
		31\
		};
#define LEVEL_PLATE_LEN_SINGLE 571

#define LEVEL_PLATE_DUAL const static uint8_t LevelPlateDual[] PROGMEM = {\
		137,  8,  153,  0,  0,  0,  0,  82,  101,  112,\
		71,  32,  66,  117,  105,  108,  100,  0,  150,  0,\
		255,  132,  3,  105,  1,  0,  0,  20,  0,  131,\
		4,  136,  0,  0,  0,  20,  0,  140,  0,  0,\
		0,  0,  0,  0,  0,  0,  48,  248,  255,  255,\
		0,  0,  0,  0,  0,  0,  0,  0,  155,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  165,\
		28,  0,  0,  24,  0,  0,  160,  64,  149,  4,\
		131,  4,  220,  5,  0,  0,  20,  0,  144,  31,\
		139,  0,  0,  0,  0,  0,  0,  0,  0,  160,\
		15,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  128,  0,  0,  0,  155,  0,  0,  0,  0,\
		0,  0,  0,  0,  164,  15,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  165,  28,  0,  0,\
		24,  10,  215,  35,  60,  149,  4,  155,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  160,  15,\
		0,  0,  24,  246,  40,  32,  65,  128,  2,  137,\
		27,  149,  0,  0,  0,  0,  66,  121,  32,  104,\
		97,  110,  100,  32,  109,  111,  118,  101,  32,  116,\
		104,  101,  32,  101,  120,  45,  0,  149,  1,  0,\
		0,  0,  116,  114,  117,  100,  101,  114,  32,  116,\
		111,  32,  100,  105,  102,  102,  101,  114,  101,  110,\
		116,  32,  0,  149,  1,  0,  0,  0,  112,  111,\
		115,  105,  116,  105,  111,  110,  115,  32,  111,  118,\
		101,  114,  32,  116,  104,  101,  32,  32,  0,  149,\
		7,  0,  0,  0,  98,  117,  105,  108,  100,  32,\
		112,  108,  97,  116,  102,  111,  114,  109,  46,  46,\
		46,  46,  0,  149,  0,  0,  0,  0,  65,  100,\
		106,  117,  115,  116,  32,  116,  104,  101,  32,  115,\
		112,  97,  99,  105,  110,  103,  32,  32,  0,  149,\
		1,  0,  0,  0,  98,  101,  116,  119,  101,  101,\
		110,  32,  116,  104,  101,  32,  101,  120,  116,  114,\
		117,  100,  101,  114,  0,  149,  1,  0,  0,  0,\
		110,  111,  122,  122,  108,  101,  32,  97,  110,  100,\
		32,  112,  108,  97,  116,  102,  111,  114,  109,  32,\
		0,  149,  7,  0,  0,  0,  119,  105,  116,  104,\
		32,  116,  104,  101,  32,  107,  110,  111,  98,  115,\
		46,  46,  46,  0,  149,  0,  0,  0,  0,  117,\
		110,  100,  101,  114,  32,  116,  104,  101,  32,  112,\
		108,  97,  116,  102,  111,  114,  109,  32,  32,  0,\
		149,  1,  0,  0,  0,  97,  110,  100,  32,  97,\
		32,  115,  104,  101,  101,  116,  32,  111,  102,  32,\
		112,  97,  112,  101,  114,  0,  149,  1,  0,  0,\
		0,  112,  108,  97,  99,  101,  100,  32,  98,  101,\
		116,  119,  101,  101,  110,  32,  116,  104,  101,  32,\
		32,  0,  149,  7,  0,  0,  0,  112,  108,  97,\
		116,  102,  111,  114,  109,  32,  97,  110,  100,  32,\
		116,  104,  101,  46,  46,  46,  0,  149,  0,  0,\
		0,  0,  110,  111,  122,  122,  108,  101,  46,  32,\
		87,  104,  101,  110,  32,  121,  111,  117,  32,  97,\
		114,  101,  0,  149,  1,  0,  0,  0,  100,  111,\
		110,  101,  44,  32,  112,  114,  101,  115,  115,  32,\
		116,  104,  101,  32,  32,  32,  32,  32,  0,  149,\
		7,  0,  0,  0,  99,  101,  110,  116,  101,  114,\
		32,  98,  117,  116,  116,  111,  110,  46,  0,  137,\
		31\
		};
#define LEVEL_PLATE_LEN_DUAL 571

#define LEVEL_PLATE_SINGLE_CH const static uint8_t LevelPlateSingleCH[] PROGMEM = {\
		137,  8,  153,  0,  0,  0,  0,  82,  101,  112,\
		71,  32,  66,  117,  105,  108,  100,  0,  150,  0,\
		255,  132,  3,  105,  1,  0,  0,  20,  0,  131,\
		4,  136,  0,  0,  0,  20,  0,  140,  0,  0,\
		0,  0,  0,  0,  0,  0,  48,  248,  255,  255,\
		0,  0,  0,  0,  0,  0,  0,  0,  155,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  165,\
		28,  0,  0,  24,  0,  0,  160,  64,  149,  4,\
		131,  4,  220,  5,  0,  0,  20,  0,  144,  31,\
		139,  0,  0,  0,  0,  0,  0,  0,  0,  160,\
		15,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  128,  0,  0,  0,  155,  0,  0,  0,  0,\
		0,  0,  0,  0,  164,  15,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  165,  28,  0,  0,\
		24,  10,  215,  35,  60,  149,  4,  155,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  160,  15,\
		0,  0,  24,  246,  40,  32,  65,  128,  2,  137,\
		27, 0x95, 0x06, 0x00, 0x00, 0x00, 0x2F, 0x99, 0x9a, 0x46,\
		0x47, 0x34, 0x9F, 0x0E, 0x56, 0x9D, 0x12, 0x19, 0x9e, 0x00,\
		0x95, 0x06, 0x00, 0x00, 0x00, 0x42, 0x43, 0x4B, 0x43, 0x46,\
		0x47, 0x92, 0xAD, 0xAE, 0x58, 0xAF, 0x41, 0x0E, 0x00, 0x95,\
		0x06, 0x00, 0x00, 0x00, 0x86, 0x43, 0x86, 0x87, 0xA2, 0x27,\
		0x95, 0x46, 0x47, 0x99, 0x9A, 0x34, 0x6E, 0xA6, 0xA7, 0x00,\
		0x95, 0x06, 0x00, 0x00, 0x00, 0x27, 0x95, 0x50, 0x51, 0x94,\
		0xA8, 0xA9, 0x23, 0x24, 0x15, 0x19, 0x00, 137, 31\
		};
#define LEVEL_PLATE_LEN_SINGLE_CH 269

#define LEVEL_PLATE_DUAL_CH const static uint8_t LevelPlateDualCH[] PROGMEM = {\
		137,  8,  153,  0,  0,  0,  0,  82,  101,  112,\
		71,  32,  66,  117,  105,  108,  100,  0,  150,  0,\
		255,  132,  3,  105,  1,  0,  0,  20,  0,  131,\
		4,  136,  0,  0,  0,  20,  0,  140,  0,  0,\
		0,  0,  0,  0,  0,  0,  48,  248,  255,  255,\
		0,  0,  0,  0,  0,  0,  0,  0,  155,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  165,\
		28,  0,  0,  24,  0,  0,  160,  64,  149,  4,\
		131,  4,  220,  5,  0,  0,  20,  0,  144,  31,\
		139,  0,  0,  0,  0,  0,  0,  0,  0,  160,\
		15,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  128,  0,  0,  0,  155,  0,  0,  0,  0,\
		0,  0,  0,  0,  164,  15,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  165,  28,  0,  0,\
		24,  10,  215,  35,  60,  149,  4,  155,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  0,  0,\
		0,  0,  0,  0,  0,  0,  0,  0,  160,  15,\
		0,  0,  24,  246,  40,  32,  65,  128,  2,  137,\
		27, 0x95, 0x06, 0x00, 0x00, 0x00, 0x2F, 0x99, 0x9a, 0x46,\
		0x47, 0x34, 0x9F, 0x0E, 0x56, 0x9D, 0x12, 0x19, 0x9e, 0x00,\
		0x95, 0x06, 0x00, 0x00, 0x00, 0x42, 0x43, 0x4B, 0x43, 0x46,\
		0x47, 0x92, 0xAD, 0xAE, 0x58, 0xAF, 0x41, 0x0E, 0x00, 0x95,\
		0x06, 0x00, 0x00, 0x00, 0x86, 0x43, 0x86, 0x87, 0xA2, 0x27,\
		0x95, 0x46, 0x47, 0x99, 0x9A, 0x34, 0x6E, 0xA6, 0xA7, 0x00,\
		0x95, 0x06, 0x00, 0x00, 0x00, 0x27, 0x95, 0x50, 0x51, 0x94,\
		0xA8, 0xA9, 0x23, 0x24, 0x15, 0x19, 0x00, 137, 31\
		};
#define LEVEL_PLATE_LEN_DUAL_CH 269

#ifdef MODEL_REPLICATOR
const static PROGMEM prog_uchar SPLASH1_MSG[] = "  MBot 3D Printer   ";
#if !defined(HEATERS_ON_STEROIDS)
const static PROGMEM prog_uchar SPLASH2_MSG[] = "----------------";
#else
const static PROGMEM prog_uchar SPLASH2_MSG[] = "-- Heater Special --";
#endif
#elif MODEL_REPLICATOR2
#ifdef SINGLE_EXTRUDER
const static PROGMEM prog_uchar SPLASH1_MSG[]  = "   The MBot CUBE    ";
#else
const static PROGMEM prog_uchar SPLASH1_MSG[] = "   The MBot CUBE    ";
#endif
const static PROGMEM prog_uchar SPLASH2_MSG[] = "--------------------";
#else
#warning "*** Compiling without MODEL_x defined ***"
const static PROGMEM prog_uchar SPLASH1_MSG[] = "      Sailfish      ";
const static PROGMEM prog_uchar SPLASH2_MSG[] = "      --------      ";
#endif
const static PROGMEM prog_uchar SPLASH3_MSG[] = "Thing 32084 r";
const static PROGMEM prog_uchar SPLASH4_MSG[] = "Firmware Version";
const static PROGMEM prog_uchar SPLASH5_MSG[] = "---Magicfirm----";

#ifdef STACK_PAINT
const static PROGMEM prog_uchar SPLASH_SRAM_MSG[] = "Free SRAM ";
#endif

const static PROGMEM prog_uchar SPLASH1A_MSG[] = "    FAIL!       ";
const static PROGMEM prog_uchar SPLASH2A_MSG[] = "    SUCCESS!    ";
const static PROGMEM prog_uchar SPLASH3A_MSG[] = "connected       ";
const static PROGMEM prog_uchar SPLASH4A_MSG[] = "Heaters are not ";

const static PROGMEM prog_uchar GO_MSG[] =         "StartPreheating";
const static PROGMEM prog_uchar GO_MSG_CH[] =       {0x2a,0x8d,0x1a,0x0a,0x00};
const static PROGMEM prog_uchar STOP_MSG[] =       "TurnHeaters Off";
const static PROGMEM prog_uchar STOP_MSG_CH[] =     {0x1b,0x2b,0x1a,0x0a,0x00};
const static PROGMEM prog_uchar PREHEATING_MSG[] =	"Preheat";
const static PROGMEM prog_uchar PREHEATING_MSG_CH[] = {0x1a,0x0a,0x00};

const static PROGMEM prog_uchar PLATFORM_MSG[] =   "Platform";
const static PROGMEM prog_uchar PLATFORM_MSG_CH[] = {0x99,0x9a,0x00};
const static PROGMEM prog_uchar TOOL_MSG[] =       "Extruder";
const static PROGMEM prog_uchar TOOL_MSG_CH[] =     {0x46,0x47,0x00};
const static PROGMEM prog_uchar NOZZLE_ERROR_MSG[] = "Toolhead Offset Sys must be set to NEW to use this utility.";
const static PROGMEM prog_uchar START_TEST_MSG[]=  "I'm going to print a series of lines so we can find my nozzle alignment.";
const static PROGMEM prog_uchar EXPLAIN1_MSG[] =   "Look for the best matched line in each axis set. Lines are numbered 1-13 and...";
const static PROGMEM prog_uchar EXPLAIN2_MSG[] =   "line one is extra long. The Y axis set is left on the plate and X axis is right.";
const static PROGMEM prog_uchar END_MSG  [] =      "Great!  I've saved these settings and I'll use them to make nice prints!";

const static PROGMEM prog_uchar SELECT_MSG[] =     "Select best lines.";
const static PROGMEM prog_uchar DONE_MSG[]   =     "Done";
const static PROGMEM prog_uchar NO_MSG[]   =       "NO ";
const static PROGMEM prog_uchar YES_MSG[]  =       "YES";

const static PROGMEM prog_uchar XAXIS_MSG[] =      "X Axis Line";
const static PROGMEM prog_uchar YAXIS_MSG[] =      "Y Axis Line";

const static PROGMEM prog_uchar HEATER_ERROR_MSG[]=  "Extruders are not heating. Check the wiring.";

const static PROGMEM prog_uchar STOP_EXIT_MSG[]   = "load/unload...";
const static PROGMEM prog_uchar TIMEOUT_MSG[]  	  = "timeout!";
const static PROGMEM prog_uchar TIMEOUT_MSG_CH[]  	  = {0x39,0x08,0x00};

const static PROGMEM prog_uchar LOAD_RIGHT_MSG[] 	= 	"Load right";
const static PROGMEM prog_uchar LOAD_RIGHT_MSG_CH[] = 	{0x4f,0x47,0x1f,0x20,0x00};
const static PROGMEM prog_uchar LOAD_LEFT_MSG[] 	=  	"Load left";
const static PROGMEM prog_uchar LOAD_LEFT_MSG_CH[] 	=  	{0x4e,0x47,0x1f,0x20,0x00};
const static PROGMEM prog_uchar LOAD_SINGLE_MSG[] 	=	"Load";
const static PROGMEM prog_uchar LOAD_SINGLE_MSG_CH[] =	{0x1f,0x20,0x00};
const static PROGMEM prog_uchar UNLOAD_SINGLE_MSG[]	=	"Unload";
const static PROGMEM prog_uchar UNLOAD_SINGLE_MSG_CH[]=	{0x0f,0x20,0x00};
const static PROGMEM prog_uchar UNLOAD_RIGHT_MSG[]	=	"Unload right";
const static PROGMEM prog_uchar UNLOAD_RIGHT_MSG_CH[]=	{0x4f,0x47,0x0f,0x20,0x00};
const static PROGMEM prog_uchar UNLOAD_LEFT_MSG[] 	=	"Unload left";
const static PROGMEM prog_uchar UNLOAD_LEFT_MSG_CH[] =	{0x4e,0x47,0x0f,0x20,0x00};

const static PROGMEM prog_uchar JOG1_MSG[]  = "    Jog mode    ";
const static PROGMEM prog_uchar JOG2_MSG[] = "  X    Y    Z   ";
const static PROGMEM prog_uchar JOG3_MSG[] = "Back";
const static PROGMEM prog_uchar JOG4_MSG[] = "(^ to back)";

const static PROGMEM prog_uchar DISTANCESHORT_MSG[] = "SHORT";
const static PROGMEM prog_uchar DISTANCELONG_MSG[] =  "LONG";

const static PROGMEM prog_uchar HEATING_MSG[] =        "Heating...     ";
const static PROGMEM prog_uchar HEATING_SPACES_MSG[] = "Heating:        ";

const static PROGMEM prog_uchar BUILD_PERCENT_MSG[] =  "            --% ";
const static PROGMEM prog_uchar EXTRUDER2_TEMP_MSG[] =   {' ','L','E','F','T',':','_','_','_','/','_','_','_',0x7f,0x00};
const static PROGMEM prog_uchar EXTRUDER1_TEMP_MSG[] =   {'R','I','G','H','T',':','_','_','_','/','_','_','_',0x7f,0x00};
const static PROGMEM prog_uchar EXTRUDER_TEMP_MSG[]  =   {'_','_','_','/','_','_','_',0x7f,0x00};
const static PROGMEM prog_uchar EXTRUDER2_TEMP_SMSG[] =   " LEFT";
const static PROGMEM prog_uchar EXTRUDER1_TEMP_SMSG[] =   "RIGHT";

const static PROGMEM prog_uchar PLATFORM_TEMP_MSG[]  =   "Platform---/---C";
const static PROGMEM prog_uchar BUILD_LEFT1_MSG[]  =  "Time Left";
const static PROGMEM prog_uchar BUILD_LEFT2_MSG[]  =  " secs";
const static PROGMEM prog_uchar BUILD_LEFT_MSG_CH[]  =  {0x32,0x33,0x08,0x34,0x00};
const static PROGMEM prog_uchar ESTIMATE_TIME_MSG[]  =  "calculating...";
const static PROGMEM prog_uchar ESTIMATE_TIME_MSG_CH[]  =  {0x2e,0x2f,0x30,0x31,0x32,0x33,0x08,0x34,0x00};


const static PROGMEM prog_uchar EXTRUDER_SPACES_MSG[]  = "Extruder       ";
const static PROGMEM prog_uchar EXTRUDER_SPACES_MSG_CH[]  = {0x46,0x47,0x00};
const static PROGMEM prog_uchar RIGHT_SPACES_MSG[]     = "Right Tool     ";
const static PROGMEM prog_uchar RIGHT_SPACES_MSG_CH[]  = {0x4f,0x46,0x47,0x00};
const static PROGMEM prog_uchar LEFT_SPACES_MSG[]      = "Left Tool      ";
const static PROGMEM prog_uchar LEFT_SPACES_MSG_CH[]   = {0x4e,0x46,0x47,0x00};
const static PROGMEM prog_uchar PLATFORM_SPACES_MSG[]  = "Platform       ";
const static PROGMEM prog_uchar PLATFORM_SPACES_MSG_CH[]  = {0x99,0x9a,0x00};
const static PROGMEM prog_uchar RESET1_MSG[]           = "Restore factory settings?";
const static PROGMEM prog_uchar RESET1_MSG_CH[]        = {0x11,0x12,0x10,0x13,0x14,0x0e,0x00};

const static PROGMEM prog_uchar CANCEL_MSG[] = "Cancel this print?";
const static PROGMEM prog_uchar CANCEL_MSG_CH[] = {0x16,0x17,0x23,0x24,0x15,0x19,0x00};

const static PROGMEM prog_uchar CANCEL_FIL_MSG[] = "Cancel load/unload?";
const static PROGMEM prog_uchar CANCEL_FIL_MSG_CH[] = {0x16,0x17,0x23,0x24,0x37,0x20,0x00};

const static PROGMEM prog_uchar CANCEL1_MSG[] = "Cancel";
const static PROGMEM prog_uchar CANCEL1_MSG_CH[] = {0x23,0x24,0x00};

const static PROGMEM prog_uchar PAUSE_MSG[]      = "Pause  "; // must be same length as the next msg
const static PROGMEM prog_uchar PAUSE_MSG_CH[]      = {0x06,0x07,0x00};

const static PROGMEM prog_uchar UNPAUSE_MSG[]    = "Unpause"; // must be same length as the prior msg
const static PROGMEM prog_uchar UNPAUSE_MSG_CH[]    = {0x25,0x26,0x00}; 

const static PROGMEM prog_uchar COLD_PAUSE_MSG[] = "Cold Pause";

const static PROGMEM prog_uchar BUILDING_MSG[]    			= "I'm already building";
const static PROGMEM prog_uchar BUILDING_MSG_CH[] 			= {0x2e,0x2f,0x15,0x19,0x01,'\n',0x00};
const static PROGMEM prog_uchar CARDCOMMS_MSG[]   			= "SD card reads are not going well. Trya different card";
const static PROGMEM prog_uchar CARDCOMMS_MSG_CH[]   		= {0x68,0x69,0x6a,0x23,0x6b,0x6c,'\n',0x00};
const static PROGMEM prog_uchar CARDOPENERR_MSG[] 			= "Cannot open the file";
const static PROGMEM prog_uchar CARDOPENERR_MSG_CH[] 		={0x15,0x2a,0x38,0x3c,0x6b,0x6c,'\n',0x00};
const static PROGMEM prog_uchar CARDNOFILES_MSG[] 			= "SD card is empty";
const static PROGMEM prog_uchar CARDNOFILES_MSG_CH[] 		= {0x6d,0x6e,0x68,0x69,'\n',0x00};
const static PROGMEM prog_uchar NOCARD_MSG[]      			= "SD card not present";
const static PROGMEM prog_uchar NOCARD_MSG_CH[]   			= {0x68,0x69,0x58,0x6f,0x2f,'\n',0x00};
const static PROGMEM prog_uchar CARDERROR_MSG[]   			= "SD card read error";
const static PROGMEM prog_uchar CARDERROR_MSG_CH[]   		= {0x68,0x69,0x6a,0x23,0x70,0x71,'\n',0x00};
const static PROGMEM prog_uchar CARDCRC_MSG[]     			= "SD card read error. Too many CRC errors. Bad card contacts or electrical noise.";
const static PROGMEM prog_uchar CARDCRC_MSG_CH[]  			= {0x68,0x69,0x61,0x72,0x70,0x71,'\n',0x00};
const static PROGMEM prog_uchar CARDFORMAT_MSG[]  			= "Unable to read this SD card format. Reformat as FAT-16.";
const static PROGMEM prog_uchar CARDFORMAT_MSG_CH[]  		= {0x68,0x69,0x73,0x45,0x70,0x71,'\n',0x00};
const static PROGMEM prog_uchar CARDSIZE_MSG[]    			= "Unable to read SD card partitions over 2GB in size. Reformat as FAT-16.";
const static PROGMEM prog_uchar CARDSIZE_MSG_CH[]    		= {0x68,0x69,0x74,0x75,0x70,0x71,'\n',0x00};
const static PROGMEM prog_uchar EXTRUDER_TIMEOUT_MSG[] 		= "I timed out while attempting to heat my extruder.";
const static PROGMEM prog_uchar EXTRUDER_TIMEOUT_MSG_CH[] 	= {0x46,0x47,0x09,0x0a,0x76,0x08,'\n',0x00};
const static PROGMEM prog_uchar PLATFORM_TIMEOUT_MSG[] 		= "I timed out while attempting to heat my platform.";
const static PROGMEM prog_uchar PLATFORM_TIMEOUT_MSG_CH[] 	= {0x5e,0x77,0x09,0x0a,0x76,0x08,'\n',0x00};

const static PROGMEM prog_uchar BUILD_MSG[] =            "SD";
const static PROGMEM prog_uchar BUILD_MSG_CH[] =      {0x15,0x19,0x00};
const static PROGMEM prog_uchar PREHEAT_MSG[] =          "Filament";
const static PROGMEM prog_uchar PREHEAT_MSG_CH[] =   {0x37,0x20,0x00};
const static PROGMEM prog_uchar ABOUT_MSG[] =   "About";
const static PROGMEM prog_uchar ABOUT_MSG_CH[] =   {0x1b,0x1c,0x00};
const static PROGMEM prog_uchar UTILITIES_MSG[] =        "Utilities";
const static PROGMEM prog_uchar MONITOR_MSG[] =          "Monitor Mode";
const static PROGMEM prog_uchar JOG_MSG[]   =            "Jog Mode";
const static PROGMEM prog_uchar JOG_MSG_CH[]   =           {0x42,0x43,0x44,0x45,0x00};
const static PROGMEM prog_uchar CALIBRATION_MSG[] =      "Calibrate Axes";
const static PROGMEM prog_uchar HOME_AXES_MSG[] =        "Home Axes";
const static PROGMEM prog_uchar HOME_AXES_MSG_CH[] =        {0x12,0x41,0x00};
const static PROGMEM prog_uchar FILAMENT_OPTIONS_MSG[] = "Filament Load";


const static PROGMEM prog_uchar MODLE_MSG[] = 	 "Model";
const static PROGMEM prog_uchar MODLE_MSG1[] = 	 ":Link";
const static PROGMEM prog_uchar MODLE_MSG_CH[] = 	 {0x3f,0x40,0x00};
const static PROGMEM prog_uchar VERSION_MSG[] = 	 "Version";
const static PROGMEM prog_uchar VERSION_MSG1[] = 	 ":7.7.0";
const static PROGMEM prog_uchar VERSION_MSG_CH[] = 	{0x3b,0x3c,0x3d,0x3e,0x00};

const static PROGMEM prog_uchar DSTEPS_MSG[] =           "Disable Steppers";
const static PROGMEM prog_uchar ESTEPS_MSG[] =           "Enable Steppers  ";
const static PROGMEM prog_uchar PLATE_LEVEL_MSG[] =      "Level Plate";
const static PROGMEM prog_uchar PLATE_LEVEL_MSG_CH[] =   {0x42,0x43,0x27,0x5e,0x00};
const static PROGMEM prog_uchar LED_BLINK_MSG[] =        "Blink LEDs       ";
const static PROGMEM prog_uchar LED_STOP_MSG[] =         "Stop Blinking!";
const static PROGMEM prog_uchar PREHEAT_SET_MSG[] =      "Preheat Setting";
const static PROGMEM prog_uchar PREHEAT_SET_MSG_CH[] =   {0x1a,0x0a,0x14,0x0e,0x00};
const static PROGMEM prog_uchar SETTINGS_MSG[] =         "Setup";
const static PROGMEM prog_uchar SETTINGS_MSG_CH[] =      {0x14,0x0e,0x00};
const static PROGMEM prog_uchar GENERAL_SET_MSG[] =      "General Setting";
const static PROGMEM prog_uchar GENERAL_SET_MSG_CH[] =   {0x4c,0x4d,0x14,0x0e,0x00};
const static PROGMEM prog_uchar RESET_MSG[] =   "Restore Setting";
const static PROGMEM prog_uchar RESET_MSG_CH[] ={0x0d,0x0e,0x00};
const static PROGMEM prog_uchar NOZZLES_MSG[] =          "Calibrate Nozzles";
const static PROGMEM prog_uchar BOT_STATS_MSG[] =        "Bot Statistics";
const static PROGMEM prog_uchar TOOL_COUNT_MSG[]   =     "Extruders";
const static PROGMEM prog_uchar TOOL_COUNT_MSG_CH[] =    {0x46,0x47,0x48,0x00};
const static PROGMEM prog_uchar SOUND_MSG[] =            "Sound";
const static PROGMEM prog_uchar SOUND_MSG_CH[] =        {0x0b,0x0c,0x00};
const static PROGMEM prog_uchar LED_MSG[] =              "LED Colour";
const static PROGMEM prog_uchar LED_HEAT_MSG[] =         "Heat LEDs";
const static PROGMEM prog_uchar EXIT_MSG[] =             "Exit menu";
const static PROGMEM prog_uchar EXIT_MSG_CH[] =        {0x0f,0x10,0x00};
const static PROGMEM prog_uchar ACCELERATE_MSG[] = 	 "Accelerate";
const static PROGMEM prog_uchar HBP_MSG[]                 = "HBP installed";
const static PROGMEM prog_uchar OVERRIDE_GCODE_TEMP_MSG[] = "Override GcTemp";
const static PROGMEM prog_uchar PAUSE_HEAT_MSG[]	  = "Pause&Heat";
const static PROGMEM prog_uchar PAUSE_HEAT_MSG_CH[]	  = {0x06,0x07,0x08,0x09,0x0a,0x00};
const static PROGMEM prog_uchar EXTRUDER_HOLD_MSG[]       = "Extruder Hold";
const static PROGMEM prog_uchar TOOL_OFFSET_SYSTEM_MSG[]  = "Tool Offset Sys";
const static PROGMEM prog_uchar SD_USE_CRC_MSG[]          = "Check SD reads";
const static PROGMEM prog_uchar PSTOP_ENABLE_MSG[]        = "P-Stop control";
const static PROGMEM prog_uchar OLD_MSG[]                 = "OLD";
const static PROGMEM prog_uchar NEW_MSG[]                 = "NEW";
const static PROGMEM prog_uchar DISABLED_MSG[]            = "N/A";

const static PROGMEM prog_uchar LANGUAGE_MSG[]            = "Language";
const static PROGMEM prog_uchar LANGUAGE_MSG_CH[]            = {0x35,0x36,0x00};
const static PROGMEM prog_uchar ENGLISH_MSG[]            = "English";
const static PROGMEM prog_uchar CHINESE_MSG_CH[]            = {0x01,0x38,0x00};

#ifdef DITTO_PRINT
const static PROGMEM prog_uchar DITTO_PRINT_MSG[]         = "Ditto Printing";
#endif
const static PROGMEM prog_uchar PAUSEATZPOS_MSG[]	  = "Pause at ZPos";
const static PROGMEM prog_uchar CHANGE_SPEED_MSG[]        = "Change Speed";
const static PROGMEM prog_uchar CHANGE_SPEED_MSG_CH[]        ={0x27,0x28,0x00};
const static PROGMEM prog_uchar CHANGE_TEMP_MSG[]         = "Change TEMP";
const static PROGMEM prog_uchar CHANGE_TEMP_MSG_CH[]         ={0x27,0x29,0x00};
const static PROGMEM prog_uchar FAN_ON_MSG[]              = "Set Fan ON "; // Needs trailing space
const static PROGMEM prog_uchar FAN_ON_MSG_CH[]              = {0x15,0x2a,0x2c,0x2d,0x00}; 
const static PROGMEM prog_uchar FAN_OFF_MSG[]             = "Set Fan OFF";
const static PROGMEM prog_uchar FAN_OFF_MSG_CH[]             = {0x1b,0x2b,0x2c,0x2d,0x00};
const static PROGMEM prog_uchar RETURN_TO_MAIN_MSG[]      = "Main Menu";
const static PROGMEM prog_uchar RETURN_TO_MAIN_MSG_CH[]   = {0x52,0x53,0x54,0x00};
const static PROGMEM prog_uchar PRINT_ANOTHER_MSG[]       = "Print Copy";
const static PROGMEM prog_uchar PRINT_ANOTHER_MSG_CH[]    = {0x55,0x15,0x56,0x57,0x00};
const static PROGMEM prog_uchar CANNOT_PRINT_ANOTHER_MSG[]= "(Cannot Copy)";
const static PROGMEM prog_uchar CANNOT_PRINT_ANOTHER_MSG_CH[]= {0x58,0x59,0x12,0x5b,0x00};

const static PROGMEM prog_uchar RED_COLOR_MSG[]    = "RED   ";
const static PROGMEM prog_uchar ORANGE_COLOR_MSG[] = "ORANGE";
const static PROGMEM prog_uchar PINK_COLOR_MSG[]   = "PINK  ";
const static PROGMEM prog_uchar GREEN_COLOR_MSG[]  = "GREEN ";
const static PROGMEM prog_uchar BLUE_COLOR_MSG[]   = "BLUE  ";
const static PROGMEM prog_uchar PURPLE_COLOR_MSG[] = "PURPLE";
const static PROGMEM prog_uchar WHITE_COLOR_MSG[]  = "WHITE ";
const static PROGMEM prog_uchar CUSTOM_COLOR_MSG[] = "CUSTOM";
const static PROGMEM prog_uchar OFF_COLOR_MSG[]    = "OFF   ";

const static PROGMEM prog_uchar ERROR_MSG[] =   "error!";
const static PROGMEM prog_uchar NA_MSG[] =      " NA";
const static PROGMEM prog_uchar WAITING_MSG[] = "waiting ";

const static PROGMEM prog_uchar EXTEMP_CHANGE_MSG[]               = "My temperature was changed externally. Reselect filament menu to try again.";
const static PROGMEM prog_uchar EXTEMP_CHANGE_MSG_CH[]            = {0x09,0x0a,0x6b,0x6c,'\n',0x00};
const static PROGMEM prog_uchar HEATER_INACTIVITY_MSG[]           = "Heaters shutdown due to inactivity";
const static PROGMEM prog_uchar HEATER_INACTIVITY_MSG_CH[]        = {0x09,0x0a,0x6b,0x6c,'\n',0x00};
const static PROGMEM prog_uchar HEATER_TOOL_MSG[]                 = "Extruder Failure!";
const static PROGMEM prog_uchar HEATER_TOOL_MSG_CH[]              = {0x46,0x47,0x09,0x0a,0x6b,0x6c,'\n',0x00};
const static PROGMEM prog_uchar HEATER_TOOL0_MSG[]                = "Tool 0 Failure!";
const static PROGMEM prog_uchar HEATER_TOOL0_MSG_CH[]             = {0x4f,0x46,0x47,0x09,0x0a,0x6b,0x6c,'\n',0x00};
const static PROGMEM prog_uchar HEATER_TOOL1_MSG[]                = "Tool 1 Failure!";
const static PROGMEM prog_uchar HEATER_TOOL1_MSG_CH[]             = {0x4e,0x46,0x47,0x09,0x0a,0x6b,0x6c,'\n',0x00};
const static PROGMEM prog_uchar HEATER_PLATFORM_MSG[]             = "Platform Failure!";
const static PROGMEM prog_uchar HEATER_PLATFORM_MSG_CH[]          = {0x5e,0x77,0x09,0x0a,0x6b,0x6c,'\n',0x00};

const static PROGMEM prog_uchar HEATER_FAIL_SOFTWARE_CUTOFF_MSG[] 		= "Temp limit reached. Shutdown or restart.";
const static PROGMEM prog_uchar HEATER_FAIL_SOFTWARE_CUTOFF_MSG_CH[] 	= {0x79,0x29,0x5f,0x1b,0x2b,0x7a,0x0d,0x7b,'\n',0x00};
const static PROGMEM prog_uchar HEATER_FAIL_NOT_HEATING_MSG[]     		= "Not heating properly Check wiring.";
const static PROGMEM prog_uchar HEATER_FAIL_NOT_HEATING_MSG_CH[] 		= {0x09,0x0a,0x6b,0x6c,0x5f,0x7c,0x7d,0x7e,'\n',0x00};
const static PROGMEM prog_uchar HEATER_FAIL_DROPPING_TEMP_MSG[]   		= "Temperature dropping Check wiring.";
const static PROGMEM prog_uchar HEATER_FAIL_DROPPING_TEMP_MSG_CH[] 		= {0x29,0x78,0x7f,0x80,0x5f,0x7c,0x7d,0x7e,'\n',0x00};
const static PROGMEM prog_uchar HEATER_FAIL_NOT_PLUGGED_IN_MSG[]  		= "Temperature reads are failing. Check wiring.";
const static PROGMEM prog_uchar HEATER_FAIL_NOT_PLUGGED_IN_MSG_CH[] 	= {0x29,0x78,0x6a,0x23,0x7f,0x80,0x5f,0x7c,0x7d,0x7e,'\n',0x00};
const static PROGMEM prog_uchar HEATER_FAIL_READ_MSG[]            		= "Temperature reads out of range. Check wiring.";
const static PROGMEM prog_uchar HEATER_FAIL_READ_MSG_CH[] 				= {0x29,0x78,0x81,0x82,0x7f,0x80,0x5f,0x7c,0x7d,0x7e,'\n',0x00};

const static PROGMEM prog_uchar BUILD_TIME_MSG[]	= "Print Time:     h  m"; 
const static PROGMEM prog_uchar Z_POSITION_MSG[]	= "ZPosition:"; 
const static PROGMEM prog_uchar FILAMENT_MSG[]	  = "Filament:"; 
const static PROGMEM prog_uchar FILAMENT_MSG_CH[] = {0x1e,0x20,0x00};
const static PROGMEM prog_uchar PROFILES_MSG[]	  = "Profiles"; 
const static PROGMEM prog_uchar HOME_OFFSETS_MSG[]= "Home Offsets"; 
const static PROGMEM prog_uchar HOME_OFFSETS_MSG_CH[]= {0x01,0x02,0x03,0x04,0x05,0x00}; 
const static PROGMEM prog_uchar TOOL_OFFSETS_MSG[]= "Tool Offsets";
const static PROGMEM prog_uchar TOOL_OFFSETS_MSG_CH[]= {0x46,0x47,0x4a,0x4b,0x49,0x00};
const static PROGMEM prog_uchar MILLIMETERS_MSG[] = "mm";
const static PROGMEM prog_uchar METERS_MSG[]	  = "m";
const static PROGMEM prog_uchar LINE_NUMBER_MSG[] = "Line:               ";
const static PROGMEM prog_uchar LEFT_EXIT_MSG []  = "Left Key to Go Back ";

const static PROGMEM prog_uchar BACK_TO_MONITOR_MSG[] ="Back";
const static PROGMEM prog_uchar BACK_TO_MONITOR_MSG_CH[] ={0x21,0x22,0x00}; 
const static PROGMEM prog_uchar STATS_MSG[]			= "Print Statistics";
const static PROGMEM prog_uchar CANCEL_BUILD_MSG[]    = "Cancel Print"; 
const static PROGMEM prog_uchar CANCEL_BUILD_MSG_CH[]    = {0x23,0x24,0x15,0x19,0x00}; 
const static PROGMEM prog_uchar HEATERS_OFF_MSG[]    = "Heaters Off"; 

const static PROGMEM prog_uchar FILAMENT_ODOMETER_MSG[]    = "Odometer";
const static PROGMEM prog_uchar FILAMENT_LIFETIME1_MSG[]   = "Life:"; 
const static PROGMEM prog_uchar FILAMENT_TRIP1_MSG[]       = "Trip:"; 
const static PROGMEM prog_uchar FILAMENT_LIFETIME2_MSG[]   = "Filament:"; 
const static PROGMEM prog_uchar FILAMENT_TRIP2_MSG[]   	   = "Fil. Trip:"; 
const static PROGMEM prog_uchar FILAMENT_RESET_TRIP_MSG[]  = "  'M' - Reset Trip"; 

const static PROGMEM prog_uchar PROFILE_RESTORE_MSG[]		= "Restore";
const static PROGMEM prog_uchar PROFILE_DISPLAY_CONFIG_MSG[]	= "Display Config";
const static PROGMEM prog_uchar PROFILE_CHANGE_NAME_MSG[]	= "Change Name";
const static PROGMEM prog_uchar PROFILE_SAVE_TO_PROFILE_MSG[]	= "Save To Profile";
const static PROGMEM prog_uchar PROFILE_PROFILE_NAME_MSG[]	= "Profile Name:";
const static PROGMEM prog_uchar UPDNLRM_MSG[]			= "Up/Dn/R/L/M to Set";
const static PROGMEM prog_uchar UPDNLM_MSG[]			= "Up/Dn/M to Set";
const static PROGMEM prog_uchar XYZOFFSET_MSG[]                 = " Offset: ";  // needs extra space
const static PROGMEM prog_uchar PROFILE_RIGHT_MSG[]		= "Right Temp: ";
const static PROGMEM prog_uchar PROFILE_LEFT_MSG[]		= "Left Temp: ";
const static PROGMEM prog_uchar PROFILE_PLATFORM_MSG[]		= "Platform Temp:   ";
const static PROGMEM prog_uchar PAUSE_AT_ZPOS_MSG[]		= "Pause at ZPos: ";

const static PROGMEM prog_uchar PRINTED_TOO_LONG_MSG[]		= "Line:1000000000+";

const static PROGMEM prog_uchar PAUSE_ENTER_MSG[]			= "Entering Pause.."; // Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_ENTER_MSG_CH[]		= {0x1f,0x5d,0x06,0x07,0x01,0x5F,0x5F,0x5F,0x00}; // Needs trailing spaces
const static PROGMEM prog_uchar CANCELLING_ENTER_MSG[]		= "Cancelling Print"; // Needs trailing spaces
const static PROGMEM prog_uchar CANCELLING_ENTER_MSG_CH[]	= {0x23,0x24,0x15,0x19,0x01,0x5F,0x5F,0x5F,0x00}; // Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_LEAVE_MSG[]			= "Leaving Pause...";// Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_LEAVE_MSG_CH[]		= {0x23,0x24,0x06,0x07,0x01,0x5F,0x5F,0x5F,0x00};// Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_DRAINING_PIPELINE_MSG[]		= "Draining pipeline..."; // Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_DRAINING_PIPELINE_MSG_CH[]	= {0x62,0x63,0x64,0x65,0x01,0x5F,0x5F,0x5F,0x00}; // Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_CLEARING_BUILD_MSG[]			= "Clearing build.."; // Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_CLEARING_BUILD_MSG_CH[]		= {0x23,0x24,0x66,0x67,0x01,0x5F,0x5F,0x5F,0x00}; // Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_RESUMING_POSITION_MSG[]		= "Resuming position..."; // Needs trailing spaces
const static PROGMEM prog_uchar PAUSE_RESUMING_POSITION_MSG_CH[]	= {0x11,0x12,0x41,0x0e,0x01,0x5F,0x5F,0x5F,0x00}; // Needs trailing spaces
const static PROGMEM prog_uchar TOTAL_TIME_MSG[]                = "Lifetime:      h 00m";
const static PROGMEM prog_uchar LAST_TIME_MSG[]                 = "Last Print:    h 00m";
const static PROGMEM prog_uchar BUILD_TIME2_MSG[]               =  "Print Time:"; // This string is 19 chars WIDE!
const static PROGMEM prog_uchar BUILD_TIME2_MSG_CH[]            =  {0x15,0x19,0x4d,0x08,0x00};
const static PROGMEM prog_uchar BUILD_FINISH_MSG[]              =  "build Finished!";
const static PROGMEM prog_uchar BUILD_FINISH_MSG_CH[]           =  {0x15,0x19,0x50,0x51,0x00};

#ifdef EEPROM_MENU_ENABLE
	const static PROGMEM prog_uchar EEPROM_MSG[]		= "Eeprom";
	const static PROGMEM prog_uchar EEPROM_DUMP_MSG[]	= "Eeprom -> SD";
	const static PROGMEM prog_uchar EEPROM_RESTORE_MSG[]	= "SD -> Eeprom";
	const static PROGMEM prog_uchar EEPROM_ERASE_MSG[]	= "Erase Eeprom";
#endif

#if defined(AUTO_LEVEL)
const PROGMEM prog_uchar ALEVEL_UTILITY_MSG[]    = "Auto-level Para"; // No more than 19 characters
const PROGMEM prog_uchar ALEVEL_UTILITY_MSG_CH[]    = {0x5a,0x43,0x27,0x5e,0x89,0x48,0x5f,0x5f,0x00};
const PROGMEM prog_uchar ALEVEL_SCREEN_MSG1[]    = "Max height variance between probe pts.";  // No more than 19 characters
const PROGMEM prog_uchar ALEVEL_SCREEN_MSG1_CH[]    = {0x8c,0x03,0x34,0x8a,0x74,0x5a,0x43,0x27,0x5e,0x8b,0x78,0x00};  // No more than 19 characters
const PROGMEM prog_uchar ALEVEL_BADLEVEL_MSG[]   = "Auto-level failed\nToo far out of level";
const PROGMEM prog_uchar ALEVEL_BADLEVEL_MSG_CH[]   = {0x5a,0x43,0x27,0x5e,0x6b,0x6c,'\n',0x76,0x10,0x27,0x5e,0x81,0x82,'\n',0x00};
const PROGMEM prog_uchar ALEVEL_COLINEAR_MSG[]   = "Auto-level failed\nBad probing points";
const PROGMEM prog_uchar ALEVEL_COLINEAR_MSG_CH[]   = {0x5a,0x43,0x27,0x5e,0x6b,0x6c,'\n',0x7d,0x83,0x03,0x7f,0x80,'\n',0x00};
const PROGMEM prog_uchar ALEVEL_INCOMPLETE_MSG[] = "Auto-level failed\nIncomplete probing";
const PROGMEM prog_uchar ALEVEL_INCOMPLETE_MSG_CH[] = {0x5a,0x43,0x27,0x5e,0x6b,0x6c,'\n',0x7d,0x83,0x84,0x50,0x51,'\n',0x00};
const PROGMEM prog_uchar ALEVEL_INACTIVE_MSG[]   = " Auto-level     ";  // must be 20 chars
const PROGMEM prog_uchar ALEVEL_ACTIVE_MSG[]     = " Auto-level ON  ";  // must be 20 chars
#if defined(AUTO_LEVEL_ZYYX)
const PROGMEM prog_uchar ALEVEL_NOT_CALIBRATED_MSG[] = "Auto-level failed\nProbe not calibrated";
#endif
#if defined(PSTOP_SUPPORT) && defined(PSTOP_ZMIN_LEVEL)
const PROGMEM prog_uchar MAX_PROBE_HITS_MSG1[]  = "Max Z Probe Hits"; // No more than 19 characters
const PROGMEM prog_uchar MAX_PROBE_HITS_MSG2[] = "Use 0 for unlimited";
#endif
#endif

const static PROGMEM prog_uchar ERROR_STREAM_VERSION[] = "This is not the x3g version I work best with. "
	"For help see: mbot.com/help   ";

#ifdef MODEL_REPLICATOR2
const static PROGMEM prog_uchar ERROR_BOT_TYPE[] =
    "I am a mbot 3d printer.This build is for another bot. See: mbot.com/help";
#else
const static PROGMEM prog_uchar ERROR_BOT_TYPE[] =
    "I am a mbot 3d printer.  This build is for another bot. See: mbot.com/help";
#endif

#endif //end of default ELSE for US English */

#endif // __MENU__LOCALES__
