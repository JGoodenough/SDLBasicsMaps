#include "CEntity.h"
#include <iostream>
using namespace std;

std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity() {
    Surf_Entity = NULL;

    X = Y = 0.0f;

    Width = Height = 0;

    AnimState = 0;
}

CEntity::~CEntity() {
}

bool CEntity::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
        return false;
    }

    //CSurface::Transparent(Surf_Entity, 255, 0, 255);
    CSurface::Transparent(Surf_Entity, 0, 0, 0);

    this->Width = Width;
    this->Height = Height;

    Anim_Control.MaxFrames = MaxFrames;
    //Anim_Control.SetFrameRate(1500);

    return true;
}

void CEntity::OnLoop() {
    Anim_Control.OnAnimate();
}

void CEntity::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    if(framesHorizontal == false)
        CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, AnimState * Width, Anim_Control.GetCurrentFrame() * Height, Width, Height);
    else
        CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, Anim_Control.GetCurrentFrame() * Width, AnimState * Height, Width, Height);
}

void CEntity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}

void CEntity::SetFrameRate(int frameRate) {
    Anim_Control.SetFrameRate(frameRate);
}

void CEntity::SetOscillate(bool osc) {
    Anim_Control.Oscillate = osc;
}
