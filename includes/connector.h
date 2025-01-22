#ifndef TYPE_CONNECTOR_DEFINITIONS
#define TYPE_CONNECTOR_DEFINITIONS

#include <enumerations.h>

#include <map>
#include <bitset>
#include <string>

extern std::map<E_Item, std::bitset<4>> item_cardinal_connector;
extern std::map<E_Item, std::string> character_connector;

#endif