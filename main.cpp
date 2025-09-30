#include <iostream>
#include <string>
using namespace std;
int main(){
    int size;
    for(int i = 0; i < size; i++){
    string a;
    cin>>a;
    if(a.size() > 10){
        cout<<a[0]<<a.size() - 2<<a[a.size() - 1];
    }
    }
    return 0;
}