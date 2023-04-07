//
// Created by psp515 on 05/04/2023.
//

#ifndef ZAD5MYLISTANDSORTING_MYSORTING_H
#define ZAD5MYLISTANDSORTING_MYSORTING_H

#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>

template <typename T=int, int size>
void mySort(T (&array)[size])
{
    if(size < 2)
        return;

    int swaps = 1;

    while (swaps > 0)
    {
        swaps = 0;

        for(int i=1; i < size; i++)
            if (array[i-1] > array[i])
            {
                std::swap(array[i-1], array[i]);
                swaps++;
            }
    }
}

template <typename T>
void mySort(T &list)
{
    if(list.size() < 2)
        return;

    std::vector<typename std::iterator_traits<std::iterator<std::forward_iterator_tag, int>>::value_type> temp(list.begin(), list.end());
    std::sort(temp.begin(), temp.end());
    std::copy(temp.begin(), temp.end(), list.begin());
}




template <int size1, int size2>
void mySort(char (&array)[size1][size2])
{
    if(size1 < 2)
        return;

    char tmp[size2+2];

    for (int i = 0; i < size1; i++)
    {
        int swaps = 0;
        for (int j = 1; j < size1; j++)
        {
            for(int k = 0; k < size2; k++)
            {
                char a = toupper(array[j-1][k]);
                char b = toupper(array[j][k]);

                if (a > b)
                {
                    strcpy(tmp, array[j-1]);
                    strcpy(array[j-1], array[j]);
                    strcpy(array[j], tmp);
                    swaps++;
                    break;
                }
                else if(a != b)
                    break;

            }
        }

        if (swaps == 0)
            break;

    }
}


#endif //ZAD5MYLISTANDSORTING_MYSORTING_H
