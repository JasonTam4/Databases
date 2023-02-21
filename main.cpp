/*
Jason Tam
251171681
Individual assignment
*/

#include "main.hpp"

using namespace std;
using json = nlohmann::json;

int main(void) {
   vector<game> games;
   request r = request("https://statsapi.web.nhl.com/api/v1/schedule");
   r.execute();
   json apiData = json::parse(r.getResult());
   string homeName;
   string awayName;
   int homeScore;
   int awayScore;

   // Putting the json into the game vector
   for(int i=0; i<apiData["totalGames"]; i++) {
      for(int j = 0; j < apiData["dates"][i]["games"].size(); j++){
            homeName = apiData["dates"][i]["games"][j]["teams"]["home"]["team"]["name"];
            awayName = apiData["dates"][i]["games"][j]["teams"]["away"]["team"]["name"];
            homeScore = apiData["dates"][i]["games"][j]["teams"]["home"]["score"];
            awayScore = apiData["dates"][i]["games"][j]["teams"]["away"]["score"];
            game g = game(homeName, awayName, homeScore, awayScore);
            games.push_back(g);
        }
   }

   // Prints the data from the game vectors
   for(int i=0; i<games.size(); i++) {
      cout << games[i].getHomeName() << " vs. " << games[i].getAwayName() << ": " << games[i].getHomeScore() << " - " << games[i].getAwayScore() << endl;
   }
   

   return 0;
}