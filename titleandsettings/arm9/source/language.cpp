#include <nds.h>
#include <stdio.h>
#include <fat.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#include "inifile.h"

extern int appName;	// 0 = DSiMenu++, 1 = SRLoader, 2 = DSisionX

// Strings
std::string STR_SAVING_SETTINGS = "STR_SAVING_SETTINGS";
std::string STR_SETTINGS_SAVED = "STR_SETTINGS_SAVED";

std::string STR_LR_SWITCH = "STR_LR_SWITCH";
std::string STR_GUI_SETTINGS = "STR_GUI_SETTINGS";
std::string STR_GAMESAPPS_SETTINGS = "STR_GAMESAPPS_SETTINGS";

// GUI settings
std::string STR_THEME = "STR_THEME";
std::string STR_LASTPLAYEDROM = "STR_LASTPLAYEDROM";
std::string STR_DSIMENUPPLOGO = "STR_DSIMENUPPLOGO";
std::string STR_DIRECTORIES = "STR_DIRECTORIES";
std::string STR_BOXART = "STR_BOXART";
std::string STR_ANIMATEDSIICONS = "STR_ANIMATEDSIICONS";
std::string STR_STARTBUTTONLAUNCH = "STR_STARTBUTTONLAUNCH";
std::string STR_SYSTEMSETTINGS = "STR_SYSTEMSETTINGS";
std::string STR_REPLACEDSIMENU = "STR_REPLACEDSIMENU";
std::string STR_RESTOREDSIMENU = "STR_RESTOREDSIMENU";

std::string STR_SHOW = "STR_SHOW";
std::string STR_HIDE = "STR_HIDE";

std::string STR_DESCRIPTION_THEME_1 = "STR_DESCRIPTION_THEME_1";
std::string STR_DESCRIPTION_THEME_2 = "STR_DESCRIPTION_THEME_2";

std::string STR_DESCRIPTION_LASTPLAYEDROM_1 = "STR_DESCRIPTION_LASTPLAYEDROM_1";
std::string STR_DESCRIPTION_LASTPLAYEDROM_2 = "STR_DESCRIPTION_LASTPLAYEDROM_2";
std::string STR_DESCRIPTION_LASTPLAYEDROM_3 = "STR_DESCRIPTION_LASTPLAYEDROM_3";
std::string STR_DESCRIPTION_LASTPLAYEDROM_4 = "STR_DESCRIPTION_LASTPLAYEDROM_4";

std::string STR_DESCRIPTION_DSIMENUPPLOGO_1 = "STR_DESCRIPTION_DSIMENUPPLOGO_1";
std::string STR_DESCRIPTION_DSIMENUPPLOGO_2 = "STR_DESCRIPTION_DSIMENUPPLOGO_2";
std::string STR_DESCRIPTION_DSIMENUPPLOGO_3 = "STR_DESCRIPTION_DSIMENUPPLOGO_3";

std::string STR_DESCRIPTION_DIRECTORIES_1 = "STR_DESCRIPTION_DIRECTORIES_1";
std::string STR_DESCRIPTION_DIRECTORIES_2 = "STR_DESCRIPTION_DIRECTORIES_2";
std::string STR_DESCRIPTION_DIRECTORIES_3 = "STR_DESCRIPTION_DIRECTORIES_3";

std::string STR_DESCRIPTION_BOXART_1 = "STR_DESCRIPTION_BOXART_1";
std::string STR_DESCRIPTION_BOXART_2 = "STR_DESCRIPTION_BOXART_2";

std::string STR_DESCRIPTION_ANIMATEDSIICONS_1 = "STR_DESCRIPTION_ANIMATEDSIICONS_1";
std::string STR_DESCRIPTION_ANIMATEDSIICONS_2 = "STR_DESCRIPTION_ANIMATEDSIICONS_2";
std::string STR_DESCRIPTION_ANIMATEDSIICONS_3 = "STR_DESCRIPTION_ANIMATEDSIICONS_3";

std::string STR_DESCRIPTION_STARTBUTTONLAUNCH_1 = "STR_DESCRIPTION_STARTBUTTONLAUNCH_1";
std::string STR_DESCRIPTION_STARTBUTTONLAUNCH_2 = "STR_DESCRIPTION_STARTBUTTONLAUNCH_2";
std::string STR_DESCRIPTION_STARTBUTTONLAUNCH_3 = "STR_DESCRIPTION_STARTBUTTONLAUNCH_3";

