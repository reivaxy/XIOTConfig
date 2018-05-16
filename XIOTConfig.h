/**
 *  Common config stuff for iotinator master and slave modules 
 *  Xavier Grosjean 2017
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once

#include <XEEPROMConfig.h>


// The default Access Point SSID and Password are known and used by slave modules
// to connect the first time.
// Master module needs to open this AP when connecting a new slave, before it returns to
// the customized SSID and PWD (after communicating them to newly connected slave)
// Should be in some common header file...
#define DEFAULT_APSSID "iotinator" 
#define DEFAULT_APPWD "iotinator"
#define DEFAULT_AP_EXPOSITION 60000

#define SSID_MAX_LENGTH 20
#define PWD_MAX_LENGTH 50
