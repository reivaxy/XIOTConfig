/**
 *  Common config stuff for iotinator iotinator master and slave modules 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once

#include <XUtils.h>
#include <XEEPROMConfig.h>


// Increment this when default config changes.
// This gets added to each module version
#define CONFIG_BASE_VERSION 1

// The default Access Point SSID and Password are known and used by slave modules
// to connect the first time.
// Master module needs to open this AP when connecting a new slave, before it returns to
// the customized SSID and PWD (after communicating them to newly connected slave)
// Should be in some common header file...
#define DEFAULT_APSSID "iotinator" 
#define DEFAULT_APPWD "iotinator"

#define DEFAULT_AP_EXPOSITION 25000

#define DEFAULT_FLIP_SCREEN true
#define DEFAULT_BRIGHTNESS 200
#define DEFAULT_CAN_SLEEP false


#define NAME_MAX_LENGTH 20

#define SSID_MAX_LENGTH 20
#define PWD_MAX_LENGTH 50
#define UI_CLASS_NAME_MAX_LENGTH 30

// Common config structure all modules should use
struct ModuleConfigStruct:XEEPROMConfigDataStruct {
  // First member (version number) is inherited from XEEPROMConfigDataStruct   
  char name[NAME_MAX_LENGTH + 1];
  char ssid[SSID_MAX_LENGTH + 1];
  char pwd[PWD_MAX_LENGTH + 1];
  // Name of the User Interface class to use to handle this module.
  char uiClassName[UI_CLASS_NAME_MAX_LENGTH + 1];
  // This module is allowed to use the sleep feature
  // Warning make sure the hardware can wake it :)
  bool canSleep = DEFAULT_CAN_SLEEP;
  long pingPeriod = 30; // 30 seconds by default
  bool flipScreen = DEFAULT_FLIP_SCREEN;
  uint8_t brightness = DEFAULT_BRIGHTNESS;
   
};

class ModuleConfigClass:public XEEPROMConfigClass {
public:
  ModuleConfigClass(unsigned int version, const char* type, const char* name);
  ModuleConfigClass(unsigned int version, const char* type, const char* name, unsigned int dataSize);
  virtual void initFromDefault();
  const char* getName(void);
  void setName(const char*);  
  void setSsid(const char* ssid);
  void setPwd(const char* pwd);
  void setUiClassName(const char* uiClassName);
  const char* getUiClassName(void);
  void setCanSleep(bool flag);
  bool getCanSleep(void);
  const char* getSsid(void);
  const char* getPwd(void);
  virtual const char* getDefaultUIClassName(void);
  void setBrightness(uint8_t);
  uint8_t getBrightness();
  bool getFlipScreen();
  void setFlipScreen(bool);
protected:
  ModuleConfigStruct* _getDataPtr(void);  
  char _name[NAME_MAX_LENGTH + 1];  // to be able to restore default name
};