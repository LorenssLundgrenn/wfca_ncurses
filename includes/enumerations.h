#ifndef ITEM_ENUMERATION_DEFINITIONS
#define ITEM_ENUMERATION_DEFINITIONS

enum E_Item {
    H_BAR,
    V_BAR,
    TLF_CRN,
    TRG_CRN,
    BLF_CRN,
    BRG_CRN,
    JUNCT,
    
    N_ITEMS
};

enum E_Cardinal {
    NORTH = 0b1000,
    SOUTH = 0b0100,
    WEST = 0b0010,
    EAST = 0b0001
};

#endif