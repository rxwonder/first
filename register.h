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

class Register {
public:
    string name;
    int ID;
    int balance;
    int age;
    
    // Конструктор - исправлены имена параметров
    Register(string name, string filename, int id, int age, int balance);
    
    void Fill_in(){}
    ~Register();
};