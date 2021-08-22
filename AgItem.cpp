/*
 * File:          AgItem.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Alex Strong
 * Date:          4/15/21
 * Section:       52
 * E-mail:        astrong3@umbc.edu
 *
 * Description:   This file contains the AgItem.cpp
 *
 *
 */

#include "AgItem.h"

//Default constructor to initialize variables
AgItem::AgItem() {
    m_size = 0;
    m_worth = BASE_WORTH;
    m_isHarvestable = false;
}

//Overloaded constructor to initialize variables with inputted values
AgItem::AgItem(int size, int worth, bool harvestable) {
    m_size = size;
    m_worth = worth;
    m_isHarvestable = harvestable;
}

//Destructor, left empty because there are no new allocations of memory
AgItem::~AgItem() {
}

//Getter for the size
int AgItem::GetSize() {
    return m_size;
}

//Getter for the worth
int AgItem::GetWorth() {
    return m_worth;
}

//Getter for if the object is harvestable or not
bool AgItem::GetIsHarvestable() {
    return m_isHarvestable;
}

//Setter for the member size variable
void AgItem::SetSize(int size) {
    m_size = size;
}

//Setter for the member harvestable variable
void AgItem::SetIsHarvestable(bool isAlive) {
    m_isHarvestable = isAlive;
}

//Setter for the worth member variable
void AgItem::SetWorth(int worth) {
    m_worth = worth;
}