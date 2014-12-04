
#ifndef CANIMATION_H_INCLUDED
#define CANIMATION_H_INCLUDED

#include <SDL/SDL.h>

class CAnimation {
    // data
    private:
        int CurrentFrame;
        int FrameInc;
        int FrameRate; //Milliseconds
        long OldTime;

    public:
        int MaxFrames;
        bool Oscillate;

    //functions
    public:
        CAnimation();
        void OnAnimate();
        void SetFrameRate(int Rate);
        int GetFrameRate();
        void SetCurrentFrame(int Frame);
        int GetCurrentFrame();
        long GetOldTime();
};

#endif
