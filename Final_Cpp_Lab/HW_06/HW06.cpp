#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;
class Team {
public:
  int ID;
  int GD;  // Goal Difference = Goal score - Goal conced
  int PTS; // Point (win = 3, draw = 1, lose = 0)

  // Constructor
  Team(int x, int y, int z) : ID(x), GD(y), PTS(z) {}
};

class Scoreboard {
public:
    vector<Team> T;
    int numberOfTeams;
    
    Scoreboard(int n){
        numberOfTeams = n;
        for(int i=0;i<n;i++){
            Team x(i,0,0);
            T.push_back(x);
        }
    }

  void match(int ID1, int ID2, int G1, int G2) {
    int GD1 = G2 - G1;
    int GD2 = G1 - G2;

    int Temp1, Temp2;
    for (int i = 0 ; i < numberOfTeams; i ++) {
      if (T[i].ID == ID1) {
       Temp1 = i;
      }if (T[i].ID == ID2) {
       Temp2 = i;
      }
    }
    if (G1 > G2) {
      T[Temp1].PTS += 3;
      T[Temp1].GD += GD2;
      T[Temp2].GD += GD1;
    } else if (G1 < G2) {
      T[Temp2].PTS += 3;
      T[Temp2].GD += GD1;
      T[Temp1].GD += GD2;
    } else {
      T[Temp1].PTS += 1;
      T[Temp2].PTS += 1;
    }

    sorted();
  }
  void showTeamAtRank(int i) {
    i--;
    cout << T[i].ID << " ";
    cout << T[i].PTS << " ";
    cout << T[i].GD << endl;
  }

  void sorted() {
    for (int i = (numberOfTeams - 1); i >= 0; i --) {
      for (int j = 1; j <= i; j ++) {
        
        if (T[j - 1].PTS < T[j].PTS) {

          Team temp(T[j - 1].ID, T[j - 1].GD, T[j - 1].PTS);
          T[j - 1] = T[j];
          T[j] = temp;

        }else if (T[j - 1].PTS == T[j].PTS) {

          if (T[j - 1].GD < T[j].GD) {
            Team temp(T[j - 1].ID, T[j - 1].GD, T[j - 1].PTS);
            T[j - 1] = T[j];
            T[j] = temp; 

          } else if ( T[j-1].GD == T[j].GD && (T[j-1].ID > T[j].ID)) {
              Team temp(T[j - 1].ID, T[j - 1].GD, T[j - 1].PTS);
              T[j - 1] = T[j];
              T[j] = temp;  
          }
        }
      }
    }
  }
};
