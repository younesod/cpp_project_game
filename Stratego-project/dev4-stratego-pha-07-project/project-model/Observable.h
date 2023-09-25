#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include "Observer.h"

namespace observer{
class Observer;

/**
 * @brief abstract class pour  Observable
 */
class Observable {
public:

    /**
     * @brief virtual destructeur.
     */
    virtual ~Observable() = default;

    /**
     * @brief constructor avec copie.
     */
    Observable(const Observable &) = default;


    /**
     * @brief Adds ajoute un observer a "observers_"
     * @param obs l'observer que l'on ajoute
     */
    virtual void addObserver( Observer * obs) final;

    /**
     * @brief Removes efface un observer a "observers_"
     * @param obs l'observer que l'on doit effacer
     */
    virtual void removeObserver(Observer *obs) final;

protected:

    Observable() = default;


    std::set<Observer *> observers_ { };

    /**
     * @brief fonction qui notifie à tous les observer un changement d'état.
     */
    virtual void notifyAll(const State state) const final;

};
}

#endif // OBSERVABLE_H
