#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
    private:
        string name;
        int quantity;
        double price;

    public:
        Item();
        Item(const string &name, int quantity, double price);

        string getName() const;
        int getQuantity() const;
        double getPrice() const;

        void setName(const string &name);
        void setQuantity(int quantity);
        void setPrice(double price);

        void displayItem() const;
};

#endif