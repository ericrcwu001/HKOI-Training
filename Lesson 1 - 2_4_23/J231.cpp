#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int b, n, price = 0;
    string i, s, temp;
    cin >> b;
    cin >> i >> temp;
    if (temp == "Ice")
    {
        i += " " + temp;
        cin >> s;
    }
    else
    {
        s = temp;
    }
    cin >> n;
    set<string> top;
    for (int i = 0; i < n; ++i)
    {
        string topping;
        cin >> temp;
        topping += temp;
        if (i != n - 1)
        {
            while (temp[temp.length() - 1] != ',')
            {
                cin >> temp;
            }
            if (topping[topping.length() - 1] != ',')
                topping += ",";
        }

        if (i != n - 1)
            top.insert(topping.substr(0, topping.length() - 1));
        else
            top.insert(topping);
    }

    if (b < 4)
    {
        price += 15;
    }
    else if (b < 7)
    {
        price += 18;
    }
    else if (b < 9)
    {
        price += 20;
    }
    else
    {
        price += 30;
    }

    if (i == "Less Ice")
        price += 2;
    else if (i == "No Ice")
        price += 3;

    if (s == "50%")
        price += 1;
    else if (s == "30%")
        price += 2;
    else if (s == "0%")
        price += 4;

    for (auto &x : top)
    {
        if (x == "Pearl" || x == "Pudding")
            price += 4;
        else if (x == "Aloe" || x == "Agar")
            price += 5;
        else if (x == "Grass" || x == "Lychee" || x == "Coffee")
            price += 6;
        else if (x == "Red" || x == "Crystal")
            price += 7;
    }

    cout << price << "\n";
    return 0;
}