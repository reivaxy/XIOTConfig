/**
 *  base class for all iotinator agent and master modules
*  Xavier Grosjean 2021
*  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
*/
 
#pragma once

#include <XUtils.h>
#include <XEEPROMConfig.h>


// Increment this when default config changes.
// This gets added to each module version
#define CONFIG_BASE_VERSION 2

// The default Master Access Point SSID and Password are known and used by agent modules
// to connect the first time (non autonomous module) or to expose an access point (autonomous module)
// Master module exposes this AP during a short time after reset, before it returns to
// the customized SSID and PWD, after communicating them to newly connected non autonomous agent
// Newly connected agent then switches to customized SSID and PWD and saves them in config so
// that it can reconnect at next boot.
#define DEFAULT_XIOT_APSSID "iotinator" 
#define DEFAULT_XIOT_APPWD "iotinator"

#define DEFAULT_AP_EXPOSITION 25000

#define DEFAULT_BOX_APSSID "" 
#define DEFAULT_BOX_APPWD ""

#define DEFAULT_FLIP_SCREEN true
#define DEFAULT_BRIGHTNESS 200
#define DEFAULT_CAN_SLEEP false

#define DEFAULT_IS_AUTONOMOUS true

#define NAME_MAX_LENGTH 20
#define IP_MAX_LENGTH 15

#define SSID_MAX_LENGTH 20
#define PWD_MAX_LENGTH 50
#define UI_CLASS_NAME_MAX_LENGTH 30

#define HOSTNAME_MAX_LENGTH 50
#define API_KEY_MAX_LENGTH 40
#define DEFAULT_WEBSITE "http://www.iotinator.com/"
#define DEFAULT_NTP_SERVER "time.google.com"
#define DEFAULT_GMT_HOUR_OFFSSET 2
#define DEFAULT_GMT_MIN_OFFSSET 0

// Common config structure all modules must use
// First 2 members (version number and type) are inherited from XEEPROMConfigDataStruct   
struct ModuleConfigStruct:XEEPROMConfigDataStruct {
  char name[NAME_MAX_LENGTH + 1];
  char xiotSsid[SSID_MAX_LENGTH + 1];
  char xiotPwd[PWD_MAX_LENGTH + 1];
  char boxSsid[SSID_MAX_LENGTH + 1];
  char boxPwd[PWD_MAX_LENGTH + 1];

  // Name of the User Interface class to use to handle this module.
  char uiClassName[UI_CLASS_NAME_MAX_LENGTH + 1];
  // This module is allowed to use the sleep feature
  // Warning make sure the hardware can wake it :)
  bool canSleep = DEFAULT_CAN_SLEEP;
  long pingPeriod = 30; // 30 seconds by default
  bool flipScreen = DEFAULT_FLIP_SCREEN;
  uint8_t brightness = DEFAULT_BRIGHTNESS;
  // This module is autonomous: it will not be used with a master
  // it will expose a configuration page on its agent wifi AP
  // to allow configuring the wifi it should connect to to access internet
  // as well as custom module configuration
  bool isAutonomous = DEFAULT_IS_AUTONOMOUS;

  // Hostname for webapps, statistics, etc
  char webSite[HOSTNAME_MAX_LENGTH + 1];
  
  // API KEY from website registration, it's a uuid, 36 char
  char apiKey[API_KEY_MAX_LENGTH + 1];
    
  // ntp server
  char ntpHostName[HOSTNAME_MAX_LENGTH + 1];
  int8_t gmtHourOffset = DEFAULT_GMT_HOUR_OFFSSET;
  int8_t gmtMinOffset = DEFAULT_GMT_MIN_OFFSSET;
   
};

class ModuleConfigClass:public XEEPROMConfigClass {
public:
  ModuleConfigClass(unsigned int version, const char* type, const char* name);
  ModuleConfigClass(unsigned int version, const char* type, const char* name, unsigned int dataSize);
  virtual void initFromDefault();
  const char* getName(void);
  void setName(const char*);  
  void setXiotSsid(const char* ssid);
  void setXiotPwd(const char* pwd); 
  void setBoxSsid(const char* ssid);
  void setBoxPwd(const char* pwd);
  void setUiClassName(const char* uiClassName);
  const char* getUiClassName(void);
  void setCanSleep(bool flag);
  bool getCanSleep(void);
  const char* getXiotSsid(void);
  const char* getXiotPwd(void);
  const char* getBoxSsid(void);
  const char* getBoxPwd(void);
  virtual const char* getDefaultUIClassName(void);
  void setBrightness(uint8_t);
  uint8_t getBrightness();
  bool getFlipScreen();
  void setFlipScreen(bool);

  void setIsAutonomous(bool);
  bool getIsAutonomous();

  void setWebSite(const char* webSite);
  void setApiKey(const char* apiKey);
  void setNtpServer(const char* ntpServer);
  void setGmtOffset(int8_t hour, int8_t min); 
  
  const char* getWebSite(void);
  const char* getApiKey(void);
  const char* getNtpServer(void);
  int8_t getGmtHourOffset(); 
  int8_t getGmtMinOffset();

  bool isHomeWifiConfigured(void);
  bool isAPInitialized(void);

protected:
  ModuleConfigStruct* _getDataPtr(void);  
  char _name[NAME_MAX_LENGTH + 1];  // to be able to restore default name
};