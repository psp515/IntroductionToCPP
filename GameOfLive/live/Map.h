//
// Created by psp515 on 28.06.2023.
//
#ifndef GAMEOFLIVE_MAP_H
#define GAMEOFLIVE_MAP_H

#include <string>
#include <unordered_map>
#include <tuple>

using namespace std;

class Map
{
    public:
        Map(int x, int y, string alive_icon = "1", string dead_icon = "0");
        void update_map();
        void print_map() const;
        int get_alive() const;

    private:
        bool state(int current_x, int current_y);
        int count_neighbours(int current_x, int current_y);
        void print_line() const;
        string get_icon(int i, int j) const;
        int x, y, alive;
        unordered_map<string, bool> map;
        static string get_hash(int i, int j);
        string dead_icon, alive_icon;
};


#endif //GAMEOFLIVE_MAP_H
