#include "CMap.h"

CMap::CMap() {
    Surf_Tileset = NULL;
}

bool CMap::OnLoad(char* File) {
    TileList.clear();

    FILE* FileHandle = fopen(File, "r");

    if(FileHandle == NULL) {
        return false;
    }

    for(int Y = 0;Y < MAP_HEIGHT;Y++) {
        for(int X = 0;X < MAP_WIDTH;X++) {
            CTile tempTile;

            fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);

            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    return true;
}

void CMap::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY) {
    if(Surf_Tileset == NULL) return;

    //determine how many tiles wide and how many high  in this example it is 1X2 (1 tile high x 2 tiles wide)
    int TilesetWidth  = Surf_Tileset->w / TILE_SIZE;
    int TilesetHeight = Surf_Tileset->h / TILE_SIZE;

    int ID = 0;

    for(int Y = 0;Y < MAP_HEIGHT;Y++) {
        for(int X = 0;X < MAP_WIDTH;X++) {
            if(TileList[ID].TypeID == TILE_TYPE_NONE) {
                ID++;
                continue;
            }
            //tile location with map (map is 40x40 tiles)
            int tX = MapX + (X * TILE_SIZE);
            int tY = MapY + (Y * TILE_SIZE);
            //grab appropriate tile from tile set
            int TilesetX = (TileList[ID].TileID % TilesetWidth) * TILE_SIZE; // column
            int TilesetY = (TileList[ID].TileID / TilesetWidth) * TILE_SIZE; // row

            CSurface::OnDraw(Surf_Display, Surf_Tileset, tX, tY, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);

            ID++;
        }
    }
}
