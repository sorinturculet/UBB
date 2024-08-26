//
// Created by sorn on 26-May-24.
//

#ifndef LAB10_11_OBSERVER_H
#define LAB10_11_OBSERVER_H
#include<vector>
#include <cstdio>
#include<algorithm>
using namespace std;
class Observer {
public:
    virtual void update()=0;
};
class Observable {
private:
/*Non owning pointers to observer objects*/
    std::vector<Observer*> observers;
public:
/* Observers use this method to register for notification
 Alternative names: attach, register, subscribe, addListener */
    void addObserver(Observer *obs) {
        observers.push_back(obs);
    }
/* Observers use this to cancel the registration
!!!Before an observer is destroyed need to cancel the registration
 Alternative names: detach, unregister, removeListener */
    void removeObserver(Observer *obs) {
        observers.erase(std::remove(begin(observers), end(observers),obs),
                        observers.end());
    }
protected:
/* Invoked by the observable object
 in order to notify interested observer */
    void notify() {
        for (auto obs : observers) {
            obs->update();
        }
    }
};

#endif //LAB10_11_OBSERVER_H
