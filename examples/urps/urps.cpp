#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "str_tok.h"
using namespace std;

fstream conf ("rps.ini");
string rps_opts, rps_c, rps_d, mod, modes, win = "You win!\n", lose = "Sorry, you lose, try again.\n";

int rps_win(string v1, string v2)
{
    if (v1 == v2) return 3;
    if (readloadedini(conf,mod,v1,findtok(rps_opts,v2,1," ")) == "0") return 1;
    else return 2;
}

string rps_result(string v1, string v2)
{
    int i = rps_win(v1,v2);
    if (i == 1) return readloadedini(conf,mod,v2,findtok(rps_opts,v1,1," "));
    if (i == 2) return readloadedini(conf,mod,v1,findtok(rps_opts,v2,1," "));
    return "0";
}

int main()
{
    if (!conf.is_open())
    {
        cout<<"Error: The \"rps.ini\" file could not be located.\n";
        system("PAUSE");
        return 1;
    }
    int result, topics;
    stringstream(ini_info(conf,0)) >> topics;
    modes = ini_info(conf,topics);
    
    for (int i = topics-1;i;i--)
          modes = modes + " " + ini_info(conf,i);
    
    cout<<"Welcome to NIGathan's Ultimate RPS!\nPick one of the following game modes:\n"<<strreplace(modes," ",", ")<<"\n\n";
    while (1)
    {
          cin>>mod;
          if (!istok(modes,mod," ")) cout<<"\nGame mode does not exist, try again.\n\n";
          else break;
    }
    cout<<"Loading \""<<readloadedini(conf,mod,"info")<<"\"...\nMod written by: "<<readloadedini(conf,mod,"author")<<"\n";
    rps_opts = readloadedini(conf,mod,"opts");
    while (1)
    {
          string rps_c;
          cout<<"\nChoose one of the following (quit to stop):\n\n"<<strreplace(rps_opts," ",", ")<<"\n\n";
          while (1) {
             cin>>rps_c;
             rps_c = lower(rps_c);
             if (rps_c == "quit") break;
             if (!istok(rps_opts,rps_c," ")) cout<<"\nInvalid choice, please try again.\n";
             else break;
          }
          if (rps_c == "quit") break;
          rps_d = gettok(rps_opts,randint(1,numtok(rps_opts," "))," ");
          cout<<"\nI chose "<<rps_d<<", you chose "<<rps_c<<".\n";
          result = rps_win(rps_c,rps_d);
          if (result == 3) cout<<"It ends in a tie.\n";
          else 
          {
               cout<<rps_result(rps_c,rps_d)<<"!\n";
               if (result == 1) cout<<win;
               else cout<<lose;
          }
    }
    system("PAUSE");
    return 0;
}
