#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

#define ll long long
#define pb push_back
#define fl(i, n, m)		for(int i=n; i<m; i++)
#define INT_INF 2000000000
#define LL_INF 3000000000000000000

class AllWoundUp
{
typedef struct 
{
  int dir[4];
}pntDescriptor;

public:

  int calSlope(int w, int x, int y, int z)
  {

  int maxWind(vector<int> x, vector<int> y)
  {
    int n;
    n = x.size();
    if(n == 0)
      return 0;

    int startX, startY;
    pntDescriptor numLine[2001];
    for(int i=0; i<=2000; i++)
      numLine[i].dir[0] = numLine[i].dir[1] = numLine[i].dir[2] = numLine[i].dir[3] = 0;

    for(int i=1; i<n; i++)
      {
	int m = calSlope(x[i-1], x[i], y[i-1], y[i]);
  }
