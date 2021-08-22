/*
 * File:          Animal.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Alex Strong
 * Date:          4/15/21
 * Section:       52
 * E-mail:        astrong3@umbc.edu
 *
 * Description:   This file contains the Animal.cpp
 *
 *
 */

#include "Animal.h"

//Default animal constructor to set default member variables
Animal::Animal() : AgItem(){
    m_name = "Chicken";
    m_IsHungry = true;
}

//Function checks if animal is fed or not and determines next step based on parameter
void Animal::Tick(bool fed) {
    //If fed and not max size, animal will grow and not be hungry
    if(fed && GetSize() != ANIMAL_MAX_SIZE){
        SetSize(GetSize() + 1);
        m_IsHungry = false;
    }
    //If fed and max size, animal will not grow and be harvestable
    else if(fed && GetSize() == ANIMAL_MAX_SIZE){
        SetIsHarvestable(true);
    }
    //If not fed and hungry, animal will be harvestable (2 seasons without food)
    else if(!fed && m_IsHungry){
        SetIsHarvestable(true);
    }
    //If not fed, but was fed last season, animal will now be hungry
    else if(!fed && !m_IsHungry){
        m_IsHungry = true;
    }
}

//Function returns how much the animal is worth when harvested
int Animal::Harvest() {
    return GetWorth() * GetSize();
}

//Function returns the name of the type of object
string Animal::GetType() {
    return "Animal";
}

//Virtual function that will display and output specific to the animal class
ostream& Animal::operator<<(ostream &output) {

    //Two different conditions for when animal is harvestable
    if (GetIsHarvestable() && !m_IsHungry) {
        output << GetType() << CONCAT << m_name << CONCAT << "Harvestable | " << ANIMAL_SIZE[GetSize()] << " | Fed";
    }
    if (GetIsHarvestable() && m_IsHungry) {
        output << GetType() << CONCAT << m_name << CONCAT << "Harvestable | " << ANIMAL_SIZE[GetSize()] << " | Not fed";
    }

    //Two different conditions for when animal is not harvestable
    if (!GetIsHarvestable() && !m_IsHungry) {
        output << GetType() << CONCAT << m_name << CONCAT << "Not Harvestable | " << ANIMAL_SIZE[GetSize()] << " | Fed";
    }
    if (!GetIsHarvestable() && m_IsHungry) {
        output << GetType() << CONCAT << m_name << CONCAT << "Not Harvestable | " << ANIMAL_SIZE[GetSize()] << " | Not fed";
    }

    return output;
}