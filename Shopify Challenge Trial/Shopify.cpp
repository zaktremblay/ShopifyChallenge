#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

static int itemCount = 0;

class Item{
    int a_itemIDNumber;
    std::string a_itemName;
public:
    Item();
    Item(const std::string & itemName);
    Item(const char * const & itemName);
    Item(const Item &);
    ~Item();
    void setItemName(const std::string & itemName);
    std::string getItemName() const;
    void setItemIDNumber(int itemIDNumber);
    int getItemIDNumber() const;
};

Item::Item() : a_itemName(){
    a_itemIDNumber = itemCount;
    a_itemName = "Item"+std::to_string(itemCount++);
}

Item::Item(const std::string & itemName): a_itemName(itemName), a_itemIDNumber(itemCount){
    itemCount++;
}

Item::Item(const char * const & itemName): a_itemName(itemName), a_itemIDNumber(itemCount){
    itemCount++;
}

Item::Item(const Item & otherItem): a_itemName(otherItem.getItemName()), a_itemIDNumber(otherItem.getItemIDNumber()){
    itemCount++;
}

Item::~Item(){
    itemCount--;
}

void Item::setItemName(const std::string & itemName){
    a_itemName=itemName;
}

std::string Item::getItemName() const{
    return a_itemName;
}

void Item::setItemIDNumber(int itemIDNumber){
    a_itemIDNumber=itemIDNumber;
}

int Item::getItemIDNumber() const{
    return a_itemIDNumber;
}

void saveToCSVFile(std::vector<Item> & inventory){
    std::ofstream myFile;
    myFile.open("inventory.csv");

    for(auto item : inventory){
        myFile << "Item name:" << item.getItemName() << ",ID:" << item.getItemIDNumber() << std::endl;
    }
}

void removeItemFromInventory(int itemIDNumber, std::vector<Item> & inventory){

    for (int i = 0; i < inventory.size(); i++){
        if(inventory[i].getItemIDNumber() == itemIDNumber){
            inventory.erase(inventory.begin()+i);
            break;
        }
    }
}

int main(){
    /*static std::vector<Item> inventory;
    inventory.reserve(50);
    std::string myString = "item in inventory2";
    inventory.insert(inventory.end(), Item(myString));
    std::cout << itemCount << std::endl;
    inventory.insert(inventory.end(), Item("this is a new item3"));
    std::cout << itemCount << "hi" << std::endl;
    removeItemFromInventory(1,inventory);
    
    saveToCSVFile(inventory);
    return 0;*/
    std::cout << "hi" << std::endl;
}
