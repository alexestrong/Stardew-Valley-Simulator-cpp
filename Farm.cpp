/*
 * File:          Farm.cpp
 * Project:       CMSC 202 Project 4, Spring 2021
 * Author:        Alex Strong
 * Date:          4/15/21
 * Section:       52
 * E-mail:        astrong3@umbc.edu
 *
 * Description:   This file contains the Farm.cpp
 *
 *
 */

#include "Farm.h"

//Farm Default constructor to set intial member variables
Farm::Farm() {
    m_food = 6;
    m_money = 0;
    m_season = 1;
}

//Farm destructor used in case that new objects are left in the m_farm vector
Farm::~Farm() {
    for (unsigned int i = 0; i < m_farm.size(); i++){
        delete m_farm[i];
    }
}

//Sub-menu for when the user requests to add something to the farm
int Farm::ChooseItem() {
    int userSelection = 0;
    //Accounts for input validation
    while(userSelection < 1 || userSelection > 3){
        cout << "What agricultural item are you interested in? " << endl;
        cout << "1. Animal" << endl;
        cout << "2. Vegetable" << endl;
        cout << "3. Tree" << endl;
        cin >> userSelection;
    }
    return userSelection;
}

//Function to add item(s) to the farm by storing them in the m_farm vector
void Farm::AddItem(int type, int quantity) {
    //Adding new Animal
    if (type == 1){
        for (int i = 0; i < quantity; i++){
            AgItem *newAgItem = new Animal;
            m_farm.push_back(newAgItem);
            cout << "New animal added to the farm" << endl;
        }
    }
    //Adding new Vegetable
    if (type == 2){
        for (int i = 0; i < quantity; i++){
            AgItem *newAgItem = new Vegetable;
            m_farm.push_back(newAgItem);
            cout << "New vegetable added to the farm" << endl;
        }
    }
    //Adding new Tree
    if (type == 3){
        for (int i = 0; i < quantity; i++){
            AgItem *newAgItem = new Tree;
            m_farm.push_back(newAgItem);
            cout << "New tree added to the farm" << endl;
        }
    }
    //Exception if type is unknown
    if (type > 3 || type < 1){
        cout << "Type unknown!" << endl;
    }

}

//Tick function controls as every season passes on the farm
void Farm::Tick(int numSeasons) {
    //Iterates through each season
    for(int i = 0; i < numSeasons; i++){
        cout << "SEASON: "<< m_season << endl;
        //Iterates through entire m_farm vector
        for(unsigned int j = 0; j < m_farm.size(); j++){

            //Determines if the tick parameter for being fed will be true or not
            //Then runs tick on each object
            if (m_food > 0) {
                    m_farm[j]->Tick(true);
                    //When object is an animal the animal must be fed so food will decrement
                    if (m_farm[j]->GetType() == "Animal"){
                        m_food--;
                    }
            }else{
                m_farm[j]->Tick(false);
            }

            //If object is a tree and a fruit is produced, food will be incremented
            if (m_farm[j]->GetType() == "Tree" && m_farm[j]->Harvest()){
                m_food++;
            }

            //If object is harvestable then it will take in the value through food or money and then deallocate the object
            if (m_farm[j]->GetIsHarvestable()) {
                if (m_farm[j]->GetType() == "Animal") {
                    m_money += m_farm[j]->Harvest();
                } else {
                    m_food += m_farm[j]->Harvest();
                }
                if (m_farm[j]->GetType() == "Tree") {
                    m_food++;
                }
                cout << m_farm[j]->GetType() << " was harvested!" << endl;
                delete m_farm[j];
                m_farm.erase (m_farm.begin()+j);
                j--;
            }
        }
        Status();
        m_season++;
    }
}

//Function to display the main menu for the user and returns the users selection
int Farm::Menu() {
    int userSelection;
    //Do while accounts for input validation
    do{
        cout << "1. Add item to the farm" << endl;
        cout << "2. Add two of each item to the farm" << endl;
        cout << "3. Simulate time" << endl;
        cout << "4. Farm Status" << endl;
        cout << "5. Quit" << endl;
        cin >> userSelection;
    }while(userSelection > 5 || userSelection < 1);
    return userSelection;
}

//Main controller function of the game, which will continue until the user wants to quit
void Farm::StartSimulation() {
    int selectedChoice;
    int chosenItem;
    int seasonInput;

    cout << "Welcome to the Stardew Valley Simulator!" << endl;
    //Do while will keep running the Do's switch statement until 5 is entered to quit
    do{
        selectedChoice = Menu();
        switch (selectedChoice) {
            case 1:
                chosenItem = ChooseItem();
                AddItem(chosenItem, 1);
                break;
            case 2:
                AddItem(1, 2);
                AddItem(2, 2);
                AddItem(3, 2);
                break;
            case 3:
                cout << "How many seasons to simulate?" << endl;
                cin >> seasonInput;
                Tick(seasonInput);
                break;
            case 4:
                Status();
                break;
            case 5:
                break;
            default:
                cout << "Unknown" << endl;
                break;
        }

    } while (selectedChoice != 5);
    cout << "Thank you for playing the Stardew Simulator!" << endl;

}

//Farms function in order to display the status of your farm and agricultural items
//Runs when called as well as every new Tick interval with the seasons
void Farm::Status() {
    cout << "**** Farm Status ****" << endl;
    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season: " << m_season << endl;
    cout << "Agricultural Items: " << endl;
    for (unsigned int i = 0; i < m_farm.size(); i++){
        (*m_farm.at(i)) << cout << endl;
    }
    cout << endl;
}