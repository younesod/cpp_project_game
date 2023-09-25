#ifndef STATE_H
#define STATE_H
enum State{
    INITIALIZED,    /**< enum value INITIALIZED, the game is being initialized*/
    NOT_STARTED,    /**< enum value NOT_STARTED. the game is not ready to start*/
    CHOOSE_PIECE,   /**< enum value CHOOSE_PIECE. the player chose the piece*/
    TURN_END,       /**< enum value TURN_END. end of the the player*/
    END_GAME,       /**< enum value END_GAME. end of the game*/
    MOVE_PIECE,      /**< enum value MOVE_PIECE. the player place the piece*/

};

#endif // STATE_H
