#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// In element vector element.first=profit and element.second=weight
void generate_inclusion_matrix(vector<pair<int, int>> elements, int knapsack, float x[]);

// comparator function to sort profitByWeight matrix in descending order of their <second pair>element
bool comparator_function(const pair<int, float> &a, const pair<int, float> &b);

// returns maxprofit calculated from elements vector and inclusion matrix x
float max_profit(vector<pair<int, int>> elements, float x[]);

// Main function
int main()
{
    // first element holds profitx and second element holds profit  in pair
    vector<pair<int, int>> elements{{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};

    // size of bag
    int knapsack{15};

    // x matrix contains info about the inclusion(fully/partial) of elements
    float x[elements.size()];

    // sets 0 at all indexes of x
    memset(x, 0, sizeof(x));

    // function calls
    generate_inclusion_matrix(elements, knapsack, x);

    cout << "Inclusion Matrix :\n";
    for (int i = 0; i < elements.size(); i++)
        cout << "x[" << i << "] = " << x[i] << '\n';
    cout << "\n";

    cout << "Maximum profit :" << max_profit(elements, x) << endl;

    return 0;
}

float max_profit(vector<pair<int, int>> elements, float x[])
{
    float profit{0};
    int i = 0;
    for (auto element : elements)
        profit += element.first * x[i++];
    return profit;
}

void generate_inclusion_matrix(vector<pair<int, int>> elements, int knapsack, float x[])
{
    // first pair data contains index to element(to get weight after sorting)
    // seond one contains profitByWeight
    vector<pair<int, float>> profitByWeight;

    // get no of elements in vector
    int noOfElements = elements.size();

    // caculates profit/weight for each element
    for (int i = 0; i < noOfElements; i++)
    {
        profitByWeight.push_back(make_pair(i, elements[i].first / (elements[i].second * 1.0)));
    }

    // sort the profitByWeight array in descending order
    sort(profitByWeight.begin(), profitByWeight.end(), comparator_function);

    int i = 0;
    int index = profitByWeight[i].first;

    // calculate x matrix
    while (elements[index].second <= knapsack)
    {
        x[index] = 1;
        // cout<<"\nAt index "<<index+1<<" weight "<<element[index].second<<endl;
        knapsack -= elements[index].second;
        // cout<<"Knapsack size :"<<knapsack;
        i++;
        index = profitByWeight[i].first;
    }

    // if knapsack is not fully filled
    if (knapsack != 0)
    {
        x[index] = knapsack / (elements[index].second * 1.0);
    }
}

bool comparator_function(const pair<int, float> &a, const pair<int, float> &b)
{
    return (a.second > b.second);
}