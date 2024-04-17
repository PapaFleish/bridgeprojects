#include <iostream>
#include <cstdlib>
using namespace std;

class Board{
public:
    Board(int row, int column);
    Board();
    void initialize_ants(int population);
    void initialize_doodleBugs(int population);
    void boundary_check();
    void print_board();
private:
    char boardArray[];
    int row;
    int column;
}

class Location : public Board{
    public:
        Location(int row, int column);
        Location();
        void set_pop(Creature creature);
        char get_pop(Creature craeture);
        void swap_content(int row1, int column1, int row2, int column2);
        friend bool operator ==(const Location& localOne, const Location& localTwo);
    private:
         char content;
}

class Creature{
public:
    void move(Location& location1, Location& Location2);
    void breed(Location& currentLocation);
    bool breed_check(int lifeSpan);
    bool death_check(int lifeSpan);
    void day_in_the_life();
private:
    int lifeSpan;
    Location location;
}

