/**
*  base class for all iotinator agent and master modules
*  Xavier Grosjean 2021
*  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
*/

#include "XIOTConfig.h"

ModuleConfigClass::ModuleConfigClass(unsigned int version, const char* type, const char* name):XEEPROMConfigClass(version + CONFIG_BASE_VERSION, type, sizeof(ModuleConfigStruct)) {
  XUtils::safeStringCopy(_name, name, NAME_MAX_LENGTH);
  setName(_name);
}

ModuleConfigClass::ModuleConfigClass(unsigned int version, const char* type, const char* name, unsigned int dataSize):XEEPROMConfigClass(version + CONFIG_BASE_VERSION, type, dataSize) {
  XUtils::safeStringCopy(_name, name, NAME_MAX_LENGTH);
  setName(_name);
}

/**
* Reset the config data structure to the default values.
* This is done each time the data structure version is different from the one saved in EEPROM
* NB: version and name are handled by base class 
*/
void ModuleConfigClass::initFromDefault() {
  XEEPROMConfigClass::initFromDefault(); // handles version and name init 
  setName(_name);
  setXiotSsid(DEFAULT_XIOT_APSSID);
  setXiotPwd(DEFAULT_XIOT_APPWD);
  setBoxSsid(DEFAULT_BOX_APSSID);
  setBoxPwd(DEFAULT_BOX_APPWD);
  setUiClassName(getDefaultUIClassName());
  setBrightness(DEFAULT_BRIGHTNESS);
  setFlipScreen(DEFAULT_FLIP_SCREEN);
  setCanSleep(DEFAULT_CAN_SLEEP); 
  setIsAutonomous(DEFAULT_IS_AUTONOMOUS);

  setWebSite(DEFAULT_WEBSITE);
  setApiKey("");
  setNtpServer(DEFAULT_NTP_SERVER);

  setGmtOffset(DEFAULT_GMT_HOUR_OFFSSET, DEFAULT_GMT_MIN_OFFSSET);
}

/**
* Set the name in the data structure
*
*/
void ModuleConfigClass::setName(const char* name) {
  XUtils::safeStringCopy(_getDataPtr()->name, name, NAME_MAX_LENGTH);
}

/**
* Get the name from the data structure
*
*/
const char* ModuleConfigClass::getName(void) {
  return _getDataPtr()->name;
}

void ModuleConfigClass::setUiClassName(const char* uiClassName) {
  XUtils::safeStringCopy(_getDataPtr()->uiClassName, uiClassName, UI_CLASS_NAME_MAX_LENGTH);
}

const char* ModuleConfigClass::getUiClassName(void) {
  return _getDataPtr()->uiClassName;
}

void ModuleConfigClass::setCanSleep(bool canSleep) {
  _getDataPtr()->canSleep = canSleep;
}

bool ModuleConfigClass::getCanSleep(void) {
  return _getDataPtr()->canSleep;
}

void ModuleConfigClass::setXiotSsid(const char* ssid) {
  XUtils::safeStringCopy(_getDataPtr()->xiotSsid, ssid, SSID_MAX_LENGTH);
}

const char* ModuleConfigClass::getXiotSsid() {
  return _getDataPtr()->xiotSsid;
}

void ModuleConfigClass::setBoxSsid(const char* ssid) {
  XUtils::safeStringCopy(_getDataPtr()->boxSsid, ssid, SSID_MAX_LENGTH);
}

const char* ModuleConfigClass::getBoxSsid() {
  return _getDataPtr()->boxSsid;
}

void ModuleConfigClass::setXiotPwd(const char* pwd) {
  XUtils::safeStringCopy(_getDataPtr()->xiotPwd, pwd, PWD_MAX_LENGTH);
}

const char* ModuleConfigClass::getXiotPwd() {
  return _getDataPtr()->xiotPwd;
}

void ModuleConfigClass::setBoxPwd(const char* pwd) {
  XUtils::safeStringCopy(_getDataPtr()->boxPwd, pwd, PWD_MAX_LENGTH);
}

const char* ModuleConfigClass::getBoxPwd() {
  return _getDataPtr()->boxPwd;
}

// This method should be overriden by modules to provide their default uiClassName
const char* ModuleConfigClass::getDefaultUIClassName() {
  return "";
}
/**
* Return the typed data structure object
*
*/
ModuleConfigStruct* ModuleConfigClass::_getDataPtr(void) {
  return (ModuleConfigStruct*)XEEPROMConfigClass::_getDataPtr();
}

void ModuleConfigClass::setBrightness(uint8_t level) {
  _getDataPtr()->brightness = level; 
}

uint8_t ModuleConfigClass::getBrightness() {
  return(_getDataPtr()->brightness);
}

bool ModuleConfigClass::getFlipScreen() {
  return(_getDataPtr()->flipScreen);
}

void ModuleConfigClass::setFlipScreen(bool flip) {
  _getDataPtr()->flipScreen = flip;
}

bool ModuleConfigClass::getIsAutonomous() {
  return(_getDataPtr()->isAutonomous);
}

void ModuleConfigClass::setIsAutonomous(bool autonomous) {
  _getDataPtr()->isAutonomous = autonomous;
}

void ModuleConfigClass::setWebSite(const char* webSite) {
  XUtils::safeStringCopy(_getDataPtr()->webSite, webSite, HOSTNAME_MAX_LENGTH);
}
void ModuleConfigClass::setApiKey(const char* apiKey) {
  XUtils::safeStringCopy(_getDataPtr()->apiKey, apiKey, API_KEY_MAX_LENGTH);
}
void ModuleConfigClass::setNtpServer(const char* ntpHostName) {
  XUtils::safeStringCopy(_getDataPtr()->ntpHostName, ntpHostName, HOSTNAME_MAX_LENGTH);
}
const char* ModuleConfigClass::getNtpServer() {
  return _getDataPtr()->ntpHostName;
}
void ModuleConfigClass::setGmtOffset(int8_t hourOffset, int8_t minOffset) {
  _getDataPtr()->gmtHourOffset = hourOffset;
  _getDataPtr()->gmtMinOffset = hourOffset;
}
int8_t ModuleConfigClass::getGmtHourOffset() {
  return _getDataPtr()->gmtHourOffset;
} 
int8_t ModuleConfigClass::getGmtMinOffset() {
  return _getDataPtr()->gmtMinOffset;
}