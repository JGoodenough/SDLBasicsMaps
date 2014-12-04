#ifndef CAREA_H_INCLUDED
#define CAREA_H_INCLUDED

#include "CMap.h"

class CArea {
    public:
        static CArea            AreaControl;

    public:
        std::vector<CMap>       MapList;

    private:
        int                     AreaSize;

        SDL_Surface*        Surf_Tileset;

    public:
        CArea();

        bool    OnLoad(char* File);

        void    OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);

        void    OnCleanup();
};

#endif // CAREA_H_INCLUDED
