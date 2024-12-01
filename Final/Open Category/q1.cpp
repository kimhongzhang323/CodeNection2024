#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <unordered_set>
using namespace std;

int main(){

    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;

    int left, right;

    left = a-(b/c);
    right = (d/e)-f;

    if (left && right){
        cout<<"=";
    } else if (left> right){
        cout<<">";
    } else{
        cout<<"<";
    }

    return 0;
}