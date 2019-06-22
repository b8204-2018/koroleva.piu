//
// Created by Polina on 16.06.2019.
//

#include <cmath>
#include "Customers.h"


bool Customer::canBuyAll() {
    Wallet neededMoney;
    for (unsigned int i = 0; i < cart.products.size(); i++){
        neededMoney.addMoney(*(new MoneyPress())->printMoney(cart.products.at(i).second, cart.products.at(i).first->getPrice()));
    }
    Wallet copy = this->wallet;

    for (unsigned int i = 0; i < neededMoney.savingMoney.size(); i++){
        if (!copy.rmMoney(neededMoney.savingMoney.at(i))) return false;
    }
    return true;
}

bool Customer::isSatisfied() {
    if (canBuyAll()) return true;
    return false;
}

ShoppingCart* Customer::getCart() {
    return &cart;
}

Wallet* Customer::getWallet() {
    return &wallet;
}


bool Child::isSatisfied() {
    for(unsigned int i = 0; i < cart.getProductList()->size(); i++){
        if (cart.getProductList()->at(i).first->getType() == "Chips") return true;
    }
    return false;
}

bool Woman::isSatisfied() {
    if (!canBuyAll()) return false;
    for (unsigned int i = 0; i < cart.getProductList()->size(); i++){
        if (cart.getProductList()->at(i).first->getType() == "Tea") return true;
    }
    return false;
}

bool Man::isSatisfied() {
    if (!canBuyAll()) return false;
    for (unsigned int i = 0; i < cart.getProductList()->size(); i++){
        if (cart.getProductList()->at(i).first->getType() == "Soda") return true;
    }
    return false;
}