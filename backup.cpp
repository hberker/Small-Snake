#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
typedef int i;

struct s{
    s(i a):W(a){}
    i W;
    SDL_Rect r={25,25,10,10};
    std::vector<std::vector<i>>b={{25,25}};
    i m(i d[2], i h, i w, i a){
        if(a)b.push_back({0,0});
        for(i e=b.size()-1;e>0;e--)b.at(e)=b.at(e-1);
        if(b.at(0).at(0)+d[0]>5&&b.at(0).at(0)+d[0]<h-W)b.at(0).at(0)+=d[0];
        if(b.at(0).at(1)+d[1]>5&&b.at(0).at(1)+d[1]<w-W)b.at(0).at(1)+=d[1];}
    i d(){for(i e=0;e<b.size();e++)for(i a=0;a<b.size();a++)if(a!=e&&b.at(e).at(0)==b.at(a).at(0)&&b.at(e).at(1)==b.at(a).at(1))return false;return true;}
    i e(i x,i y){for(i e=0;e<b.size();e++)if(b.at(e).at(0)==x&&b.at(e).at(1)==y)return true;return false;}
    i R(SDL_Renderer *R){SDL_SetRenderDrawColor(R,255,0,255,255);for(i e=0;e<b.size();e++)r.x=b.at(e).at(0),r.y=b.at(e).at(1),SDL_SetRenderDrawColor(R,255,0,255,255),SDL_RenderFillRect(R,&r);}
}; 
i main2(i c,char*v[]){
    i l=10,E=-1,w=480,h=640,D[2]={0,0};
    SDL_Window *W;
    SDL_Renderer *R;
    SDL_Event e;
    SDL_Rect f={0,0,10,10};
    s S=s(++l);
    //std::cout << SDL_KEYDOWN << std::endl;
    W=SDL_CreateWindow("S",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,h,w,SDL_WINDOW_OPENGL);
    R=SDL_CreateRenderer(W,-1,2);
    while(S.d() && !(e.type==SDL_QUIT)){
        if(E)f.x=25+(11*(rand()%(54+1))),f.y=25+(11*(rand()%(40+1))),E=-1;
        while(SDL_PollEvent(&e)){ 
            if(e.type==SDL_KEYDOWN){ 
                switch(e.key.keysym.sym){ 
                    case 1073741906:D[0]=0,D[1]=-l;break; 
                    case 1073741905:D[0]=0,D[1]=l;break; 
                    case 1073741904:D[0]=-l,D[1]=0;break; 
                    case 1073741903:D[0]=l,D[1]=0;break;
                }
            }
        }
        SDL_SetRenderDrawColor(R,0,0,0,0);
        SDL_RenderClear(R);
        E=S.e(f.x,f.y);
        S.m(D,h,w,E);
        S.R(R);
        SDL_RenderFillRect(R,&f);
        SDL_RenderPresent(R);
        SDL_Delay(50);
    }
    SDL_Quit();
}


//typedef int i;struct s{s(i a):W(a){}i W;SDL_Rect r={25,25,10,10};std::vector<std::vector<i>>b={{25,25}};i m(i d[2], i h, i w, i a){if(a)b.push_back({0,0});for(i e=b.size()-1;e>0;e--)b.at(e)=b.at(e-1);if(b.at(0).at(0)+d[0]>5&&b.at(0).at(0)+d[0]<h-W)b.at(0).at(0)+=d[0];if(b.at(0).at(1)+d[1]>5&&b.at(0).at(1)+d[1]<w-W)b.at(0).at(1)+=d[1];}i d(){for(i e=0;e<b.size();e++)for(i a=0;a<b.size();a++)if(a!=e&&b.at(e).at(0)==b.at(a).at(0)&&b.at(e).at(1)==b.at(a).at(1))return 0;return 1;}i e(i x,i y){for(i e=0;e<b.size();e++)if(b.at(e).at(0)==x&&b.at(e).at(1)==y)return 1;return 0;}i R(SDL_Renderer*R){SDL_SetRenderDrawColor(R,255,0,255,255);for(i e=0;e<b.size();e++)r.x=b.at(e).at(0),r.y=b.at(e).at(1),SDL_SetRenderDrawColor(R,255,0,255,255),SDL_RenderFillRect(R,&r);}};i main(i c,char*v[]){i l=10,E=-1,w=480,h=640,D[2]={0,0};SDL_Window *W;SDL_Renderer *R;SDL_Event e;SDL_Rect f={0,0,10,10};s S=s(++l);W=SDL_CreateWindow("S",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,h,w,SDL_WINDOW_OPENGL);R=SDL_CreateRenderer(W,-1,SDL_RENDERER_ACCELERATED);while(S.d()&&!(e.type==SDL_QUIT)){if(E)f.x=25+(11*(rand()%(54+1))),f.y=25+(11*(rand()%(40+1))),E=-1;while(SDL_PollEvent(&e)){if(e.type==SDL_KEYDOWN){switch(e.key.keysym.sym){case SDLK_UP:D[0]=0,D[1]=-l;break;case SDLK_DOWN:D[0]=0,D[1]=l;break;case SDLK_LEFT:D[0]=-l,D[1]=0;break;case SDLK_RIGHT:D[0]=l,D[1]=0;break;}}}SDL_SetRenderDrawColor(R,0,0,0,0);SDL_RenderClear(R);E=S.e(f.x,f.y);S.m(D,h,w,E);S.R(R);SDL_RenderFillRect(R,&f);SDL_RenderPresent(R);SDL_Delay(50);}SDL_Quit();}