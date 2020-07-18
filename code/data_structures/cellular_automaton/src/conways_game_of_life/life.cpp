#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
// Defines the world size parameters
const int SIZE_X = 50;
const int SIZE_Y = 160;
// Number of random cells are filled
const int number = SIZE_X * SIZE_Y / 8;

void loadConfig(char world[][SIZE_Y]);
// Initializes world and loads up several default values

void generation(char world[][SIZE_Y], int& gen);
// Takes the world array and decides whether cells live, die, or multiply.

void copyGeneration(char world[][SIZE_Y], char worldCopy[][SIZE_Y]);
// Copies the current generation from world to worldCopy.

void updateGeneration(char world[][SIZE_Y], char worldCopy[][SIZE_Y]);
// Updates the current generation in worldCopy to world.

void display(const char world[][SIZE_Y], ofstream& fout, const int gen);
// Outputs the world as text.
// Records each successive world generation in a text file.

int getNeighbors(const char world[][SIZE_Y], int posX, int posY);
// Retrieves the amount of neighbors a cell has

int main()
{
    int gen(0);
    char world[SIZE_X][SIZE_Y];

    ofstream fout;
    fout.open("life.txt");
    if (fout.fail())
    {
        cout << "Opening file for output failed!\n";
        exit(1);
    }

    loadConfig(world);
    display(world, fout, gen);
    char c;
    cout << "\nPress return to create a new generation and press x to exit!\n";
    cin.get(c);
    do {
        generation(world, gen);
        display(world, fout, gen);
        cout << "\nPress return to create a new generation and press x to exit!\n";
        cin.get(c);
    } while (c == '\n');

    return 0;
}

void loadConfig(char world[][SIZE_Y])
{
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
            world[i][j] = '-';

    srand(time(NULL));

    for (int i = 0; i < number; i++)
    {
        int randX = rand() % SIZE_X;
        int randY = rand() % SIZE_Y;
        world[randX][randY] = '*';
    }
}

int getNeighbors(const char world[][SIZE_Y], int posX, int posY)
{
    int neighbors(0);

    int row = posX - 1, column = posY - 1;
    // Top-left
    if (column >= 0 && row >= 0)
        if (world[row][column] == '*')
            neighbors++;
    // Top-middle
    column++;
    if (row >= 0)
        if (world[row][column] == '*')
            neighbors++;
    // Top-right
    column++;
    if (column < SIZE_Y && row >= 0)
        if (world[row][column] == '*')
            neighbors++;

    row = posX, column = posY;     // Reset

    // Left
    column--;
    if (column >= 0)
        if (world[row][column] == '*')
            neighbors++;

    // Right
    column = posY + 1;
    if (column < SIZE_Y)
        if (world[row][column] == '*')
            neighbors++;

    row = posX + 1, column = posY - 1;     // Reset

    // Bottom-left
    if (row < SIZE_X && column >= 0)
        if (world[row][column] == '*')
            neighbors++;
    column++;
    if (row < SIZE_X)
        if (world[row][column] == '*')
            neighbors++;
    column++;
    if (row < SIZE_X && column < SIZE_Y)
        if (world[row][column] == '*')
            neighbors++;

    return neighbors;
}

void generation(char world[][SIZE_Y], int& gen)
{
    char worldCopy[SIZE_X][SIZE_Y];
    copyGeneration(world, worldCopy);
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {
            int neighbors = getNeighbors(world, i, j);
            if (neighbors <= 1 || neighbors > 3)
                worldCopy[i][j] = '-';
            else if (neighbors == 3 && worldCopy[i][j] == '-')
                worldCopy[i][j] = '*';
        }
    updateGeneration(world, worldCopy);
    gen++;
}

void copyGeneration(char world[][SIZE_Y], char worldCopy[][SIZE_Y])
{
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
            worldCopy[i][j] = world[i][j];

}

void updateGeneration(char world[][SIZE_Y], char worldCopy[][SIZE_Y])
{
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
            world[i][j] = worldCopy[i][j];

}

void display(const char world[][SIZE_Y], ofstream& fout, const int gen)
{
    cout << "Generation " << gen << endl;
    fout << 'G' << ' ' << gen << '\n';
    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            char cell = world[i][j];
            cout << cell;
            fout << cell;
        }
        cout << endl;
        fout << '\n';
    }
    cout << endl;
    fout << '\n';
}
