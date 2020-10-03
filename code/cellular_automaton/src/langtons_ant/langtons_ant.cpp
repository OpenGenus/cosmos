#include <iostream>
#include <vector>
#include <array>

using std::cout;
using std::cin;
using std::vector;
using std::array;

class Direction
{
public:
    int x;
    int y;
    const static Direction north;
    const static Direction east;
    const static Direction south;
    const static Direction west;
    const static array<Direction, 4> directions;

private:
    int i;

private:
    Direction(int x_, int y_, int i_)
    {
        x = x_;
        y = y_;
        i = i_;
    };
public:
    Direction() : Direction(north)
    {
    };

    Direction right() const
    {
        return directions.at((this->i + 1) % 4);
    }

    Direction left() const
    {
        return directions.at((this->i + 3) % 4);
    }
};

const Direction Direction::north{0, 1, 0};
const Direction Direction::east{1, 0, 1};
const Direction Direction::south{0, -1, 2};
const Direction Direction::west{-1, 0, 3};

const array<Direction, 4> Direction::directions({
    north, east, south, west,
});

class LangtonAnt
{
private:
    vector<vector<unsigned char>> board;
    int ant_x;
    int ant_y;
    int width;
    int height;
    Direction direction;

public:
    LangtonAnt(int width_, int height_)
    {
        board.assign(width_, vector<unsigned char>(height_, 0));
        width = width_;
        height = height_;
        ant_x = width / 2;
        ant_y = height / 2;
    }

    void show()
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
                cout << (board[j][i] ? '#' : ' ');
            cout << '\n';
        }
    }

    void step()
    {
        if (board[ant_x][ant_y])
        {
            board[ant_x][ant_y] = 0;
            direction = direction.left();
        }
        else
        {
            board[ant_x][ant_y] = 1;
            direction = direction.right();
        }
        ant_x = (ant_x + direction.x + width) % width;
        ant_y = (ant_y + direction.y + height) % height;
    }
};

int main()
{
    const int width = 100;
    const int height = 50;

    const int max_step = 10000;

    LangtonAnt langtonAnt(width, height);

    for (int step = 0; step <= max_step; ++step)
    {
        cout << "Step " << step << '\n';
        langtonAnt.show();
        cin.get();
        langtonAnt.step();
    }
}
