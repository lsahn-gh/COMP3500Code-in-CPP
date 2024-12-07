#pragma once

#include <iostream>
#include <random>
#include <vector>

using namespace std;

#ifndef MAX_RANDOM
#define MAX_RANDOM 100
#endif


static inline int RandomGen()
{
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> distrib(1, MAX_RANDOM);
    return distrib(gen);
}

static inline void lswap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

static inline void PrintVectorInt(vector<int>& array)
{
    cout << "array >> ";
    for (int elem : array)
    {
        cout << elem << " ";
    }
    cout << endl;
}
