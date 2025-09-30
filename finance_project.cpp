#include "register.h"
#include "draw_graphic.h"
using namespace std;
int current_id;
int current_balance;
int current_age;
string current_name;
int final_choice = 0;
void choice_1(){

    system("cls");
        cout<<"\t\t\t"<<"Your current balance:"<<current_balance<<endl;
        cout<<"\n\n"<<"[1]:Make expense"<<"\t\t"<<"[2]:delete expense\t\t"<<"[3]:clear all\n\t\t\t\t[0]:exit:";
        int choice;
        cin>>choice;
        system("cls");
        int choice_balance;
        cout<<"\t\t\tinput ur value:";
        
        vector<vector<string>> expenses;
        int choiceee = 1;
        int i = 0;
        while(choiceee == 1){
            string expense_name;
            cout<<"Write the name of ur expense:";
            cin>>expense_name;
            input_amount:
            cout<<endl<<"write the amount:";
            
            int amounts;
            cin>>amounts;
            
            int tool;
            if(amounts / 100 >= 10){
                tool = amounts / 100;
            }
            else if(amounts / 10 >= 10){
                tool = amounts / 10;
            }
            else if(amounts <= 0){
                system("cls");
                cout<<"Wrong output!"<<endl;
                goto input_amount;

            }else{
                tool = amounts;
            }

            for(i < i+1; i++;){
                expenses[i][0] = expense_name;
                for(int j = 0; j < amounts; j++){
                expenses[i][j] = '#';
                }
            }
            i++;
            cout<<"\none expense added!\nselect option:\n[1]:add one more expense\n[2]:select expense to delete\n[3]:clear all\n[0]exit:";
            cin>>choiceee;
        }
        
        
        system("cls");
        
}
int main(){
    srand(time(NULL));
    begging:
    cout << "1.register \t 2.login\n";
    int choice;
    cin >> choice;
    start:
    if(choice == 1){
        cout << "\tEnter ur data \n1.ur name\n2.ur age\n3.Enter ur balance\n";
        
        // НЕ используй указатели для простого ввода!
        string start_name;
        int start_age;
        int start_balance;
        
        cin >> start_name >> start_age >> start_balance;
        current_age = start_age;
        current_balance = start_balance;
        current_name = start_name;
        system("cls");
        cout << "is this correct \nur name:" << start_name << "\nur age:" << start_age << "\nur start-balance:" << start_balance << "\n1.yes\n2.no\n";
        
        int choice2;
        cin >> choice2;
        
        if(choice2 == 1){
            int unique_id = rand() % 9000 + 1000; // Правильная генерация ID 1000-9999
            current_id = unique_id;
            cout << "ur data saved :) ID: " << unique_id << endl;
            string test = to_string(unique_id) + ".txt";
            Register obj1(start_name,test,unique_id,start_age,start_balance);
            final_choice = 1;
        }
        if(choice2 == 2){
            goto start;
            cout<<"try again\n";
            system("cls");
        }
    }





//login

    if(choice == 2){
        start2:
        cout<<"Enter ur id:";
        int unique_id;
        cin>>unique_id;
        current_id = unique_id;
        string id = to_string(unique_id) + ".txt";
    
        bool id_found = false;
        for(const auto& entry : fs::directory_iterator(".")){
            if(entry.is_regular_file() && entry.path().filename() == id){
                cout<<"last verification...\tType ur name!:";
                ifstream Verification(entry.path());
 
                if(!Verification.is_open()){
        cerr<<"ERROR 0001"<<endl;
        return 1;
    }
                string check;
                Verification>>check;
            
                string verification;
                cin>>verification;
                if(verification == check){
                    system("cls");
                    cout<<"\tcongratulations!\nu loged in succesfully!\n";
                    id_found = true;
                    final_choice = 2;
                    current_name = check;
                    Verification>>current_id;
                    Verification>>current_age;
                    Verification>>current_balance;
                    Verification.close();     
                }else{
                    system("cls");
                    cout<<"Error0002!\n";
                    return 1;
                }
            }
        }
        if(!id_found){
            system("cls");
            cout<<"ID must be incorrect\n";
            goto start2;
        }
    }
    
    
















    system("cls");
    if(final_choice == 1){
        string text = "__";
        string abu = to_string(current_balance);
        for(int i = 0; i < abu.size(); i++){
                text += '#';
                text += '#';
                text += '#';
                text += '#';
                text += '#';
                text += '#';
                
        
        }
        text += "__";
        cout<<"\t\t\t\t"<<text<<"\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t"<<"Your current balance:"<<"\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t\t"<<current_balance<<"\t\t\t\t"<<endl;
        cout<<"\t\t\t\t"<<text<<"\t\t\t\t"<<endl;
        cout<<endl;
        cout<<"[1]:Make month-expenses\t\t[2]:transfer money\t\t[0]:exit\n";
        int choice;
        cin>>choice;
        if(choice == 1){
            choice_1();
        }
    }
}