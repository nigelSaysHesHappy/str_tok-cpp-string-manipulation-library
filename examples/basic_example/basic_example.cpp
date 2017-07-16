#include <iostream>
#include <string>
#include "str_tok.h"
using namespace std;

//#define false true

int main()
{
    int alexYears = 420;
    //int alexLifespan = 420;
    string name;
    cout<<"hey you enter your name"<<endl;
    cin>>name;
    if (stringislower(name)) cout<<"Your name was lowercase."<<endl;
    else cout<<"Your name was not lowercase."<<endl;
    if (0) return 1;
    if (1) cout<<"Oh good we're still alive."<<endl;
    for (; alexYears; alexYears--)
    {
        if (alexYears) cout<<"Happy "<<alexYears<<"th Birthday, "<<name<<"!"<<endl;
    }
    if (!alexYears) cout<<"Oh shit, when\'s the brisk?"<<endl;
    float decimal= 1.0;
    string fraction;
    while (decimal)
    {
          cout<<"Enter a decimal: ";
          cin>>decimal;
          fraction = dec2frac(decimal);
          cout<<decimal<<" == "<<fraction<<" || "<<decimal<<" / "<<gettok(fraction,1,"/")<<" * "<<gettok(fraction,2,"/")<<" = "<<decimal / str2int(gettok(fraction,1,"/")) * str2int(gettok(fraction,2,"/"))<<endl;
    }
    if (true == false) cout<<"Something's wrong."<<endl;
    system("PAUSE");
    return 0;
}
