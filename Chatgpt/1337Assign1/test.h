#ifndef HOTDOG_STAND_CLASS_H
#define HOTDOG_STAND_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class HotDogStandsClass {
private:
    string identificationStr;
    string addressStr;
    float hotdogPriceFl;
    unsigned inventoryAmountUns;
    unsigned soldAmountUns;

public:
    HotDogStandsClass() { }

    static unsigned globalSoldCountUns;

    const string& getIdStr() const { 
        return identificationStr; 
    }
    
    void setIdStr(const string& identificationStr) { 
        this->identificationStr = identificationStr; 
    }

    const string& getAddressStr() const { 
        return addressStr; 
    }
    
    void setAddressStr(const string& addressStr) { 
        this->addressStr = addressStr; 
    }

    float getPriceFl() const { 
        return hotdogPriceFl;  
    }
    
    void setPriceFl(float hotdogPriceFl) { 
        this->hotdogPriceFl = hotdogPriceFl; 
    }

    unsigned getSoldAmountUns() const { 
        return  soldAmountUns; 
    }
    
    void setSoldAmountUns(unsigned soldAmountUns) { 
        this->soldAmountUns = soldAmountUns; 
    }

    unsigned getInventoryAmountUns() const { 
        return inventoryAmountUns; 
    }
    
    void setInventoryAmountUns(unsigned inventoryAmountUns) { 
        this->inventoryAmountUns = inventoryAmountUns; 
    }

    void stockInventoryAmountUns(unsigned stockCountUns) { 
        // Example: assign or add to inventory; adjust according to your intent
        this->inventoryAmountUns = stockCountUns; 
        // Or if adding:
        // this->inventoryAmountUns += stockCountUns;
    }

    void hotDogsBuyUns(unsigned count);

}; // end of HotDogStandsClass

#endif
