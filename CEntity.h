#ifndef CENTITY_H_INCLUDED
#define CENTITY_H_INCLUDED

#include <vector>

#include "CAnimation.h"
#include "CSurface.h"

class CEntity {
    public:
        static std::vector<CEntity*>    EntityList;

    protected:
        CAnimation      Anim_Control;

        SDL_Surface*    Surf_Entity;

    public:
        float           X;
        float           Y;

        int             Width;
        int             Height;

        int             AnimState;

        bool framesHorizontal = false;

    public:
        CEntity();

        virtual ~CEntity();

    public:
        virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        virtual void OnLoop();

        virtual void OnRender(SDL_Surface* Surf_Display);

        virtual void OnCleanup();

        virtual void SetFrameRate(int frameRate);

        virtual void SetOscillate(bool osc);
};

#endif // CENTITY_H_INCLUDED
