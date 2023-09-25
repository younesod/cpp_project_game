#ifndef OBSERVER_H
#define OBSERVER_H
#include "State.h"
namespace observer{
class Observable;
/**
 * @brief abstract class pour observer
 */
class Observer {
public:

    /**
     * @brief virtual met a jouer tout les observers
     * @param obs objet observable.
     */
    virtual void update(State state) = 0;

    /**
     * @brief default virtual destructeur.
     */
    virtual ~Observer() = default;

    /**
     * @brief constructeur par copie.
     */
    Observer(const Observer &) = default;

    Observer & operator=(const Observer &) = default;

protected:

    Observer() = default;
};

}

#endif // OBSERVER_H