std::string STR_DESCRIPTION_SYSTEMSETTINGS_1 = "STR_DESCRIPTION_SYSTEMSETTINGS_1";
std::string STR_DESCRIPTION_SYSTEMSETTINGS_2 = "STR_DESCRIPTION_SYSTEMSETTINGS_2";

std::string STR_DESCRIPTION_REPLACEDSIMENU_1 = "STR_DESCRIPTION_REPLACEDSIMENU_1";
std::string STR_DESCRIPTION_REPLACEDSIMENU_2 = "STR_DESCRIPTION_REPLACEDSIMENU_2";

std::string STR_DESCRIPTION_RESTOREDSIMENU_1 = "STR_DESCRIPTION_RESTOREDSIMENU_1";

// Games/Apps settings
std::string STR_LANGUAGE = "STR_LANGUAGE";
std::string STR_CPUSPEED = "STR_CPUSPEED";
std::string STR_VRAMBOOST = "STR_VRAMBOOST";
std::string STR_SOUNDFIX = "STR_SOUNDFIX";
std::string STR_DEBUG = "STR_DEBUG";
std::string STR_LOGGING = "STR_LOGGING";
std::string STR_ROMREADLED = "STR_ROMREADLED";
std::string STR_ASYNCPREFETCH = "STR_ASYNCPREFETCH";
std::string STR_SNDFREQ = "STR_SNDFREQ";
std::string STR_SLOT1LAUNCHMETHOD = "STR_SLOT1LAUNCHMETHOD";
std::string STR_LOADINGSCREEN = "STR_LOADINGSCREEN";
std::string STR_BOOTSTRAP = "STR_BOOTSTRAP";
std::string STR_USEGBARUNNER2 = "STR_USEGBARUNNER2";

std::string STR_SYSTEM = "STR_SYSTEM";
std::string STR_ON = "STR_ON";
std::string STR_OFF = "STR_OFF";
std::string STR_YES = "STR_YES";
std::string STR_NO = "STR_NO";
std::string STR_NONE = "STR_NONE";
std::string STR_POWER = "STR_POWER";
std::string STR_CAMERA = "STR_CAMERA";
std::string STR_REBOOT = "STR_REBOOT";
std::string STR_DIRECT = "STR_DIRECT";
std::string STR_REGULAR = "STR_REGULAR";
std::string STR_RELEASE = "STR_RELEASE";
std::string STR_NIGHTLY = "STR_NIGHTLY";

std::string STR_DESCRIPTION_LANGUAGE_1 = "STR_DESCRIPTION_LANGUAGE_1";
std::string STR_DESCRIPTION_LANGUAGE_2 = "STR_DESCRIPTION_LANGUAGE_2";
std::string STR_DESCRIPTION_LANGUAGE_3 = "STR_DESCRIPTION_LANGUAGE_3";

std::string STR_DESCRIPTION_CPUSPEED_1 = "STR_DESCRIPTION_CPUSPEED_1";
std::string STR_DESCRIPTION_CPUSPEED_2 = "STR_DESCRIPTION_CPUSPEED_2";

std::string STR_DESCRIPTION_VRAMBOOST_1 = "STR_DESCRIPTION_VRAMBOOST_1";
std::string STR_DESCRIPTION_VRAMBOOST_2 = "STR_DESCRIPTION_VRAMBOOST_2";

std::string STR_DESCRIPTION_SOUNDFIX_1 = "STR_DESCRIPTION_SOUNDFIX_1";
std::string STR_DESCRIPTION_SOUNDFIX_2 = "STR_DESCRIPTION_SOUNDFIX_2";

std::string STR_DESCRIPTION_DEBUG_1 = "STR_DESCRIPTION_DEBUG_1";
std::string STR_DESCRIPTION_DEBUG_2 = "STR_DESCRIPTION_DEBUG_2";

std::string STR_DESCRIPTION_LOGGING_1 = "STR_DESCRIPTION_LOGGING_1";
std::string STR_DESCRIPTION_LOGGING_2 = "STR_DESCRIPTION_LOGGING_2";

std::string STR_DESCRIPTION_ROMREADLED_1 = "STR_DESCRIPTION_ROMREADLED_1";

