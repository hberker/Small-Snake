#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <stdio.h>
#include <vector>
#include <iostream>

typedef int i;
typedef double d;

using namespace std;
struct snake
{
    snake(i a) : W(a){}
    i W;
    SDL_Rect rc = {25,25,10,10};
    vector<vector<i>> b={{25,25}};
       
    i move(i dir[2], i SH, i SW, bool a)
    {
        if (a) b.push_back({0,0});
        for (i e = b.size() - 1; e > 0; e--)b.at(e) = b.at(e - 1);
        if (b.at(0).at(0) + dir[0] > 5 && b.at(0).at(0) + dir[0] < SH - W) b.at(0).at(0) += dir[0];
        if (b.at(0).at(1) + dir[1] > 5 && b.at(0).at(1) + dir[1] < SW - W) b.at(0).at(1) += dir[1];
    }
    bool die()
    {
        for(i e = 0; e < b.size();e++)
        {
            for(i a = 0; a < b.size();a++)
            {
                if(a!=e&&b.at(e).at(0)==b.at(a).at(0)&&b.at(e).at(1)==b.at(a).at(1)) return false;
            }
        }
        return true;
    }
    bool didEat(i x, i y)
    {
        for(i e = 0; e < b.size();e++)
        {
            if(b.at(e).at(0) == x && b.at(e).at(1) == y) return true;
        }
        return false;
    }
    i rend(SDL_Renderer *rend)
    {
        SDL_SetRenderDrawColor(rend, 0xFF, 0x00, 0xFF, 0xFF);
        for(i e = 0; e < b.size(); e++)
        {
            rc.x = b.at(e).at(0), rc.y = b.at(e).at(1);
            SDL_SetRenderDrawColor(rend, 0xFF, 0x00, 0xFF, 0xFF);
            SDL_RenderFillRect(rend,&rc);
        }
    }
}; 

int main(int argc, char* argv[])
{

    i s = 10;
    bool a = true;
    bool eat = false;
    i SW = 480, SH = 640;
    i Dir[2] = {0,0};

    SDL_Window *wind;
    SDL_Renderer *rend;
    SDL_Rect f = {465,465,10,10};

    snake sn = snake(++s);

    wind=SDL_CreateWindow("S",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SH,SW,SDL_WINDOW_OPENGL);
    rend=SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED );
    while(a)
    {
        if(eat)f.x =  25 + (11 * (rand()%(54 + 1))), f.y = 25 + (11 * (rand()%(40 + 1))),eat = false;

        SDL_Event e;
        while( SDL_PollEvent(&e)!= 0) 
        { 
            if(e.type==SDL_QUIT)a=!a;  
            if(e.type==SDL_KEYDOWN) 
            { 
                switch(e.key.keysym.sym) 
                { 
                    case SDLK_UP: Dir[0]=0,Dir[1]=-s;break; 
                    case SDLK_DOWN:Dir[0]=0,Dir[1]=s;break; 
                    case SDLK_LEFT:Dir[0]=-s,Dir[1]=0;break; 
                    case SDLK_RIGHT:Dir[0]=s,Dir[1]=0;break; 
                    default:Dir[0]=0,Dir[1]=0;break; 
                } 
            } 
        }
        SDL_SetRenderDrawColor(rend, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderClear(rend);
        eat = sn.didEat(f.x,f.y);
        sn.move(Dir, SH, SW, eat);
        sn.rend(rend);
        SDL_RenderFillRect(rend,&f);
        SDL_RenderPresent(rend);
        SDL_Delay(40);
        a=sn.die();
    }
    SDL_Quit();
    return 0;
}