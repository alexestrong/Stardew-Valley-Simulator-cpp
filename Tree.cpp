/*
 * File:          Tree.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Alex Strong
 * Date:          4/15/21
 * Section:       52
 * E-mail:        astrong3@umbc.edu
 *
 * Description:   This file contains the Tree.cpp
 *
 *
 */

#include "Tree.h"

//Default constructor for the tree class, sets variable to starting point
Tree::Tree() {
    m_age = 0;
}

//Destructor shouldn't need to run, but will clean up if any fruits are left in the fruit storing vector
Tree::~Tree(){
    for (unsigned int i = 0; i < m_fruit.size(); i++){
        delete m_fruit[i];
    }
}

//Tick function which will run various tree & AgItem functions as it grows
void Tree::Tick(bool fed) {
    //When the tree age is below fruiting (mature) age it will continue to size up until mature
    if(m_age <= SEASONS_TO_FRUIT){
        if(m_age % SEASONS_TO_SIZE == 0 && m_age != 0){
            SetSize(GetSize() + 1);
        }
    }

    //If the tree can fruit (is mature) and not too old yet then it will grow a new fruit
    if(m_age > SEASONS_TO_FRUIT && m_age < SEASONS_TO_HARVEST){
        Fruit* myFruit = new Fruit;
        m_fruit.push_back(myFruit);
    }

    //If tree is at harvesting age, it will be set as harvestable
    if(m_age == SEASONS_TO_HARVEST){
        SetIsHarvestable(true);
    }

    //As long as tree is not yet harvestable, everytime the tick is run, tree will age
    if(!GetIsHarvestable())
        m_age++;
}


//Harvest function to return whether it has produced a fruit or not
int Tree::Harvest() {
    //If a fruit is present and tree not too old yet, the new fruit created will be deallocated and deleted from vector
    if(m_fruit.size() > 0 && !GetIsHarvestable()){
        delete m_fruit[0];
        m_fruit.pop_back();
        return 1;
    }
    else{
        return 0;
    }

}

//Function returns the name of the type of object
string Tree::GetType() {
    return "Tree";
}

//Virtual function that will display and output specific to the tree class
ostream& Tree::operator<<(ostream& output) {
    int count = 0;
    for (unsigned int i = 0; i < m_fruit.size(); i++) {
        count++;
    }

    //Two different conditions for when tree is harvestable
    if (GetIsHarvestable() && m_age > SEASONS_TO_FRUIT) {
        output << GetType() << CONCAT << TREE_SIZE[GetSize()] << " |  Harvestable | Fruiting | Fruit Count: " << count;
    }
    if(GetIsHarvestable() && m_age <= SEASONS_TO_FRUIT){
        output << GetType() << CONCAT << TREE_SIZE[GetSize()] << " |  Harvestable | Not Fruiting | Fruit Count: " << count;
    }

    //Two different conditions for when animal is not harvestable
    if (!GetIsHarvestable() && m_age > SEASONS_TO_FRUIT) {
        output << GetType() << CONCAT << TREE_SIZE[GetSize()] << " |  Not Harvestable | Fruiting | Fruit Count: "
               << count;
    }
    if (!GetIsHarvestable() && m_age <= SEASONS_TO_FRUIT) {
        output << GetType() << CONCAT << TREE_SIZE[GetSize()] << " |  Not Harvestable | Not Fruiting | Fruit Count: "
               << count;
    }
    return output;
}