#include <vector>
#include <cassert>

#define MAX_RANDOM 100
#include "Utils.h"

using namespace std;

namespace lsahn
{

void SelectionSorting(vector<int>& array)
{
    for (int i = 0; i < array.size() - 1; ++i)
    {
        int index = i, min = array[i];

        for (int j = i + 1; j < array.size(); ++j)
        {
            if (array[j] < min)
            {
                index = j;
                min = array[j];
            }
        }

        lswap(array[i], array[index]);
    }
}

void SelectionSortingExample()
{
    cout << "+-------------------------------+" << endl;
    cout << "|   Selection Sorting Example   |" << endl;
    cout << "+-------------------------------+" << endl;

    vector<int> array;
    array.reserve(10);

    for (int i = 0; i < array.capacity(); i++)
    {
        array.push_back(RandomGen());
    }

    PrintVectorInt(array);
    SelectionSorting(array);
    PrintVectorInt(array);
}

} // lsahn