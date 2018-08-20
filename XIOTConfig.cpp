/**
*  Common config stuff for iotinator iotinator slave modules 
*  Xavier Grosjean 2018
*  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
*/

#include "XIOTConfig.h"

ModuleConfigClass::ModuleConfigClass(unsigned int version, const char* type, const char* name):XEEPROMConfigClass(version + CONFIG_BASE_VERSION, type, sizeof(ModuleConfigStruct)) {
  XUtils::safeStringCopy(_name, name, NAME_MAX_LENGTH);
  setName(name);
}

ModuleConfigClass::ModuleConfigClass(unsigned int version, const char* type, const char* name, unsigned int dataSize):XEEPROMConfigClass(version + CONFIG_BASE_VERSION, type, dataSize) {
  XUtils::safeStringCopy(_name, name, NAME_MAX_LENGTH);
  setName(name);
}

/**
* Reset the config data structure to the default values.
* This is done each time the data structure version is different from the one saved in EEPROM
* NB: version and name are handled by base class 
*/
void ModuleConfigClass::initFromDefault() {
  XEEPROMConfigClass::initFromDefault(); // handles version and name init 
  ModuleConfigStruct* configPtr = _getDataPtr();
  setName(_name);
  setSsid(DEFAULT_APSSID);
  setPwd(DEFAULT_APPWD);
  setUiClassName(getDefaultUIClassName());
  setBrightness(DEFAULT_BRIGHTNESS);
  setFlipScreen(DEFAULT_FLIP_SCREEN);
  setCanSleep(DEFAULT_CAN_SLEEP); 
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

void ModuleConfigClass::setSsid(const char* ssid) {
  XUtils::safeStringCopy(_getDataPtr()->ssid, ssid, SSID_MAX_LENGTH);
}

const char* ModuleConfigClass::getSsid() {
  return _getDataPtr()->ssid;
}

void ModuleConfigClass::setPwd(const char* pwd) {
  XUtils::safeStringCopy(_getDataPtr()->pwd, pwd, PWD_MAX_LENGTH);
}

const char* ModuleConfigClass::getPwd() {
  return _getDataPtr()->pwd;
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