#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL/SDL.h>
#include "Define.h"
#include "CAnimation.h"
#include "CEntity.h"

#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent {
    private:
        bool running;

        SDL_Surface* Surf_Display;

        SDL_Surface* Background_Surface;

//        CAnimation Anim_Yoshi;

    private:
        CEntity BackgroundEntity;
        CEntity Entity1;
        CEntity BBB;
//        CEntity         Entity2;
//        CEntity EntityFull;

    public:
        CApp(); //constructor
        int OnExecute();

    public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnExit();
        void OnLoop();
        void OnRender();
        void OnCleapup();
        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

};

#endif
