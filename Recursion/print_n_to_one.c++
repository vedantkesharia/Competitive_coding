#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std; 
void print_n_to_one(int n) {
if(n>0){
    cout<<n<<"\n";
}
n--;
print_n_to_one(n);

}

int main(){
    int n=5;
    print_n_to_one(n);
}