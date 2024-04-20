#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

const int ROWS = 20;
const int COLUMNS = 20;
const char ANT_NAME = 'o';
const char DOODLEBUG_NAME = 'x';

struct Location{
    int xValue;
    int yValue;
};
// object for the coordinates on the world map we're making

class World;

class Organism{
    public:
    Organism(Location local, int lifespan, char name);
    Organism(Location local, char name);
    Organism(Location local);
    Organism();
    Location get_location() const;
    char get_name();
    int get_lifespan();
    void new_location(Location newLoc);
    void i_lived_bitch();
    int random_selector(int options);
    virtual Location move(World& board);
    virtual Location breed(World& board);
    friend ostream& operator <<(ostream& outs, const Organism& organism);
    private:
    Location location;
    int lifespan;
    char name; 
    
};

class Ant:public Organism{
    public:
    Ant(Location spawn, int lifespan);
    Ant(Location spawn);
    virtual Location move(World& board) override;
    virtual Location breed(World& board) override;
    private:
};

class Doodlebug:public Organism{
    public:
    Doodlebug(Location spawn, int lifespan);
    Doodlebug(Location spawn);
    Doodlebug();
    virtual Location move(World& board) override;
    virtual Location breed(World& board) override;
    bool ant_hunt(World& board);
    void death(World& board);
    private:
    int hunger;
};

class World{
    public:
    World();
    bool is_open_space(const Location& position);
    vector<Location> available_adj_cells(const Location& curr_pos);
    vector<Location> adjacent_ants(const Location& curr_pos);
    char get_content(Organism organism);
    void write_content(Location position, Organism& organism);
    void write_content(Location position, char dude);
 //   void swap(Location current_local, Location new_local);
    void execution(Organism& victim);
    void execution(Location& target);
    void print(ostream& outs) const;
    void initial_spawn_doodle(int population);
    void initial_spawn_ants(int population);
    void simulate_time();
    private:
    vector<vector<Organism>> board;
};

int main( )
{
    srand(time(0));
    World board;

    board.initial_spawn_ants(100);
    board.initial_spawn_doodle(5);

    board.print(cout);
    
    cout << endl << "this is our initial board." << endl;

            cout << "press enter to continue";
        cin.get();
        board.simulate_time();
        board.print(cout);

   /* while (true)
    {
        cout << "press enter to continue";
        cin.get();
        board.simulate_time();
        board.print(cout);
    }*/
    return 0;
}
Organism::Organism(Location local, int lifespan, char name):location(local), name(name), lifespan(lifespan){}
Organism::Organism(Location local, char name):location(local), name(name), lifespan(0){

}

Organism::Organism(Location local):location(local), lifespan(0), name('-') {}

Organism::Organism():location(), lifespan(0), name('-') {} 

Location Organism::get_location() const
{
return location;
}

char Organism::get_name()
{
    return name;
}

int Organism::get_lifespan()
{
    return lifespan;
}

void Organism::new_location(Location newLoc){
    location = newLoc;
    return;
}

void Organism::i_lived_bitch()
{
    lifespan++;
}

int Organism::random_selector(int options)
{

    if (options == 1)
        return 0;
    else
        {int answer = rand() % (options);
        return answer;}
}

ostream& operator <<(ostream& outs, const Organism& organism) {
    outs << organism.name;
    return outs;
}

Location Organism::move(World& board) {return{22, 22};}
Location Organism::breed(World& board) {return{22, 22};}

Ant::Ant(Location spawn, int lifespan):Organism(spawn, lifespan, ANT_NAME) {}

Ant::Ant(Location spawn):Organism(spawn, ANT_NAME) {}

Location Ant::move(World& board)
{
    vector<Location> options = board.available_adj_cells(get_location());
    if (options.empty())
        return {22, 22};
    int direction = random_selector(options.size());
    Location next = options[direction];
    return next;
}

Location Ant::breed(World& board)
{
    if ((get_lifespan()%3) == 0)
    {
        vector<Location> options = board.available_adj_cells(get_location());
        if (options.size() < 1)
            return get_location();
        int direction = random_selector(options.size());
        Location next = options[direction];
        return next;
    }
    else
        return {22, 22};
}

Doodlebug::Doodlebug(Location spawn, int lifespan):Organism(spawn, lifespan, DOODLEBUG_NAME), hunger(0) {}

Doodlebug::Doodlebug(Location spawn):Organism(spawn, DOODLEBUG_NAME), hunger(0) {}

Doodlebug::Doodlebug():Organism(), hunger(0) {}

bool Doodlebug::ant_hunt(World& board)
{
    vector<Location> options = board.adjacent_ants(get_location());
    if (options.size() < 1){
        return false;
       }
    int direction = random_selector(options.size());
    Location current = this->get_location();
    board.execution(current);
    board.write_content(options[direction], 'x');
    return true;
}

Location Doodlebug::move (World& board)
{
    vector<Location> options = board.available_adj_cells(get_location());
    if (options.empty())
        return {22, 22};
    int direction = random_selector(options.size());
    Location next = options[direction]; 
    return next;
}

