#include <iostream>
#include <string>
#include <vector>
#include "live/Map.h"

using namespace std;

int main(int argc, char *argv[])
{
    int print_only_extremes = 0;

    if(argc != 4 && argc != 5)
    {
        cout << "Program receives arguments: x-size y-size generations print_only_extremes(optional 0 or 1)" << endl;
        return 1;
    }

    cout << "Program starting!" << endl << endl;

    int generations = stoi(argv[3]);
    if(argc == 5)
        print_only_extremes = stoi(argv[4]);


    Map* live_map = new Map(stoi(argv[1]), stoi(argv[2]));

    int max_occupied = live_map->get_alive(),
    min_occupied = live_map->get_alive(),
    total = live_map->get_alive(),
    starting = live_map->get_alive();

    cout << "Starting generation (1)";
    live_map->print_map();
    cout << endl;

    for(int i = 1; i < generations; i++)
    {
        live_map->update_map();

        int alive = live_map->get_alive();

        total += alive;
        max_occupied = max(max_occupied, alive);
        min_occupied = min(min_occupied, alive);

        if(alive == 0)
        {
            cout << "Dead Generation (" << generations <<")";
            live_map->print_map();
            cout << endl;

            cout << "Live has ended :(" << endl << endl;

            break;
        }

        if(i == generations-1)
        {
            cout << "Final Generation (" << generations <<")";
            live_map->print_map();
            cout << endl;
        }
        else if(print_only_extremes == 0)
        {
            cout << "New Generation (" << i+1 << ")";
            live_map->print_map();
            cout << endl;
        }
    }

    double avg = static_cast<double>(total) / (generations);

    cout << "----- Stats -----" << endl;
    cout << "Starting: " << starting << endl;
    cout << "Ending: " << live_map->get_alive() << endl;
    cout << "Average: " << avg  << endl;
    cout << "Max: " << max_occupied  << endl;
    cout << "Min: " << min_occupied  << endl;
    cout << "Total lives: " << total  << endl << endl;

    cout << "Program finished!" << endl;

    return 0;
}