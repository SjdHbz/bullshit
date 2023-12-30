#ifndef SCORE_H
#define SCORE_H
namespace MyGame {
    class Score{
    public:
        int score;
        int swland;
        int swWorker;
        int number_of_cows;
        int number_of_cows_meat;
        int number_of_cows_milk;
        int number_of_sheep;
        int number_of_sheep_milk;
        int number_of_sheep_meat;
        int number_of_chicken;
        int number_of_chicken_egg;
        int number_of_chicken_meat;
        int number_of_wheat;
        int number_of_corn;
        int number_of_land;
        int number_of_worker;
        Score(){
             score=0;
             swland=0;
             swWorker=0;
             number_of_cows=0;
             number_of_cows_meat=0;
             number_of_cows_milk=0;
             number_of_sheep=0;
             number_of_sheep_milk=0;
             number_of_sheep_meat=0;
             number_of_chicken=0;
             number_of_chicken_egg=0;
             number_of_chicken_meat=0;
             number_of_wheat=0;
             number_of_corn=0;
             number_of_land=0;
             number_of_worker=0;
        }
    };
}


#endif
