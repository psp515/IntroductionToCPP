//
// Created by psp515 on 28.06.2023.
//

#include "Map.h"
#include <map>
#include <unordered_map>
#include <iostream>
#include <utility>
#include <random>
using namespace std;

Map::Map(int x, int y, string alive_icon, string dead_icon)
{
    this->x = x;
    this->y = y;
    this->alive = 0;

    this->alive_icon = std::move(alive_icon);
    this->dead_icon = std::move(dead_icon);

    srand((unsigned) time(NULL));

    for(int i=0; i < x; i++)
        for(int j = 0; j < y; j++)
        {
            int value = rand() % 2;

            if(value == 1)
            {
                map.insert(make_pair(get_hash(i, j), true));
                alive++;
            }
            else
                map.insert(make_pair(get_hash(i, j), false));
        }
}

string Map::get_hash(int i, int j)
{
    return to_string(i) + to_string(j);
}

bool Map::state(int current_x, int current_y)
{
    int neighbours = count_neighbours(current_x, current_y);
    string hash = get_hash(current_x, current_y);
    bool value = map.at(hash);

    if (value && (neighbours == 2 || neighbours == 3))
        return true;

    if (!value && neighbours == 3)
        return true;

    return false;
}

int Map::count_neighbours(int current_x, int current_y)
{
    int count = 0;

    for (int i = current_x - 1; i <= current_x + 1; i++)
        for (int j = current_y - 1; j <= current_y + 1; j++) {
            if ((i == current_x && j == current_y) || (i < 0 || j < 0)
                || (i >= this->x || j >= this->y))
                continue;


            if (this->map[get_hash(i, j)])
                count++;

        }

    return count;
}

void Map::update_map()
{
    unordered_map<string, bool> nextState;
    int new_alive = 0;

    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
        {
            bool value = state(i, j);
            if (value)
                new_alive++;

            nextState[get_hash(i, j)] = value;
        }

    alive = new_alive;
    map = nextState;
}

void Map::print_map() const
{
    print_line();
    for (int i = 0; i < x; i++) {
        cout << ":";
        for (int j = 0; j < y; j++)
        {
            string icon = get_icon(i, j);
            cout << "  " << icon << "  :";
        }

        print_line();
    }
}

int Map::get_alive() const {
    return alive;
}

void Map::print_line() const
{
    cout << endl;
    for (int i = 0; i < y; i++)
    {
        cout << " -----";
    }
    cout << endl;
}

string Map::get_icon(int i, int j) const {
    string hash = get_hash(i, j);
    bool value = map.at(hash);
    if (value)
        return this->alive_icon;

    return this->dead_icon;
}
