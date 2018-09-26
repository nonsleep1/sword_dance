#include "configfile.h"

using namespace std;

void config(std::string &normal_plus,std::string &normal_tilde,
  std::string &meme_plus,
  std::string &meme_tilde,
  std::string &devicename)
{
  std::string variab, argument, line;

  int counteris=0;

  std::fstream configfile ("config.ini");
    if(configfile.is_open())
    {
     std::vector<std::string>tokensas;


      while(getline(configfile,line))
      {

        std::istringstream iline(line);
        std::string temp;
        while(getline(iline,temp,'='))
        {
          tokensas.push_back(temp);
            ++counteris;
        }


      }

      for(int i=0;i<counteris;i++)
      {
        if(tokensas[i]=="normal_plus"){normal_plus=tokensas[i+1];}
        if(tokensas[i]=="normal_tilde"){normal_tilde=tokensas[i+1];}
        if(tokensas[i]=="meme_plus"){meme_plus=tokensas[i+1];}
        if(tokensas[i]=="meme_tilde"){meme_tilde=tokensas[i+1];}
        if(tokensas[i]=="devicename"){devicename=tokensas[i+1];}
      //  std::cout <<i<< " ___ "<<tokensas[i] << '\n';

      }
      /*  std::cout <<"+++"<< normal_plus <<"+++"<< '\n';
        std::cout <<"+++"<< normal_tilde <<"+++"<< '\n';
        std::cout <<"+++"<< meme_plus <<"+++"<< '\n';
        std::cout <<"+++"<< meme_tilde <<"+++"<< '\n';
        std::cout <<"+++"<< devicename <<"+++"<< '\n';*/


    }

}
