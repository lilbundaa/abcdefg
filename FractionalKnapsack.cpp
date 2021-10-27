/* 
Q) You are given the following-

A knapsack (kind of shoulder bag) with limited weight capacity.
Few items each having some weight and value.
 
The problem states-

Which items should be placed into the knapsack such that-

The value or profit obtained by putting the items into the knapsack is maximum.
And the weight limit of the knapsack does not exceed. */

#include <iostream>
#include <algorithm>
using namespace std;

struct Details
{
    int price;
    int weight;
};
bool cmp(Details a,Details b)
{
    double unit1 = (double)a.price/(double)a.weight;
    double unit2 = (double)b.price/(double)b.weight;
    return unit1 > unit2;
}
double FractionalKnapsack(Details d[],int C,int n)
{
    sort(d,d+n,cmp);

    double maxprofit=0.0;
    for(int i=0;i<n;i++)
    {
        if(C>=d[i].weight)
        {
            C-=d[i].weight;
            maxprofit+=d[i].price;
        }
        else
        {
            int left=C;
            C=0;
            double cost = (double)d[i].price/(double)d[i].weight * left;
            maxprofit+=cost;
            break;
        }
    }
    return maxprofit;
}
int main()
{
    int W,n;
    cout<<"Enter the number of items ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the capacity of knapsack ";
    cin>>W;
    Details arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the price of Item-"<<i+1<<endl;
        cin>>arr[i].price;
        cout<<endl;
        cout<<"Enter the Weight of Item-"<<i+1<<endl;
        cin>>arr[i].weight;
        cout<<endl;
    }
    cout << "Maximum value we can obtain = "<< FractionalKnapsack(arr, W, n);

    return 0;
}
