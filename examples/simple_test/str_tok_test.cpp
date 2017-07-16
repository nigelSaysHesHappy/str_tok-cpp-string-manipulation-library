#include <iostream>
#include <string>
#include <fstream>
#include "str_tok.h"
using namespace std;

int main()
{
    ifstream inifile ("test.ini");
    if (!inifile.is_open()) return 1;
    string input;
    string delimiter;
    string substring;
    string subsubstring;
    int num, num2;
    while (1)
    {
            cout<<"Input a non-spaced string: ";
            cin>>input;
            if (input.compare("quit") == 0) break;
            cout<<"Input a non-spaced sub-string: ";
            cin>>substring;
            cout<<"Input a non-spaced sub-sub-string: ";
            cin>>subsubstring;
            cout<<"Input a single char token delimiter: ";
            cin>>delimiter;
            cout<<"Input a number: ";
            cin>>num;
            cout<<"Another: ";
            cin>>num2;
            cout<<"Results:\n";
            cout<<"len("<<input<<"):\t\t"<<len(input)<<"\tlen("<<substring<<"):\t"<<len(substring)<<"\n";
            cout<<"numtok("<<input<<","<<delimiter<<"):\t\t"<<numtok(input,delimiter)<<"\n";
            if (num < 0) cout<<"gettok("<<input<<","<<num<<","<<delimiter<<"):\t\t"<<gettok(input,num,delimiter)<<"\n";
            for (int x = 1; x <= numtok(input,delimiter); x++) cout<<"gettok("<<input<<","<<x<<","<<delimiter<<"):\t\t"<<gettok(input,x,delimiter)<<"\n";
            cout<<"\n";
            cout<<"isin("<<input<<","<<substring<<"):\t\t"<<isin(input,substring)<<"\n";
            for (int x = 0; x <= isin(input,substring,0); x++) cout<<"isin("<<input<<","<<substring<<","<<x<<"):\t\t"<<isin(input,substring,x)<<"\n";
            cout<<"iswm("<<input<<","<<substring<<"):\t\t"<<iswm(input,substring)<<"\n\n";
            cout<<"findtok("<<input<<","<<substring<<","<<num<<","<<delimiter<<"):\t"<<findtok(input,substring,num,delimiter)<<"\n";
            cout<<"wildtok("<<input<<","<<substring<<","<<num<<","<<delimiter<<"):\t"<<wildtok(input,substring,num,delimiter)<<"\n";
            cout<<"istok("<<input<<","<<substring<<","<<delimiter<<"):\t"<<istok(input,substring,delimiter)<<"\n\n";
            cout<<"addtok("<<input<<","<<substring<<","<<delimiter<<"):\t"<<addtok(input,substring,delimiter)<<"\n";
            cout<<"appendtok("<<input<<","<<substring<<","<<delimiter<<"):\t"<<appendtok(input,substring,delimiter)<<"\n";
            cout<<"deltok("<<input<<","<<num<<","<<delimiter<<"):\t\t"<<deltok(input,num,delimiter)<<"\n\n";
            cout<<"instok("<<input<<","<<substring<<","<<num<<","<<delimiter<<"):\t"<<instok(input,substring,num,delimiter)<<"\n\n";
            cout<<"matchtok("<<input<<","<<substring<<","<<num<<","<<delimiter<<"):\t"<<matchtok(input,substring,num,delimiter)<<"\n\n";
            cout<<"puttok("<<input<<","<<substring<<","<<num<<","<<delimiter<<"):\t"<<puttok(input,substring,num,delimiter)<<"\n";
            cout<<"remtok("<<input<<","<<substring<<","<<num<<","<<delimiter<<"):\t"<<remtok(input,substring,num,delimiter)<<"\n";
            cout<<"reptok("<<input<<","<<substring<<","<<subsubstring<<","<<num<<","<<delimiter<<"):\t"<<reptok(input,substring,subsubstring,num,delimiter)<<"\n\n";
            cout<<"stringisalpha("<<input<<"):\t"<<stringisalpha(input)<<"\n";
            cout<<"stringisalnum("<<input<<"):\t"<<stringisalnum(input)<<"\n";
            cout<<"stringislower("<<input<<"):\t"<<stringislower(input)<<"\n";
            cout<<"stringisupper("<<input<<"):\t"<<stringisupper(input)<<"\n\n";
            cout<<"stringisnum("<<input<<"):\t"<<stringisnum(input)<<"\n";
            cout<<"stringisnum("<<input<<","<<num<<","<<num2<<"):\t"<<stringisnum(input,num,num2)<<"\n\n";
            cout<<"isletter("<<input<<"):\t"<<isletter(input)<<"\n";
            cout<<"isletter("<<input<<","<<substring<<"):\t"<<isletter(input,substring)<<"\n\n";
            cout<<"upper("<<input<<"):\t"<<upper(input)<<"\n";
            cout<<"lower("<<input<<"):\t"<<lower(input)<<"\n\n";
            cout<<"strreplace("<<input<<","<<substring<<","<<subsubstring<<"):\t"<<strreplace(input,substring,subsubstring)<<"\n";
            //cout<<"sorttok("<<input<<","<<delimiter<<"):\t"<<sorttok(input,delimiter)<<"\n";
            cout<<"strleft("<<input<<","<<num<<"):\t"<<strleft(input,num)<<"\n";
            cout<<"strright("<<input<<","<<num<<"):\t"<<strright(input,num)<<"\n";
            cout<<"strmid("<<input<<","<<num<<","<<num2<<"):\t"<<strmid(input,num,num2)<<"\n\n";
            cout<<"randtok("<<input<<","<<delimiter<<"):\t"<<randtok(input,delimiter)<<"\n";
            cout<<"randomizetok("<<input<<","<<delimiter<<"):\t"<<randomizetok(input,delimiter)<<"\n";
            cout<<"strrep("<<input<<","<<num<<"):\t"<<strrep(input,num)<<"\n\n";
            cout<<"readini("<<input<<","<<substring<<","<<subsubstring<<"):\t"<<readini(input,substring,subsubstring)<<"\n";
            //cout<<"readloadedini(inifile,"<<substring<<","<<subsubstring<<"):\t"<<readloadedini(inifile,substring,subsubstring)<<"\n";
            cout<<"strremove("<<input<<","<<substring<<"):\t\t"<<strremove(input,substring)<<"\n";
    }
    system("pause");
    return 0;
}
