#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std; 

int parameterised_sum(int n, int sum){
if(n<1){
    return sum;
}
sum+=n;
return parameterised_sum(n-1,sum);

}

int main(){
    int n=3;
    int sum=0;
    cout<<parameterised_sum(n,sum);
}