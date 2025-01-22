#include <connector.h>
#include <enumerations.h>

std::map<E_Item, std::bitset<4>> item_connector {
    { H_BAR, 0b0011 },
    { V_BAR, 0b1100 },
    { TLF_CRN, 0b0101 },
    { TRG_CRN, 0b0110 },
    { BLF_CRN, 0b1001 },
    { BRG_CRN, 0b1010 },
    { JUNCT, 0b1111 },
    { EMPTY, 0b1111 }
};

std::map<E_Item, std::string> character_connector {
    { H_BAR, "═" },
    { V_BAR, "║" },
    { TLF_CRN, "╔" },
    { TRG_CRN, "╗" },
    { BLF_CRN, "╚" },
    { BRG_CRN, "╝" },
    { JUNCT, "╬" },
    { EMPTY, " " }
};