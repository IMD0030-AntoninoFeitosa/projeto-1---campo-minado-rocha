#ifndef SWEEPER_H
#define SWEEPER_H

#include <array>
#include <iostream>
#include <string>
#include <vector>

enum class Difficulty { beginner, intermediary, advanced };


struct Cell {
  bool is_hidden {true};
  bool has_bomb {false};

  bool has_redFlag {false};
  int near_bombs;
  
};

struct DifficultyRules {
  int MapSize_X ;
  int MapSize_Y ;
  int Bombs_N;
  int Rule = 0;
};

struct Record {
  std::string name;
  int milliseconds;
};


using Map = std::array<std::array<Cell,31>,31>;

using ListRecords = std::array<Record,10>;

void create_map(Map &map, DifficultyRules &rules);

void show_map(Map &map, DifficultyRules &rules);

int is_winner(Map &map, DifficultyRules &rules);

void near_bombs_map(Map &map, DifficultyRules &rules);

void adjacent_reveal(Map &map, DifficultyRules &rules, int posX,int posY);

void check_rules(Map &map, DifficultyRules &rules, int posX,int posY);

int act1_change_map(Map &map, DifficultyRules &rules, int posX,int posY,bool IsFirstAction);

void act2_red_flag(Map &map, DifficultyRules &rules, int posX,int posY);


#endif