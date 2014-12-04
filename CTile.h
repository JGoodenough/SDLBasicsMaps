#ifndef CTILE_H_INCLUDED
#define CTILE_H_INCLUDED

#include "Define.h"

enum {
    TILE_TYPE_NONE = 0,

    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};

class CTile {
    public:
        int     TileID;
        int     TypeID;

    public:
        CTile();
};

#endif // CTILE_H_INCLUDED
