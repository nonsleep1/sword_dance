//#define _GLIBCXX_USE_CXX11_ABI 0/1

#include <iostream>
#include <SDL2/SDL.h>
#include <string>



void MyAudioCallback(void* userdata, Uint8* stream, int streamLength);
int sound_sdl(std::string path,std::string devicename);
struct AudioData
{
  Uint8* pos;
  Uint32 length;

};
