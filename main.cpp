#include <iostream>
using namespace std;
class smartArray{
    private:
    int* Array = new int[size];
    for(int i = 0; i<size; i++){
        Array[i] = -1;
    }
    public:
    int size;
        void Addvalue(int value, int index){
            if(index>=0 && index<size){
            if(Array[index] != -1){
                Array[index] == value;
            }
        }  
        
        int getvalue(int index){
            if(index < size && index >= 0){
            if(Array[index] != -1){
                return Array[index];    
        }
    }
}
        void printArray(){
            for(int i = 0; i < size; i++){
                cout<<Array[i];
            }
        }
};
int main(){
    int size;
    smartArray obj;
    cin>>size;
    smartArray.size = size;
    smartArray.printArray();
    for(int i = 0; i < size; i++){
        smartArray.Addvalue(12,i);
    }
    smartArray.getvalue(5);
    smartArray.printArray();
    return 0;
}