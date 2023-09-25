#include "Observable.h"

namespace observer {
void Observable::addObserver(Observer * observer)
{
    observers_.insert(observer);
}

void Observable::removeObserver(Observer * observer)
{
    observers_.erase(observer);
}

void Observable::notifyAll(State state) const
{

    for (Observer * observer : observers_)
    {
        observer->update(state);
    }
}

}

