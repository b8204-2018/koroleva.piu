#include <cmath>

#include "Money.h"

Money::Money(unsigned int currency, unsigned int count) {
    this->currency = currency;
    this->count = count;
}

unsigned int Money::getCurrency() {
    return currency;
}

unsigned int Money::getCount() {
    return count;
}

void Money::changeCount(int count) {
    this->count += count;
}

Money *MoneyPress::printMoney(unsigned int currency, unsigned int count) {
    Money *money = new Money(currency, count);
    return money;
}

void Wallet::addMoney(Money money) {
    for (unsigned int i = 0; i < savingMoney.size(); i++) {
        if (money.getCurrency() == savingMoney.at(i).getCurrency()) {
            savingMoney.at(i).changeCount(money.getCount());
            return;
        }
    }
    savingMoney.push_back(money);
}

bool Wallet::rmMoney(Money money) {
    for (unsigned int i = 0; i < savingMoney.size(); i++) {
        if (money.getCurrency() == savingMoney.at(i).getCurrency() &&
            money.getCount() <= savingMoney.at(i).getCount()) {
            savingMoney.at(i).changeCount(-money.getCount());
            return true;
        }
    }
    return false;
}

Converter::rate::rate(unsigned int
                      from, unsigned int
                      into, float
                      ratio) {
    this->from = from;
    this->into = into;
    this->ratio = ratio;

}

void Converter::addRate(unsigned int from, unsigned int into, float ratio) {
    rate newRate(from, into, ratio);
    for (unsigned int i = 0; i < rateCollection.size(); i++) {
        if (newRate.from == rateCollection.at(i).from && newRate.into == rateCollection.at(i).into) {
            rateCollection.at(i).ratio = newRate.ratio;
            return;
        }
    }
    rateCollection.push_back(newRate);
}

Money *Converter::convert(Money &from, unsigned int into) {
    for (unsigned int i = 0; i < rateCollection.size(); i++) {
        if (from.getCurrency() == rateCollection.at(i).from && into == rateCollection.at(i).into) {
            Money *converted = (new MoneyPress)->printMoney(into,
                                                            round(from.getCount() * rateCollection.at(i).ratio));
            delete &from;
            return converted;
        }
    }
    return nullptr;
}
