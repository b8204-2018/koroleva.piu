//
// Created by Polina on 16.06.2019.
//

#ifndef SHOP_CUSTOMERS_H
#define SHOP_CUSTOMERS_H

#include <vector>
#include "Shop.h"
#include "Money.h"

using namespace std;


class Customer {
protected:
    ShoppingCart cart;
    Wallet wallet;



public:

    virtual bool isSatisfied();

    bool canBuyAll();

    Wallet *getWallet();

    ShoppingCart *getCart();

};


class Child : public Customer {
public:
    bool isSatisfied() override;

};

class Man : public Customer {
public:
    bool isSatisfied() override;

};

class Woman : public Customer {
public:
    bool isSatisfied() override;

};

/*class Family : Customer {
    vector<Human> members;
public:
    void addMember(Human *member);

    bool isSatisfied() override;

}; */

#endif //SHOP_CUSTOMERS_H
