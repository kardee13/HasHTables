#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "hash.h"
using namespace std;

int main()
{
    hash Hashy;

    std::fstream fs;
    fs.open("cities.txt",std::fstream::in);


    cout << "Entered into for loop : " << endl;
    if(fs)
    {
        cout << "Entered into if: " << endl;
        string s;
        while(getline(fs, s))
        {
            cout << "Entered into while loop : " << endl;

            char name[20];
            for (int i = 0;i<20;i++)
                name[i] = 0;

            for(int i = 0; i < s.length(); i++)
            {
                if(s[i] != 32  && s[i] != '\n')
                {
                    name[i] = s[i];
                    continue;
                }
                else
                    break;
            }
            cout<<name<<endl;
             Hashy.AddItem(name,"Drink");
            for (int i = 0;i<20;i++)
                name[i] = 0;

        }
    }
    //Hashy.PrintTable();
    Hashy.PrintItemsInIndex(7);

    return 0;
}
