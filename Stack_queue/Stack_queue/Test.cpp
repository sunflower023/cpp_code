#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void main()

{

    queue<char> Q;

    char x, y;

    x = 'n'; y = 'g';

    Q.push(x); Q.push('i'); Q.push(y);

    Q.pop(); Q.push('r'); Q.push('t'); Q.push(x);

    Q.pop(); Q.push('s');

    while (!Q.empty())

    {

        x = Q.front();

        Q.pop();

        cout << x;

    };

    cout << y;

}