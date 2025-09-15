#include <vector>
#include <iostream>
#include <string>
using namespace std;
class finance{
    private:
    int balance = 0;
    vector<int> data;
    public:
    string option;
    void calculate_procent(){
        cout<<"How many operations?"<<endl;
        int size;
        cin>>size;
        for(int i = 0; i < size; i++){
            cout<<"enter the value"<<endl;
            int income;
            cin>>income;
            data.push_back(income);
        }
        
        for(int i = 0; i < size; i++){
            balance+=data[i];
        }
        int tool = balance / 100;
        for(int i = 0; i < size; i++){
            cout<<"for: "<<data[i]<<" "<<(double)data[i] / tool<<endl;

        }
    }
};
int main(){
    finance objA;
    objA.calculate_procent();
    return 0;
}