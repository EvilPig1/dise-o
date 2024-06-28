#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<int> gapCoding(const vector<int>& arr);
vector<int> createSample(const vector<int>& arr, int m);
int binarySearchGapCoded(const vector<int>& gc, const vector<int>& sample, int x);