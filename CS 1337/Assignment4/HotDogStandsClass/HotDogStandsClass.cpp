#ifndef HOTDOG_STAND_CLASS_CPP
#define HOTDOG_STAND_CLASS_CPP

#include "HotDogStandsClass.h"

using namespace std;

unsigned HotDogStandsClass::globalSoldCountUns = 0;

void HotDogStandsClass::hotDogsBuyUns(unsigned count) 
{
    if (inventoryAmountUns==0)
    {
        cout<<"There are no more hotdogs left to be sold. Try again later."<<endl;
        return;
    }

    else if (count>inventoryAmountUns)
    {
        cout<<"Stand "<<identificationStr<<"has only "<<inventoryAmountUns<<" hotdogs avaliable. Try again."<<endl<<endl;
        return;
    }

    else 
    {
    soldAmountUns += count;
    inventoryAmountUns -= count;
    globalSoldCountUns += count;
    
    cout << "Transaction successful!" << count << " hotdog(s) sold." << endl;
    }
}

void HotDogStandsClass::stockInventoryAmountUns(unsigned stockAmountUns)
{
    if (stockAmountUns==0)
    {
        cout<<"No Hotdogs were added."<<endl;
    }

    if (stockAmountUns<0)
    {
        cout<<"Invalid stock amount. Please enter a valid number (>=0)"<<endl;
    }

    else 
    {
        inventoryAmountUns+=stockAmountUns;
        cout<<stockAmountUns<<" hotdogs were added to the inventory. New inventory count is "<<inventoryAmountUns<<endl;
    }
}

#endif