std::string STR_DESCRIPTION_ASYNCPREFETCH_1 = "STR_DESCRIPTION_ASYNCPREFETCH_1";
std::string STR_DESCRIPTION_ASYNCPREFETCH_2 = "STR_DESCRIPTION_ASYNCPREFETCH_1";
std::string STR_DESCRIPTION_ASYNCPREFETCH_3 = "STR_DESCRIPTION_ASYNCPREFETCH_1";

std::string STR_DESCRIPTION_SNDFREQ_1 = "STR_DESCRIPTION_SNDFREQ_1";
std::string STR_DESCRIPTION_SNDFREQ_2 = "STR_DESCRIPTION_SNDFREQ_2";

std::string STR_DESCRIPTION_SLOT1LAUNCHMETHOD_1 = "STR_DESCRIPTION_SLOT1LAUNCHMETHOD_1";
std::string STR_DESCRIPTION_SLOT1LAUNCHMETHOD_2 = "STR_DESCRIPTION_SLOT1LAUNCHMETHOD_2";
std::string STR_DESCRIPTION_SLOT1LAUNCHMETHOD_3 = "STR_DESCRIPTION_SLOT1LAUNCHMETHOD_3";
std::string STR_DESCRIPTION_SLOT1LAUNCHMETHOD_4 = "STR_DESCRIPTION_SLOT1LAUNCHMETHOD_4";

std::string STR_DESCRIPTION_LOADINGSCREEN_1 = "STR_DESCRIPTION_LOADINGSCREEN_1";
std::string STR_DESCRIPTION_LOADINGSCREEN_2 = "STR_DESCRIPTION_LOADINGSCREEN_2";

std::string STR_DESCRIPTION_BOOTSTRAP_1 = "STR_DESCRIPTION_BOOTSTRAP_1";
std::string STR_DESCRIPTION_BOOTSTRAP_2 = "STR_DESCRIPTION_BOOTSTRAP_2";

std::string STR_DESCRIPTION_FLASHCARD_1 = "STR_DESCRIPTION_FLASHCARD_1";
std::string STR_DESCRIPTION_FLASHCARD_2 = "STR_DESCRIPTION_FLASHCARD_2";

std::string STR_DESCRIPTION_GBARUNNER2_1 = "STR_DESCRIPTION_GBARUNNER2_1";
std::string STR_DESCRIPTION_GBARUNNER2_2 = "STR_DESCRIPTION_GBARUNNER2_2";

// Flashcard settings
std::string STR_FLASHCARD_SELECT = "STR_FLASHCARD_SELECT";
std::string STR_LEFTRIGHT_FLASHCARD = "STR_LEFTRIGHT_FLASHCARD";
std::string STR_AB_SETRETURN = "STR_AB_SETRETURN";

// Sub-theme select
std::string STR_SUBTHEMESEL_DSI = "STR_SUBTHEMESEL_DSI";
std::string STR_SUBTHEMESEL_3DS = "STR_SUBTHEMESEL_3DS";
std::string STR_SUBTHEMESEL_R4 = "STR_SUBTHEMESEL_R4";
std::string STR_AB_SETSUBTHEME = "STR_AB_SETSUBTHEME";
std::string STR_DSI_DARKMENU = "STR_DSI_DARKMENU";
std::string STR_DSI_NORMALMENU = "STR_DSI_NORMALMENU";
std::string STR_DSI_RED = "STR_DSI_RED";
std::string STR_DSI_BLUE = "STR_DSI_BLUE";
std::string STR_DSI_GREEN = "STR_DSI_GREEN";
std::string STR_DSI_YELLOW = "STR_DSI_YELLOW";
std::string STR_DSI_PINK = "STR_DSI_PINK";
std::string STR_R4_THEME01 = "STR_R4_THEME01";
std::string STR_R4_THEME02 = "STR_R4_THEME02";
std::string STR_R4_THEME03 = "STR_R4_THEME03";
std::string STR_R4_THEME04 = "STR_R4_THEME04";
std::string STR_R4_THEME05 = "STR_R4_THEME05";
std::string STR_R4_THEME06 = "STR_R4_THEME06";
std::string STR_R4_THEME07 = "STR_R4_THEME07";
std::string STR_R4_THEME08 = "STR_R4_THEME08";
std::string STR_R4_THEME09 = "STR_R4_THEME09";
std::string STR_R4_THEME10 = "STR_R4_THEME10";
std::string STR_R4_THEME11 = "STR_R4_THEME11";
std::string STR_R4_THEME12 = "STR_R4_THEME12";
std::string STR_R4_THEME13 = "STR_R4_THEME13";


