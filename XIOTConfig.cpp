/**
 *  Common config stuff for iotinator iotinator slave modules 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
 #include "XIOTConfig.h"
  
 ModuleConfigClass::ModuleConfigClass(unsigned int version, const char* name):XEEPROMConfigClass(version, name, sizeof(ModuleConfigStruct)) {
 }
  
 ModuleConfigClass::ModuleConfigClass(unsigned int version, const char* name, unsigned int dataSize):XEEPROMConfigClass(version, name, dataSize) {
 }
 
 /**
  * Reset the config data structure to the default values.
  * This is done each time the data structure version is different from the one saved in EEPROM
  * NB: version and name are handled by base class 
  */
 void ModuleConfigClass::initFromDefault() {
   XEEPROMConfigClass::initFromDefault(); // handles version and name init 
   ModuleConfigStruct* configPtr = _getDataPtr();
   setSsid(DEFAULT_APSSID);
   setPwd(DEFAULT_APPWD);
 
 }
 
 void ModuleConfigClass::setSsid(const char* ssid) {
   XUtils::safeStringCopy(_getDataPtr()->ssid, ssid, SSID_MAX_LENGTH);
 }
 
 void ModuleConfigClass::setPwd(const char* pwd) {
   XUtils::safeStringCopy(_getDataPtr()->pwd, pwd, PWD_MAX_LENGTH);
 }
 
 const char* ModuleConfigClass::getSsid() {
   return _getDataPtr()->ssid;
 }
 
 const char* ModuleConfigClass::getPwd() {
   return _getDataPtr()->pwd;
 }
 
 /**
  * Return the typed data structure object
  *
  */
 ModuleConfigStruct* ModuleConfigClass::_getDataPtr(void) {
   return (ModuleConfigStruct*)XEEPROMConfigClass::_getDataPtr();
 }