Location Doodlebug::breed(World& board)
{
    if (get_lifespan() % 8 == 0)
    {
        vector<Location> options = board.available_adj_cells(get_location());
        if (options.size() < 1)
            return get_location();
        int direction = random_selector(options.size());
        Location next = options[direction]; 
        return next;
    }
    else
        return {22, 22};
}

void Doodlebug::death(World& board){ //needs fix
    Location here = get_location();
    if (hunger >= 3)
        board.execution(*this);
    else
        return;
}

World::World() : board(ROWS, vector<Organism>(COLUMNS))
{
    for (int i=0; i<ROWS; i++)
        for (int j = 0; j < COLUMNS; j++){
            Location spawn;
            Organism temp;
            spawn.xValue = i, spawn.yValue = j; 
            temp.new_location(spawn);
            board[i][j] = temp;
        }
}

bool World::is_open_space(const Location& position)
{
    if (position.xValue >= ROWS || position.xValue < 0 || position.yValue >= COLUMNS || position.yValue < 0)
        return false;
    else if (board[position.xValue][position.yValue].get_name() == '-')
    {
        return true;
    }
    else
        return false;
}

vector<Location> World::available_adj_cells(const Location& curr_pos)
{
    vector<Location> available_adj_cells;
    vector<Location> unvetted_list = {{curr_pos.xValue + 1, curr_pos.yValue}, {curr_pos.xValue, curr_pos.yValue + 1}, {curr_pos.xValue - 1, curr_pos.yValue}, {curr_pos.xValue, curr_pos.yValue-1}};
    for (Location local: unvetted_list){
        if (is_open_space(local)){
            available_adj_cells.push_back(local);
    }
    }
    return available_adj_cells;
}

vector<Location> World::adjacent_ants(const Location& curr_pos)
{
    vector<Location> available_adj_cells;
    vector<Location> unvetted_list = {{curr_pos.xValue + 1, curr_pos.yValue}, {curr_pos.xValue, curr_pos.yValue + 1}, {curr_pos.xValue - 1, curr_pos.yValue}, {curr_pos.xValue, curr_pos.yValue-1}};

    for (Location local: unvetted_list){
    {
            if (is_open_space(local))
            {
                if (board[local.yValue][local.xValue].get_name() == ANT_NAME)
                {
                available_adj_cells.push_back(local);
                }
            }
    }
    }

    return available_adj_cells;
}

char World::get_content(Organism organism)
{
    return organism.get_name();
}

void World::write_content(Location position, Organism& organism)
{
    Organism newlife(position, organism.get_name());
    board[position.xValue][position.yValue] = newlife;
    return;
}

void World::write_content(Location position, char dude)
{
    Organism newlife(position, dude);
    board[position.xValue][position.yValue] = newlife;
    return;
}

//void World::swap(Location current_local, Location new_local)
//{
   // board[new_local.xValue][new_local.yValue] = board[current_local.xValue][current_local.yValue];
  //  board[current_local.xValue][current_local.yValue] = Organism(current_local);
//}

void World::execution(Organism &victim)
{
    Location target = victim.get_location();
    Organism corpse(target);
    board[target.xValue][target.yValue] = corpse;
}

void World::execution(Location &target)
{
    Organism corpse(target);
    board[target.xValue][target.yValue] = corpse;
}

void World::initial_spawn_doodle(int population)
{

    while (population > 0){
    Location spawn;
    spawn.xValue = rand() % 20;
    spawn.yValue = rand() % 20;

    if (is_open_space(spawn)){
        Doodlebug newbug(spawn);
        board[spawn.xValue][spawn.yValue] = newbug;
        population--;
    }

    }
}

void World::initial_spawn_ants(int population)
{

    while (population > 0){
    Location spawn;
    spawn.xValue = rand() % 20;
    spawn.yValue = rand() % 20;

    if (is_open_space(spawn)){
        Ant newbug(spawn);
        board[spawn.xValue][spawn.yValue] = newbug;
        population--;
    }

    }
}


void World::print(ostream& outs) const {
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++){
            outs << board[i][j] << " ";
        }    
        outs << endl;
    }
}

void World::simulate_time() {
    vector<Doodlebug*>  doodles;
    vector<Ant*> ants;
    Location null = {22, 22};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j].get_name() == DOODLEBUG_NAME) {
                doodles.push_back(static_cast<Doodlebug*>(&board[i][j])); 
            }
            if (board[i][j].get_name() == ANT_NAME) {
                ants.push_back(static_cast<Ant*>(&board[i][j]));
            }            
        }
    }

    for (Ant* ant_ptr: ants) {
        cout << ant_ptr->move(*this).xValue;
        if (ant_ptr->move(*this).xValue != null.xValue)
            {write_content(ant_ptr->move(*this), 'o');
            cout<< "I work";
            }
        if (ant_ptr->breed(*this).xValue != null.xValue)
            write_content(ant_ptr->breed(*this), 'o');
    }

    for (Doodlebug* doodlebug_ptr: doodles) {
        if (doodlebug_ptr->move(*this).xValue != null.xValue)
            write_content(doodlebug_ptr->move(*this), 'o');
        if (doodlebug_ptr->move(*this).xValue != null.xValue)
            write_content(doodlebug_ptr->breed(*this), 'o');
    }
}