const char* languageIniPath;

extern int guiLanguage;
int setLanguage = 0;

/**
 * Initialize translations.
 * Uses the language ID specified in settings.ui.language.
 */
void langInit(void)
{
	if (guiLanguage == -1) {
		setLanguage = PersonalData->language;
	} else {
		setLanguage = guiLanguage;
	}

	switch (setLanguage) {
		case 0:
		default:
			languageIniPath = "nitro:/languages/japanese.ini";
			break;
		case 1:
			languageIniPath = "nitro:/languages/english.ini";
			break;
		case 2:
			languageIniPath = "nitro:/languages/french.ini";
			break;
		case 3:
			languageIniPath = "nitro:/languages/german.ini";
			break;
		case 4:
			languageIniPath = "nitro:/languages/italian.ini";
			break;
		case 5:
			languageIniPath = "nitro:/languages/spanish.ini";
			break;
	}

	CIniFile languageini( languageIniPath );

	STR_SAVING_SETTINGS = languageini.GetString("LANGUAGE", "SAVING_SETTINGS", "");
	STR_SETTINGS_SAVED = languageini.GetString("LANGUAGE", "SETTINGS_SAVED", "");

	STR_LR_SWITCH = languageini.GetString("LANGUAGE", "LR_SWITCH", "");
	STR_GUI_SETTINGS = languageini.GetString("LANGUAGE", "GUI_SETTINGS", "");
	STR_GAMESAPPS_SETTINGS = languageini.GetString("LANGUAGE", "GAMESAPPS_SETTINGS", "");

	// GUI settings
	STR_THEME = languageini.GetString("LANGUAGE", "THEME", "");
	STR_LASTPLAYEDROM = languageini.GetString("LANGUAGE", "LASTPLAYEDROM", "");
	switch (appName) {
		case 0:
		default:
			STR_DSIMENUPPLOGO = languageini.GetString("LANGUAGE", "DSIMENUPPLOGO", "");
			break;
		case 1:
			STR_DSIMENUPPLOGO = languageini.GetString("LANGUAGE", "SRLOADERLOGO", "");
			break;
		case 2:
			STR_DSIMENUPPLOGO = languageini.GetString("LANGUAGE", "DSISIONXLOGO", "");
			break;
	}
	STR_DIRECTORIES = languageini.GetString("LANGUAGE", "DIRECTORIES", "");
	STR_BOXART = languageini.GetString("LANGUAGE", "BOXART", "");
	STR_ANIMATEDSIICONS = languageini.GetString("LANGUAGE", "ANIMATEDSIICONS", "");
	STR_STARTBUTTONLAUNCH = languageini.GetString("LANGUAGE", "STARTBUTTONLAUNCH", "");
	STR_SYSTEMSETTINGS = languageini.GetString("LANGUAGE", "SYSTEMSETTINGS", "");
	STR_REPLACEDSIMENU = languageini.GetString("LANGUAGE", "REPLACEDSIMENU", "");
	STR_RESTOREDSIMENU = languageini.GetString("LANGUAGE", "RESTOREDSIMENU", "");

	STR_SHOW = languageini.GetString("LANGUAGE", "SHOW", "");
	STR_HIDE = languageini.GetString("LANGUAGE", "HIDE", "");

	switch (appName) {
		case 0:
		default:
			STR_DESCRIPTION_THEME_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_THEME_1", "");
			STR_DESCRIPTION_THEME_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_THEME_2", "");
			break;
		case 1:
			STR_DESCRIPTION_THEME_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_THEME_1_SRLOADER", "");
			STR_DESCRIPTION_THEME_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_THEME_2", "");
			break;
		case 2:
			STR_DESCRIPTION_THEME_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_THEME_1_DSISIONX", "");
			STR_DESCRIPTION_THEME_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_THEME_2", "");
			break;
	}

	STR_DESCRIPTION_LASTPLAYEDROM_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_LASTPLAYEDROM_1", "");
	STR_DESCRIPTION_LASTPLAYEDROM_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_LASTPLAYEDROM_2", "");
	STR_DESCRIPTION_LASTPLAYEDROM_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_LASTPLAYEDROM_3", "");
	STR_DESCRIPTION_LASTPLAYEDROM_4 = languageini.GetString("LANGUAGE", "DESCRIPTION_LASTPLAYEDROM_4", "");

	switch (appName) {
		case 0:
		default:
			STR_DESCRIPTION_DSIMENUPPLOGO_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_DSIMENUPPLOGO_1", "");
			STR_DESCRIPTION_DSIMENUPPLOGO_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_DSIMENUPPLOGO_2", "");
			STR_DESCRIPTION_DSIMENUPPLOGO_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_DSIMENUPPLOGO_3", "");
			break;
		case 1:
			STR_DESCRIPTION_DSIMENUPPLOGO_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_SRLOADERLOGO_1", "");
			STR_DESCRIPTION_DSIMENUPPLOGO_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_SRLOADERLOGO_2", "");
			STR_DESCRIPTION_DSIMENUPPLOGO_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_SRLOADERLOGO_3", "");
			break;
		case 2:
			STR_DESCRIPTION_DSIMENUPPLOGO_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_DSISIONXLOGO_1", "");
			STR_DESCRIPTION_DSIMENUPPLOGO_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_DSISIONXLOGO_2", "");
			STR_DESCRIPTION_DSIMENUPPLOGO_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_DSISIONXLOGO_3", "");
			break;
	}

	STR_DESCRIPTION_DIRECTORIES_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_DIRECTORIES_1", "");
	STR_DESCRIPTION_DIRECTORIES_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_DIRECTORIES_2", "");
	STR_DESCRIPTION_DIRECTORIES_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_DIRECTORIES_3", "");

	STR_DESCRIPTION_BOXART_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_BOXART_1", "");
	STR_DESCRIPTION_BOXART_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_BOXART_2", "");

	STR_DESCRIPTION_ANIMATEDSIICONS_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_ANIMATEDSIICONS_1", "");
	STR_DESCRIPTION_ANIMATEDSIICONS_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_ANIMATEDSIICONS_2", "");
	STR_DESCRIPTION_ANIMATEDSIICONS_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_ANIMATEDSIICONS_3", "");

	STR_DESCRIPTION_STARTBUTTONLAUNCH_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_STARTBUTTONLAUNCH_1", "");
	STR_DESCRIPTION_STARTBUTTONLAUNCH_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_STARTBUTTONLAUNCH_2", "");
	STR_DESCRIPTION_STARTBUTTONLAUNCH_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_STARTBUTTONLAUNCH_3", "");

	STR_DESCRIPTION_SYSTEMSETTINGS_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_SYSTEMSETTINGS_1", "");
	STR_DESCRIPTION_SYSTEMSETTINGS_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_SYSTEMSETTINGS_2", "");

	switch (appName) {
		case 0:
		default:
			STR_DESCRIPTION_REPLACEDSIMENU_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_REPLACEDSIMENU_1", "");
			STR_DESCRIPTION_REPLACEDSIMENU_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_REPLACEDSIMENU_2", "");
			break;
		case 1:
			STR_DESCRIPTION_REPLACEDSIMENU_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_REPLACEDSIMENU_1_SRLOADER", "");
			STR_DESCRIPTION_REPLACEDSIMENU_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_REPLACEDSIMENU_2", "");
			break;
		case 2:
			STR_DESCRIPTION_REPLACEDSIMENU_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_REPLACEDSIMENU_1_DSISIONX", "");
			STR_DESCRIPTION_REPLACEDSIMENU_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_REPLACEDSIMENU_2", "");
			break;
	}

	STR_DESCRIPTION_RESTOREDSIMENU_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_RESTOREDSIMENU_1", "");

	// Games/Apps settings
	STR_LANGUAGE = languageini.GetString("LANGUAGE", "LANGUAGE", "");
	STR_CPUSPEED = languageini.GetString("LANGUAGE", "CPUSPEED", "");
	STR_VRAMBOOST = languageini.GetString("LANGUAGE", "VRAMBOOST", "");
	STR_SOUNDFIX = languageini.GetString("LANGUAGE", "SOUNDFIX", "");
	STR_DEBUG = languageini.GetString("LANGUAGE", "DEBUG", "");
	STR_LOGGING = languageini.GetString("LANGUAGE", "LOGGING", "");
	STR_ROMREADLED = languageini.GetString("LANGUAGE", "ROMREADLED", "");
	STR_ASYNCPREFETCH = languageini.GetString("LANGUAGE", "ASYNCPREFETCH", "");
	STR_SNDFREQ = languageini.GetString("LANGUAGE", "SNDFREQ", "");
	STR_SLOT1LAUNCHMETHOD = languageini.GetString("LANGUAGE", "SLOT1LAUNCHMETHOD", "");
	STR_LOADINGSCREEN = languageini.GetString("LANGUAGE", "LOADINGSCREEN", "");
	STR_BOOTSTRAP = languageini.GetString("LANGUAGE", "BOOTSTRAP", "");
	STR_USEGBARUNNER2 = languageini.GetString("LANGUAGE", "USEGBARUNNER2", "");

	STR_SYSTEM = languageini.GetString("LANGUAGE", "SYSTEM", "");
	STR_ON = languageini.GetString("LANGUAGE", "ON", "");
	STR_OFF = languageini.GetString("LANGUAGE", "OFF", "");
	STR_YES = languageini.GetString("LANGUAGE", "YES", "");
	STR_NO = languageini.GetString("LANGUAGE", "NO", "");
	STR_NONE = languageini.GetString("LANGUAGE", "NONE", "");
	STR_POWER = languageini.GetString("LANGUAGE", "POWER", "");
	STR_CAMERA = languageini.GetString("LANGUAGE", "CAMERA", "");
	STR_REBOOT = languageini.GetString("LANGUAGE", "REBOOT", "");
	STR_DIRECT = languageini.GetString("LANGUAGE", "DIRECT", "");
	STR_REGULAR = languageini.GetString("LANGUAGE", "REGULAR", "");
	STR_RELEASE = languageini.GetString("LANGUAGE", "RELEASE", "");
	STR_NIGHTLY = languageini.GetString("LANGUAGE", "NIGHTLY", "");

	STR_DESCRIPTION_LANGUAGE_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_LANGUAGE_1", "");
	STR_DESCRIPTION_LANGUAGE_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_LANGUAGE_2", "");
	STR_DESCRIPTION_LANGUAGE_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_LANGUAGE_3", "");

	STR_DESCRIPTION_CPUSPEED_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_CPUSPEED_1", "");
	STR_DESCRIPTION_CPUSPEED_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_CPUSPEED_2", "");

	STR_DESCRIPTION_VRAMBOOST_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_VRAMBOOST_1", "");
	STR_DESCRIPTION_VRAMBOOST_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_VRAMBOOST_2", "");

	STR_DESCRIPTION_SOUNDFIX_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_SOUNDFIX_1", "");
	STR_DESCRIPTION_SOUNDFIX_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_SOUNDFIX_2", "");

	STR_DESCRIPTION_DEBUG_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_DEBUG_1", "");
	STR_DESCRIPTION_DEBUG_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_DEBUG_2", "");

	STR_DESCRIPTION_LOGGING_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_LOGGING_1", "");
	STR_DESCRIPTION_LOGGING_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_LOGGING_2", "");

	STR_DESCRIPTION_ROMREADLED_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_ROMREADLED_1", "");

	STR_DESCRIPTION_ASYNCPREFETCH_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_ASYNCPREFETCH_1", "");
	STR_DESCRIPTION_ASYNCPREFETCH_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_ASYNCPREFETCH_2", "");
	STR_DESCRIPTION_ASYNCPREFETCH_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_ASYNCPREFETCH_3", "");

	STR_DESCRIPTION_SNDFREQ_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_SNDFREQ_1", "");
	STR_DESCRIPTION_SNDFREQ_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_SNDFREQ_2", "");

	STR_DESCRIPTION_SLOT1LAUNCHMETHOD_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_SLOT1LAUNCHMETHOD_1", "");
	STR_DESCRIPTION_SLOT1LAUNCHMETHOD_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_SLOT1LAUNCHMETHOD_2", "");
	STR_DESCRIPTION_SLOT1LAUNCHMETHOD_3 = languageini.GetString("LANGUAGE", "DESCRIPTION_SLOT1LAUNCHMETHOD_3", "");
	STR_DESCRIPTION_SLOT1LAUNCHMETHOD_4 = languageini.GetString("LANGUAGE", "DESCRIPTION_SLOT1LAUNCHMETHOD_4", "");

	STR_DESCRIPTION_LOADINGSCREEN_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_LOADINGSCREEN_1", "");
	STR_DESCRIPTION_LOADINGSCREEN_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_LOADINGSCREEN_2", "");

	STR_DESCRIPTION_BOOTSTRAP_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_BOOTSTRAP_1", "");
	STR_DESCRIPTION_BOOTSTRAP_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_BOOTSTRAP_2", "");

	STR_DESCRIPTION_FLASHCARD_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_FLASHCARD_1", "");
	STR_DESCRIPTION_FLASHCARD_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_FLASHCARD_2", "");

	STR_DESCRIPTION_GBARUNNER2_1 = languageini.GetString("LANGUAGE", "DESCRIPTION_GBARUNNER2_1", "");
	STR_DESCRIPTION_GBARUNNER2_2 = languageini.GetString("LANGUAGE", "DESCRIPTION_GBARUNNER2_2", "");

	// Flashcard settings
	STR_FLASHCARD_SELECT = languageini.GetString("LANGUAGE", "FLASHCARD_SELECT", "");
	STR_LEFTRIGHT_FLASHCARD = languageini.GetString("LANGUAGE", "LEFTRIGHT_FLASHCARD", "");
	STR_AB_SETRETURN = languageini.GetString("LANGUAGE", "AB_SETRETURN", "");

	// Sub-theme select
	STR_SUBTHEMESEL_DSI = languageini.GetString("LANGUAGE", "SUBTHEMESEL_DSI", "");
	STR_SUBTHEMESEL_3DS = languageini.GetString("LANGUAGE", "SUBTHEMESEL_3DS", "");
	STR_SUBTHEMESEL_R4 = languageini.GetString("LANGUAGE", "SUBTHEMESEL_R4", "");
	STR_AB_SETSUBTHEME = languageini.GetString("LANGUAGE", "AB_SETSUBTHEME", "");
	STR_DSI_DARKMENU = languageini.GetString("LANGUAGE", "DSI_DARKMENU", "");
	STR_DSI_NORMALMENU = languageini.GetString("LANGUAGE", "DSI_NORMALMENU", "");
	STR_DSI_RED = languageini.GetString("LANGUAGE", "DSI_RED", "");
	STR_DSI_BLUE = languageini.GetString("LANGUAGE", "DSI_BLUE", "");
	STR_DSI_GREEN = languageini.GetString("LANGUAGE", "DSI_GREEN", "");
	STR_DSI_YELLOW = languageini.GetString("LANGUAGE", "DSI_YELLOW", "");
	STR_DSI_PINK = languageini.GetString("LANGUAGE", "DSI_PINK", "");
	STR_R4_THEME01 = languageini.GetString("LANGUAGE", "R4_THEME01", "");
	STR_R4_THEME02 = languageini.GetString("LANGUAGE", "R4_THEME02", "");
	STR_R4_THEME03 = languageini.GetString("LANGUAGE", "R4_THEME03", "");
	STR_R4_THEME04 = languageini.GetString("LANGUAGE", "R4_THEME04", "");
	STR_R4_THEME05 = languageini.GetString("LANGUAGE", "R4_THEME05", "");
	STR_R4_THEME06 = languageini.GetString("LANGUAGE", "R4_THEME06", "");
	STR_R4_THEME07 = languageini.GetString("LANGUAGE", "R4_THEME07", "");
	STR_R4_THEME08 = languageini.GetString("LANGUAGE", "R4_THEME08", "");
	STR_R4_THEME09 = languageini.GetString("LANGUAGE", "R4_THEME09", "");
	STR_R4_THEME10 = languageini.GetString("LANGUAGE", "R4_THEME10", "");
	STR_R4_THEME11 = languageini.GetString("LANGUAGE", "R4_THEME11", "");
	STR_R4_THEME12 = languageini.GetString("LANGUAGE", "R4_THEME12", "");
	STR_R4_THEME13 = languageini.GetString("LANGUAGE", "R4_THEME13", "");
}
