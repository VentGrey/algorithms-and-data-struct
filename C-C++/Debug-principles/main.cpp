#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int A[3][5]; //Global matrix

void print_row(int rows) 
{
        for(int i = 0; i < 5; i++) {
                cout <<A[rows][i]<<" ";
        }
        cout << "\n";
}

int main() 
{
        for(int i = 0; i < 3; i++) {
                print_row(i);
        }
}