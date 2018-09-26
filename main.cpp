#include <iostream>
//#include <locale>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <windows.h>
#define SDL_MAIN_HANDLED
#include "sound_sdl.h"
#include "configfile.h"

using namespace std;

int main()
{
  std::cout << "Options:\n0 -Exit(you can write \"exit\")\n1 -Normal(you can write \"normal\")\n2 -MEME(you can write \"meme\")" << '\n';
int loopopt1=1;
//===================================================
string normal_tilde = "";
string normal_plus = "";
string meme_plus = "";
string meme_tilde = "";
string devicename = "";
config(normal_plus, normal_tilde, meme_plus, meme_tilde,devicename);
//=====================================================
char optionas[30];
while(loopopt1==1)//MAIN menu begin
{
  string Soptionas;
  cout<<">";
  cin >> optionas;
  Soptionas=optionas;
  transform(Soptionas.begin(),Soptionas.end(),Soptionas.begin(),::tolower);
  //Soptionas=tolower(optionas);
  if((strcmp(optionas,"0")==0)|(strcmp(optionas,"exit")==0))
  loopopt1=0;
  if((strcmp(optionas,"1")==0)|(strcmp(optionas,"normal")==0))
  {
    //string Soptionas;
    int loopopt2=1;
    Soptionas="";

    cout<<"--------NORMAL MODE------;"<<endl;
    cout<<"Write exit to get back;"<<endl;
    cout << "Press tilde key to play \"Sword Dance\"" << endl;
    cout << "Press + key to play \"NANI\"" <<endl;
    cout<<">";
    while (loopopt2==1)//PRESS 1 menu
    {

    //  cin >> optionas;
      Soptionas=optionas;
      transform(Soptionas.begin(),Soptionas.end(),Soptionas.begin(),::tolower);
      if(strcmp(optionas,"exit")==0)
      loopopt2=0;
      if(GetAsyncKeyState(0x6B)){//+
        sound_sdl(normal_plus,devicename);
      }
      if(GetAsyncKeyState(0xC0)){//tilde
      sound_sdl(normal_tilde,devicename);
      }
      if(GetAsyncKeyState(0x23)){//tilde
      loopopt2=0;
      }
    }//PRESS 1 menu end

    }
    if ((strcmp(optionas,"2")==0)|(strcmp(optionas,"meme")==0))
    {

      int loopopt3=1;
      Soptionas="";
      cout<<"--------MEME MODE------;"<<endl;
      cout<<"Write exit to get back;"<<endl;
      cout << "Press tilde key to play \"Sword Dance\"" << endl;
      cout << "Press + key to play \"NANI\"" <<endl;
      cout<<">";
      while (loopopt3==1)//PRESS 2 menu
      {

      //  cin >> optionas;
        Soptionas=optionas;
        transform(Soptionas.begin(),Soptionas.end(),Soptionas.begin(),::tolower);
        if(strcmp(optionas,"exit")==0)
        loopopt3=0;
        if(GetAsyncKeyState(0x6B)){//+
          sound_sdl(meme_tilde,devicename);
        }
        if(GetAsyncKeyState(0xC0)){//tilde
        sound_sdl(meme_plus,devicename);
        }
        if(GetAsyncKeyState(0x23)){
        loopopt3=0;
        }
      }//PRESS 2 MENU end
  }

}//MAIN MENU end



  return 0;
}
