// shop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const std::string datafilename = "data.txt";
const std::string check = "check.txt";

class PRODUCT {
    private:
        std::string name; //string?
        std::string manufacturer;
        int ID;
        int amount;
        double price;
    public:
        PRODUCT(std::string name_, std::string manu_, int id_, int amount_, double price_)
            :name(name_), manufacturer(manu_), ID(id_), amount(amount_), price(price_) {};
        void set_data(std::string name_, std::string manu_, int id_, int amount_, double price_);
            
        void print();
        void print2();
        void reduce_amount();
        void change_price();
};


/// <summary>
/// 
/// </summary>

class USER {
    private:
        std::string name;
        std::string surname;
        double budget;
        double start_money;
        double final_money;
        PRODUCT goods[50];
    public:
        int reduce_budget(double x);
        int get_user_info();
        int report(std::string filename);
};
USER user; 

/// <summary>
/// 
/// </summary>

class DATABASE {
private:
    PRODUCT* list; //list = new PRODUCT[x]
    int size;
public:
    DATABASE();
    int read_file(std::string filename);
    int search();
    PRODUCT search_by_name();
    PRODUCT search_by_manu();

};
int DATABASE::read_file(std::string filename) {
    //FILE* file1;
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        return 0;
    }

    int index;
    std::string name;
    std::string manufacturer;
    int amount;
    double price;
    

    int size;
    inputFile >> size;
    list = new PRODUCT[size];
    int i = 0;
    while (inputFile >> index >> name >> manufacturer >> amount >> price) {
        list[i].set_data();
        i++;
    }
}

int main()
{ 
    user.get_user_info();
    DATABASE database;
    database.read_file(datafilename);
    database.search();
    user.report(check);
    std::cout << "Thanks for coming to our e-shop!";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
