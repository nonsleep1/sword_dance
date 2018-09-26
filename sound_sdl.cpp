#include "sound_sdl.h"

//#include <windows.h>

//#define FILE_PATH_SWORD_DANCE "C:\\Users\\nonsleepVM2\\Desktop\\test.wav"
//#define FILE_PATH_SWORD_DANCE "test1.wav"
//#define FILE_PATH_NANI "C:\\Users\\nonsleepVM2\\Desktop\\test.wav"

using namespace std;




void MyAudioCallback(void* userdata, Uint8* stream, int streamLength)
{
  AudioData* audio = (AudioData*)userdata;

  if(audio->length ==0)
  {
    return;
  }
  Uint32 length = (Uint32)streamLength;
  length = (length > audio->length ? audio->length : length);

  SDL_memcpy(stream, audio->pos, length);

  audio->pos += length;
  audio->length -= length;
}
int sound_sdl(std::string path,std::string devicename) {

  //string path;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_AudioSpec wavSpec;
  Uint8* wavStart;
  Uint32 wavLength;
  if(SDL_LoadWAV(path.c_str(), &wavSpec, &wavStart, &wavLength)==NULL)
  {
    cout << "Error: " <<path
    <<" could not loaded as an audio file"<<endl;
    return 1;
  }
  AudioData audio;
  audio.pos = wavStart;

  audio.length = wavLength;

  wavSpec.callback = MyAudioCallback;
  wavSpec.userdata = &audio;
  //string name = SDL_GetAudioDeviceName;
 /*cout <<"0 "<<SDL_GetAudioDeviceName(0,0)<<endl;
cout <<"1 "<<SDL_GetAudioDeviceName(1,0)<<endl;
cout <<"2 "<<SDL_GetAudioDeviceName(2,0)<<endl;
cout <<"3 "<<SDL_GetAudioDeviceName(3,0)<<endl;
cout <<"4 "<<SDL_GetAudioDeviceName(4,0)<<endl;
cout <<"5 "<<SDL_GetAudioDeviceName(5,0)<<endl;
cout <<"6 "<<SDL_GetAudioDeviceName(6,0)<<endl;
cout <<"7 "<<SDL_GetAudioDeviceName(7,0)<<endl;*/

  SDL_AudioDeviceID device = SDL_OpenAudioDevice("VoiceMeeter Input (VB-Audio VoiceMeeter VAIO)", 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
  if(device == 0)
  {
    cout << "Error: " << SDL_GetError() <<endl;
    return 1;
  }

  SDL_PauseAudioDevice(device, 0);

 while(audio.length > 0)
  {
    SDL_Delay(100);
  }
  SDL_CloseAudioDevice(device);
  SDL_FreeWAV(wavStart);

  SDL_Quit();

  return 0;
}
int main()
{
    return 0;
}
