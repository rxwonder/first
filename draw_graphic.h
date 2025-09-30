#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
namespace graphics {
        inline string o_name,c_name;
        inline int o_id,c_id;
        inline int o_age,c_age;
        inline static int o_balance,c_balance;
        bool check_id(int iddd);
        void test();
        
        }

