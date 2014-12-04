#include "CApp.h"

/*
Render
This function handles all the rendering of anything that shows up on the screen. It does NOT handle data manipulation, as this is what the Loop function is supposed to handle.
*/

void CApp::OnRender(){
//CSurface::OnDraw(Surf_Display, Background_Surface, 0, 0);
//    CSurface::OnDraw(Surf_Display, Surf_Test, 100, 100, 0, 0, 20, 10);

//    CSurface::OnDraw(Surf_Display, Surf_Test, 290, 220, 0, Anim_Yoshi.GetCurrentFrame() * 64, 64, 64);

    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
//        CEntity::EntityList[1]->OnRender(Surf_Display);
        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
//
//    CEntity::EntityList[0]->OnRender(Surf_Display);

    SDL_Flip(Surf_Display);
}
