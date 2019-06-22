#include <vector>

#ifndef SHOP_MONEY_H
#define SHOP_MONEY_H

using namespace std;

enum currency {
    rub, eur, usd, jpy
};

class Money;

class MoneyPress;

class Money {
    unsigned int currency;
    unsigned int count;

    Money(unsigned int currency, unsigned int count);

    friend class MoneyPress;

public:
    unsigned int getCurrency();

    unsigned int getCount();

    void changeCount(int count);

    ~Money() = default;
};

class MoneyPress {
public:
    Money *printMoney(unsigned int currency, unsigned int count);
};

class Wallet {
    vector<Money> savingMoney;
public:
    void addMoney(Money money);

    bool rmMoney(Money money);

    friend class Customer;
};

class Converter {
    struct rate {
        unsigned int from;
        unsigned int into;
        float ratio;

        rate(unsigned int from, unsigned int into, float ratio);
    };

    vector<rate> rateCollection;

public:
    Money *convert(Money &from, unsigned int into);

    void addRate(unsigned int from, unsigned int into, float ratio);
};

#endif //SHOP_MONEY_H
