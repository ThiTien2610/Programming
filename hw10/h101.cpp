// Snake game

#include<iostream>
#include<vector>
// Builder pattern: How the snake is created
class Snake
{
public:
    int length;
};
class SnakeBuilder
{
private:
    Snake* snake;
public:
    SnakeBuilder(){ snake =new Snake();}
    void setLength(int l){ snake->length =l;}
    Snake* getsnake() { return snake;}
};
// Composite pattern: Organize game objects such as Food and Snake on the board
class GameObject
{
public:
    virtual void draw() =0;
};
class SnakeObject : public GameObject
{
public:
    void draw() override
    {
        std::cout<< "Draw snake\n";
    }
};
class FoodObject : public GameObject
{
public:
    void draw() override
    {
        std::cout<< "Draw food\n";
    }
};
class Board : public GameObject
{
    std::vector<GameObject*>objects;
public:
    void add(GameObject* obj)
    {
        objects.push_back(obj);
    }
    
    void draw() override
    {
        for ( auto o:objects) o->draw();
    }
};
// Template Method defines structure of game turn

class GameTurn
{
public:
    void playTurn()
    {
        start();
        middle();
        end();
    }
protected:
    virtual void start()
    {
        std::cout<< "Turn starts\n";
    }
    virtual void middle()=0;
    virtual void end()
    {
        std::cout << "Turn ends\n";
    }
};
class SnakeTurn: public GameTurn
{
protected:
    void middle() override
    {
        std::cout<<"Snake moves\n";
    }
};
int main()
{
    SnakeBuilder builder;
    builder.setLength(5);
    Snake* snake=builder.getsnake();

    std::cout<< "Snake length: "<< snake->length<<"\n";

    Board board;
    board.add(new SnakeObject());
    board.add(new FoodObject());

    board.draw();

    SnakeTurn turn;
    turn.playTurn();
    
    return 0;

}




