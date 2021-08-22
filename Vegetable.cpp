/*
 * File:          Vegetable.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Alex Strong
 * Date:          4/15/21
 * Section:       52
 * E-mail:        astrong3@umbc.edu
 *
 * Description:   This file contains the Vegetable.cpp
 *
 *
 */

#include "Vegetable.h"

//Default constructor for vegetable items (has no member variables to initialize)
Vegetable::Vegetable() : AgItem(){
}

//Returns size for when the vegetable is harvested to determine its worth
int Vegetable::Harvest() {
    return GetSize();
}

//Tick function to allow the vegetable to grow until its mature size of (2)
void Vegetable::Tick(bool fed) {
    //As long as vegetable is under the max size it will keep growing
    if(GetSize() < MAX_VEG_SIZE){
        SetSize(GetSize() + 1);
    }
    //Otherwise it will not longer grow and it will be recognized as harvestable
    else{
        SetIsHarvestable(true);
    }
}

//Function returns the name of the type of object
string Vegetable::GetType() {
    return "Vegetable";
}

//Virtual function that will display and output specific to the vegetable class
ostream& Vegetable::operator<<(ostream& output){
    if(GetIsHarvestable()){
        output << GetType() << CONCAT << "Harvestable | " << Veg_Size[GetSize()];
    }else{
        output << GetType() << CONCAT << "Not Harvestable | " << Veg_Size[GetSize()];
    }
    return output;
}