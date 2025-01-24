#include "connector.h"
#include "enumerations.h"

std::map<E_Item, int> cardinal_connector {
    { H_BAR, EAST | WEST },
    { V_BAR, NORTH | SOUTH },
    { TLF_CRN, SOUTH | EAST },
    { TRG_CRN, SOUTH | WEST },
    { BLF_CRN, NORTH | EAST },
    { BRG_CRN, NORTH | WEST },
    { JUNCT, NORTH | SOUTH | WEST | EAST }
};

std::map<E_Item, wchar_t> character_connector {
    { H_BAR, L'─' },
    { V_BAR, L'│' },
    { TLF_CRN, L'┌' },
    { TRG_CRN, L'┐' },
    { BLF_CRN, L'└' },
    { BRG_CRN, L'┘' },
    { JUNCT, L'┼' }
};