#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class finance{
    private:
    int balance = 0;
    string owner_name;
    int owner_id;
    vector<int> data;
    static vector<int> clients_id;
    
    public:
    
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
            double wastes = 0;
            wastes = (double)data[i] / tool;
            if(data[i] / 100 >= 0){
            cout<<"for: "<<data[i]<<"\t";
            string graph = draw_percent(wastes);
            cout<<graph<<endl;
            continue;
        } if(data[i] / 10 >= 0) {
            cout<<"for: "<<data[i]<<" \t";
            string graph = draw_percent(wastes);
            cout<<graph<<endl;
            continue;
        }else{
            continue;
            cout<<"for: "<<data[i]<<"  \t";
            string graph = draw_percent(wastes);
            cout<<graph<<endl;
        }

        }
    }
    string draw_percent(double wastes) {
    string result;
    int count = (int)(wastes / 2);
    for(int i = 0; i < count; i++) {
        result += "#";
    }
    return result;
}
    void show_sum(){
        cout<<balance<<endl;
    }
};


int main(){
    srand(time(NULL));
    finance objA;
    objA.calculate_procent();
    objA.show_sum();
    return 0;
}