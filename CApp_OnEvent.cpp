#include "CApp.h"

/*
Event (Input)
This function handles all input events from the mouse, keyboard, joysticks, or other devices.
*/

void CApp::OnEvent(SDL_Event* Event){
    CEvent::OnEvent(Event);
}

void CApp::OnExit() {
    running = false;
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym)
    {
        case SDLK_ESCAPE:
            OnExit();
            break;
//        case SDLK_r:
//            Reset();
//            break;
    }
}
