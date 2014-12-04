#include "CApp.h"

/*
Loop / Update
This function handles all the data updates, such as a NPCs moving across the screen, decreasing your health bar, or whatever
*/

void CApp::OnLoop(){
//    Anim_Yoshi.OnAnimate();

    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;
//        if(CEntity::EntityList[i] == &Entity2 && Entity2.X < 500 && CEntity::EntityList[i]->GetAnimationControl().GetOldTime() + CEntity::EntityList[i]->GetAnimationControl().GetFrameRate() > SDL_GetTicks()) {
//            Entity2.X += 1;
//        } else {
            CEntity::EntityList[i]->OnLoop();
//        }
    }
//    CEntity::EntityList[0]->OnLoop();
}
