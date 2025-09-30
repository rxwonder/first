#include "register.h"
Register::Register(string a,string file,int b, int c, int e) : name(a),ID(b),age(c),balance(e){
    ofstream data(file);
    if(!data.is_open()){
        cerr<<"ERROR 0001"<<endl;
        return;
    }
    data<<name<<endl<<ID<<endl<<age<<endl<<balance;
    data.close();
    cout<<"congratilations"<<endl;
}
Register::~Register(){
    cout<<"Bye"<<endl;
}
