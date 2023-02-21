#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class game{
    private:
        string homeName, awayName;
        int homeScore, awayScore;

    public:
        game(string new_homeName, string new_awayName, int new_homeScore, int new_awayScore);

        string getHomeName();
        string getAwayName();
        int getHomeScore();
        int getAwayScore();

        void setHomeName(string new_homeName);
        void setAwayName(string new_awayName);
        void setHomeScore(int new_homeScore);
        void setAwayScore(int new_awayScore);

        ~game();

};