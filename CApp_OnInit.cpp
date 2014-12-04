#include "CApp.h"

/*
Initialize (Init)
This function handles all the loading of data, whether it be textures, maps, NPCs, or whatever.
*/

bool CApp::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    // old reso: 1024 w X 768 h
    //Initialize Main Window for Game
    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
        return false;
    }

    // set window Title
    SDL_WM_SetCaption("Map Test", "Map Test Icon Name");
    //Initialize Test graphic
//    if((Surf_Test = CSurface::OnLoad("./gfx/yoshi.bmp")) == NULL) {
//        return false;
//    }
    if((Background_Surface = CSurface::OnLoad("./gfx/backgroundwhite.bmp")) == NULL) {
        return false;
    }

    if(BackgroundEntity.OnLoad("./gfx/backgroundblue.bmp", 1024, 768, 1) == false) {
        return false;
    }

    if(Entity1.OnLoad("./gfx/yoshi.png", 64, 64, 8) == false) {
        return false;
    }

    if(BBB.OnLoad("./gfx/maincharacter2.png", 32, 32, 6) == false) {
        return false;
    }

//    if(Entity2.OnLoad("./gfx/yoshi2.bmp", 64, 64, 8) == false) {
//        return false;
//    }

//    if(EntityFull.OnLoad("./gfx/yoshi.bmp", 64, 512, 8) == false) {
//        return false;
//    }
//
//    Entity2.X = 100;
//
//    EntityFull.X = 200;

    Entity1.SetFrameRate(100);

    BBB.X = 100;

    BBB.SetFrameRate(100);
    BBB.framesHorizontal = true;
//    BBB.SetOscillate(true);

    CEntity::EntityList.push_back(&BackgroundEntity); // MUST put this on the vector first to repaint background before updating foreground animations
    CEntity::EntityList.push_back(&Entity1);
    CEntity::EntityList.push_back(&BBB);
//    CEntity::EntityList.push_back(&Entity2);
//    CEntity::EntityList.push_back(&EntityFull);

    //CSurface::Transparent(Surf_Test, 255, 0, 255);

//    Anim_Yoshi.MaxFrames = 8;
//    Anim_Yoshi.Oscillate = true;
//    Anim_Yoshi.SetFrameRate(100);

    return true;
}
