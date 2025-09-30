#include "draw_graphic.h"
namespace graphics{
            

    bool check_id(int iddd){
        bool checked = false;
        string iddd_str = to_string(iddd) + ".txt";
         for(const auto& entry : fs::directory_iterator(".")){
            if(entry.is_regular_file() && entry.path().filename() == iddd_str){
                
                ifstream Verification(entry.path());
                
                if(!Verification.is_open()){
        cerr<<"ERROR 0001"<<endl;
        return 1;
    }
            
                Verification>>c_name;
                Verification>>c_id;
                Verification>>c_age;
                Verification>>c_balance;
            Verification.close();
            checked = true;
    }

}
if(checked){
    return true;
}else{
    return false;
}
}
        void test(){
            cout<<c_name<<endl;
            cout<<c_balance<<endl;
            cout<<c_id<<endl;
        }
}