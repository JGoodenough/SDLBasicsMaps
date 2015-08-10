#include "CApp.h"
#include <iostream> // Added by JG for console output 1/8/13

using namespace std; // Added by JG for console output 1/8/13

//Constructor for CApp class to initialize members
CApp::CApp(){
    Surf_Display = NULL;
    Background_Surface = NULL;

    running = true;
}

int CApp::OnExecute(){
    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;
    // main game loop
    while(running){
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleapup();


    return 0;
}


//Starting point of program
int main(int argc, char* argv[]){
    CApp theApp;

    // START DISPLAY SDL VERSION
    SDL_version compiled;
    SDL_VERSION(&compiled);
    printf("We compiled against SDL version %d.%d.%d ...\n",
           compiled.major, compiled.minor, compiled.patch);
    // END DISPLAY SDL VERSION

    return theApp.OnExecute();
}
