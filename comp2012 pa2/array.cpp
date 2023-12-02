#include "array.h"

bool ItemsArray::find(const string &name) const{
    // Task 3.1: Find an item in the ItemsArray.
    if (arraySize == 0) return false;
    for (int i=0; i<arraySize; i++){
        if (items[i]->getName() == name){
            return true;
        }
    }
    return false;
}

bool ItemsArray::insert(Item* item){
    // Task 3.2: Insert an item into the ItemsArray.
    if (find(item->getName()) == true) return false;
    else{
        Item** New = new Item*[arraySize+1];
        bool check = false;
        bool confirm = false;

        if (arraySize == 0){
            New[0] = item;
            items = New;
        }
        else{
            // add them to new array with descending order
            for (int i=0; i<arraySize; i++){
                if (item->getDefaultPower() > items[i]->getDefaultPower() && check == false){
                    New[i] = item;
                    New[i+1] = items[i];
                    check = true;
                }
                else if (item->getDefaultPower() == items[i]->getDefaultPower()){
                    New[i] = items[i];
                    New[i+1] = item;
                    check = true;
                }
                else if (item->getDefaultPower() < items[i]->getDefaultPower()){
                    New[i] = items[i];
                }
                else if (item->getDefaultPower() > items[i]->getDefaultPower() && check == true){
                    New[i+1] = items[i];
                }
            }

            // check if the item has the smallest default power
            for (int i=0; i<arraySize; i++){
                if (New[i]->getName() == item->getName()){
                    confirm = true;
                }
            }
            if (confirm == false) New[arraySize] = item;

            delete [] items;
            items = New;
        }      
        arraySize++;
        return true;
    }
}

AttackItem* AttackItemsArray::attack(){
    // Task 5.1: Choose the most powerful attack item.
    if (arraySize == 0) return nullptr;
    for (int i=0; i<arraySize; i++){
        AttackItem* temp = dynamic_cast<AttackItem*> (items[i]);
        if (temp->usable() == true) return temp;
    }
    return nullptr;
}

DefenseItem* DefenseItemsArray::defense(AttackItem* attackItem, int& defense_power){
    // Task 5.2: Choose the best defending item.
    if (arraySize == 0) return nullptr;

    int best = 0;
    int finding = 0;
    int test = 0;
    DefenseItem* good = nullptr;

    for (int i=0; i<arraySize; i++){
        DefenseItem* temp = dynamic_cast<DefenseItem*> (items[i]);

        // find p1 (get default power)
        int p1 = temp->getDefaultPower();
        // find p3 (get remaining power)
        int p3 = temp->getRemainingDefensePower();

        // find p2 (if datapair exists in corresponding attack item)
        int p2 = 0;
        if (attackItem != nullptr){
            p2 = temp->getDefensePair()->find(attackItem->getName());
        }

        finding = (p2 >= p1) ? p2 : p1;
        test = (finding < p3) ? finding : p3;
        
        // compare
        if (test > best){
            best = test;
            good = temp;
        }
    }

    // update defense power
    defense_power = best;
    if (best == 0){
        return nullptr;
    }
    else{
        return good;
    } 
}