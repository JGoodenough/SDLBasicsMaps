#include "CAnimation.h"
#include <iostream> // Added by JG for console output 1/8/13

using namespace std;
CAnimation::CAnimation() {
    CurrentFrame = 0;
    MaxFrames = 0;
    FrameInc = 1;

    FrameRate = 1000; //Milliseconds
    OldTime = 0;

    Oscillate = false;
}

void CAnimation::OnAnimate() {
    if(OldTime + FrameRate > SDL_GetTicks()) {
        //cout << "old time" << OldTime + FrameRate << " >> latest" << SDL_GetTicks() << endl;
        return;
    }

    OldTime = SDL_GetTicks();
    //cout << OldTime << endl;

    CurrentFrame += FrameInc;
//    if(MaxFrames == 8)
//        cout << CurrentFrame << endl;
    if(Oscillate) {
        if(FrameInc > 0) {
            if(CurrentFrame > MaxFrames-1) {
                FrameInc = -FrameInc;
                //CurrentFrame = 0;
            }
        } else {
            if(CurrentFrame < 0) {
                FrameInc = -FrameInc;
            }
        }
    } else { //No oscillation just resets back to frame 0 and runs through frames again
        if(CurrentFrame > MaxFrames-1) {
            CurrentFrame = 0;
        }
    }
}

void CAnimation::SetFrameRate(int Rate){
    FrameRate = Rate;
}

int CAnimation::GetFrameRate() {
    return FrameRate;
}

void CAnimation::SetCurrentFrame(int Frame) {
    if(Frame < 0 || Frame >= MaxFrames) return;

    CurrentFrame = Frame;
}

int CAnimation::GetCurrentFrame() {
    return CurrentFrame;
}

long CAnimation::GetOldTime() {
    return OldTime;
}
