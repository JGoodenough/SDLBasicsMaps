#include "CApp.h"

/*
Cleanup
This function simply cleans up any resources loaded, and insures a peaceful quitting of the game.
*/

void CApp::OnCleapup(){
    SDL_FreeSurface(Background_Surface);

    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnCleanup();
    }

    CEntity::EntityList.clear();

    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
