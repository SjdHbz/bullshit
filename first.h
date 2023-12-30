#ifndef FIRST_H
#define FIRST_H

class first{
public:
    int coin ;
    int worker ;
    int agricultural_land ;
    first(){
        coin=12;
        worker=1;
        agricultural_land=2;
    }

    void set_coin(int Coin){
        coin = Coin;
    }
};

#endif // FIRST_H
