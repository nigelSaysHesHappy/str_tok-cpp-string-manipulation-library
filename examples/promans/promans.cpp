
#ifdef USE_UNICODE
#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif
#endif

//The above doesn't do shit!
//Well right now? No, not unless you #define USE_UNICODE
//#ifndef is if not defined.

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <dirent.h>
#include <windows.h>
#include <mmsystem.h>
#include <dos.h>
#include "str_tok.h"
#include "concol.h"

using namespace std;

int listFile(string dirArray[]);

int main()
{
    //system("CHCP 1252"); //Why doesn't this work?!
    
    SetConsoleTitle("Promans Drinking Game");
    
    concol b=concol(backcolor());
    concol f=concol(textcolor());
    
    string files[2222];
    int total = listFile(files);
    //for (int i = 0;i < total;i++)
    //    cout<<i<<": "<<files[i]<<endl;
    cout << "NIGathan's sound guesser thingy! Best used with PronunciationManual's clips.\n\n";
    cout << "Loaded " << total << " wav files.\n\n";
    system("PAUSE");
    cout << endl;
    
    int sound[4];
    string used;
    string current;
    int answer;
    string temp;
    string abcd = "ABCD";
    while (1)
    {
          if (numtok(used,".") >= total) used = "";
          current = "";
          sound[0] = randint(0,total);
          while (istok(used,data2str("%i",sound[0]),"."))
                sound[0] = randint(0,total);
          current = addtok(current,data2str("%i",sound[0]),".");
          used = addtok(used,data2str("%i",sound[0]),".");
          for (int i = 1;i < 4;i++)
          {
              sound[i] = randint(0,total);
              while (istok(current,data2str("%i",sound[i]),"."))
                    sound[i] = randint(0,total);
              current = addtok(current,data2str("%i",sound[i]),".");
          }
          current = randomizetok(current,".");
          temp = data2str("%i",sound[0]);
          for (int i = 0;i < 4;i++)
          {
              if (temp == gettok(current,i+1,".")) answer = i;
              cout << abcd[i] << ") " << files[str2int(gettok(current,i+1,"."))] << "\n\n";
          }
          #ifdef UNICODE
          WCHAR nonsense[256];
          mbstowcs(nonsense, files[sound[0]].c_str(),sizeof(nonsense));
          PlaySound(nonsense, NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
          #else
          PlaySound(files[sound[0]].c_str(), NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
          #endif
          cout << "\n\n\n\n\n";
          system("PAUSE");
          cout << "\nAnswer: ";
          setcolor(yellow,b);
          cout << abcd[answer] <<") " << files[sound[0]] << "\n\n";
          setcolor(f,b);
          system("PAUSE");
          cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    }
    return 0;
}

int listFile(string dirArray[]){
        DIR *pDIR;
        struct dirent *entry;
        int i = 0;
        if( pDIR=opendir(".") ){
                while(entry = readdir(pDIR)){
                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
                        {
                            dirArray[i] = entry->d_name;
                            if (strright(dirArray[i],4) == ".wav")
                            {
                               dirArray[i] = strleft(dirArray[i],-4);
                               i++;
                            }
                            else dirArray[i] = "";
                        }
                }
                closedir(pDIR);
        }
        return i;
}
