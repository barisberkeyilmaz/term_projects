#include "../include/team.h"

using namespace std;


Team::Team(){};
string Team::getName() { return name; };
int Team::getCurrentSize() { return current_size; };
int Team::getId() { return id; };
int Team::getCapacity() { return capacity; };
Player *Team::getPlayer(int number)
{
    for (int i = 0; i < current_size; i++)
    {
        if (player_list[i].getNumber() == number)
            return &player_list[i];
    }
    return nullptr;
};
Player *Team::getPlayerList()
{
    return player_list;
};
void Team::setName(string new_name) { name = new_name; };
void Team::setId(int newId) { id = newId; };
void Team::listPlayers()
{
    cout << "Number"
         << " Name"
         << " Age"
         << " #Goals"
         << " #Assists"
         << " #Matches" << endl;
    ;
    for (int i = 0; i < current_size; i++)
    {
        cout << player_list[i].getNumber() << " - ";
        cout << player_list[i].getName() << " - ";
        cout << player_list[i].getAge() << " - ";
        cout << player_list[i].getGoalNumber() << " - ";
        cout << player_list[i].getAssistNumber() << " - ";
        cout << player_list[i].getMatchNumber() << endl;
    }
};
void Team::addPlayer(int number, string name, int age, int goals, int assists, int matches)
{
    // Fill this method
    if(capacity <= 0){
        current_size = 0;
        capacity = 3;
        
        Player *player_list = new Player[capacity];
        player_list[current_size].setName(name);
        player_list[current_size].setNumber(number);
        player_list[current_size].setAge(age);
        player_list[current_size].setGoalNumber(goals);
        player_list[current_size].setAssistNumber(assists);
        player_list[current_size].setMatchNumber(matches);
        
        this->player_list = player_list;

        player_list = NULL;
        delete[] player_list;
        current_size++;
    }
    else if(capacity == current_size){
        capacity = capacity * 2;

        Player *temp_parr = new Player[capacity];
        
        for (int i = 0; i < current_size; i++){
            temp_parr[i].setName(player_list[i].getName());
            temp_parr[i].setNumber(player_list[i].getNumber());
            temp_parr[i].setAge(player_list[i].getAge());
            temp_parr[i].setGoalNumber(player_list[i].getGoalNumber());
            temp_parr[i].setAssistNumber(player_list[i].getAssistNumber());
            temp_parr[i].setMatchNumber(player_list[i].getMatchNumber());
        }

        temp_parr[current_size].setName(name);
        temp_parr[current_size].setNumber(number);
        temp_parr[current_size].setAge(age);
        temp_parr[current_size].setGoalNumber(goals);
        temp_parr[current_size].setAssistNumber(assists);
        temp_parr[current_size].setMatchNumber(matches);
        
        current_size++;


        player_list = temp_parr;

        temp_parr = NULL;
        delete[] temp_parr;

    }

    else{
        player_list[current_size].setName(name);
        player_list[current_size].setNumber(number);
        player_list[current_size].setAge(age);
        player_list[current_size].setGoalNumber(goals);
        player_list[current_size].setAssistNumber(assists);
        player_list[current_size].setMatchNumber(matches);
        
        current_size++;
    }


    return;
};

bool Team::checkNumber(int number)
{
    for (int i = 0; i < current_size; i++)
    {
        if (player_list[i].getNumber() == number)
            return true;
    }
    return false;
}
void Team::removePlayer(int number)
{
    //Fill this method
    current_size--;
    if(capacity/current_size > 2 || capacity/current_size == 2){
        capacity = capacity/2;
        if(current_size == 0 || current_size == 1){
            capacity = capacity * 2;
        }
    }
    Player *temp_parr = new Player[capacity];

    int j = 0;

    for (int i = 0; i < current_size; i++){
            if(number == player_list[i].getNumber()){
                break;
            }
            temp_parr[i].setName(player_list[i].getName());
            temp_parr[i].setNumber(player_list[i].getNumber());
            temp_parr[i].setAge(player_list[i].getAge());
            temp_parr[i].setGoalNumber(player_list[i].getGoalNumber());
            temp_parr[i].setAssistNumber(player_list[i].getAssistNumber());
            temp_parr[i].setMatchNumber(player_list[i].getMatchNumber());
            j++;
    }
    for (int i = j; i < current_size; i++){
            temp_parr[i].setName(player_list[i+1].getName());
            temp_parr[i].setNumber(player_list[i+1].getNumber());
            temp_parr[i].setAge(player_list[i+1].getAge());
            temp_parr[i].setGoalNumber(player_list[i+1].getGoalNumber());
            temp_parr[i].setAssistNumber(player_list[i+1].getAssistNumber());
            temp_parr[i].setMatchNumber(player_list[i+1].getMatchNumber());
            j++;
    }
    player_list = temp_parr;

    temp_parr = NULL;
    delete[] temp_parr;
    return;
};