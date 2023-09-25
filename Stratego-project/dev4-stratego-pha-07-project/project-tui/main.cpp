
#include <Game.h>
#include "View.h"
#include "Controller.h"

/**
 * @brief main permet de lancer le jeu
 * @return
 */
int main()
{
    Game game=Game();
    View view= View(&game);
    Controller ctrl= Controller(&game,&view);
    ctrl.startGame();

}
