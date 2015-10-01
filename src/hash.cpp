#include <iostream>
#include <cstdlib>
#include <string>
#include "hash.h"
using namespace std;

hash::hash()
{
      for(int i = 0;i < tablesize ; i++)
      {
          HashTable[i] = new item;
          HashTable[i]->name = "empty";
          HashTable[i]->drink = "empty";
          HashTable[i]->next = NULL;
      }
}

void hash::AddItem(string name,string drink)
{
    int index = Hash_func(name);

    if(HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item *ptr = HashTable[index];
        item *n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }

}

int hash::Hash_func(string name)
{
    cout << name << name.length() << endl;
    int hash_a = 0;
    int index;

    for(int i=0;i< name.length();i++)
    {
        hash_a = hash_a + (int) name[i];
        //cout << "hash_a = " << hash_a << endl;
    }

    index = hash_a % tablesize;

    return index;
}

void hash::PrintTable()
{
    int num;

    for(int i=0;i<tablesize;i++)
    {
        num = NumOfItemInIndex(i);
        cout<<"--------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "Number of items = "<< num << endl;
        cout<<"--------------------\n";
    }
}

void hash::PrintItemsInIndex(int index)
{
    item *ptr = HashTable[index];

    if(ptr->name == "empty")
        cout << "index = " << index << "is empty" << endl;
    else
    {
        cout << "index = " << index << "contains the following items\n";
        while(ptr != NULL)
        {
            cout << "---------------\n";
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "---------------\n";
            ptr = ptr->next;
        }
    }

}

int hash::NumOfItemInIndex(int index)
{
    int cnt = 0;
    if (HashTable[index]->name == "empty")
    {
        return cnt;
    }
    else
    {
        cnt++;
        item *ptr = HashTable[index];
        while(ptr->next != NULL)
        {
            cnt++;
            ptr = ptr->next;
        }
        return cnt;
    }
}

