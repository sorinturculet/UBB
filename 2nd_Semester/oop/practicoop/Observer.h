//
// Created by sorn on 27-Jun-24.
//

#ifndef PRACTICOOP_OBSERVER_H
#define PRACTICOOP_OBSERVER_H
#include<vector>
#include<algorithm>
using namespace std;
class Observer{
    public:
        virtual void update()=0;
};
class Observable {
private:
    vector<Observer*> v;
public:
    void addObserver(Observer* obs){
        v.push_back(obs);
    }
    void removeObserver(Observer* obs){
        v.erase(remove(v.begin(),v.end(),obs),v.end());
    }
    void notify(){
        for(const auto& obs:v){
            obs->update();
        }
    }
};


#endif //PRACTICOOP_OBSERVER_H
