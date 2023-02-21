#include "game.hpp"

// Contstructor
game::game(string new_homeName, string new_awayName, int new_homeScore, int new_awayScore) {
        homeName = new_homeName;
        awayName = new_awayName;
        homeScore = new_homeScore;
        awayScore = new_awayScore;
}

// Getters
string game::getHomeName() {
    return homeName;
}

string game::getAwayName() {
    return awayName;
}

int game::getHomeScore() {
    return homeScore;
}

int game::getAwayScore() {
    return awayScore;
}


// Setters
void game::setHomeName(string new_homeName) {
    homeName = new_homeName;
}

void game::setAwayName(string new_awayName) {
    awayName = new_awayName;
}

void game::setHomeScore(int new_homeScore) {
    homeScore = new_homeScore;
}

void game::setAwayScore(int new_awayScore) {
    awayScore = new_awayScore;
}


game::~game() {
        
}