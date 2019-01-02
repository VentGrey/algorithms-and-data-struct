#include <bits/stdc++.h>
#include <iostream>

using namespace std;

ifstream f("data.in");
ofstream g("data.out");

int main_arr[100], n;

int main()
{
        f >> n;
        for (int i = 0; i <= n; i++) {
                int x;
                f >> x;
                ++main_arr[x];
        }
        if (main_arr[4] > 0) {
                g << "Aparece";
        } else {
                g << "No aparece";
        }

        return 0;
}