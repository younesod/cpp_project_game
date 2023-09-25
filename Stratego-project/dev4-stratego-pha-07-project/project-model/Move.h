#ifndef MOVE_H
#define MOVE_H

/**
 * @brief The Move enum sert pour distinguer le mouvement des diférentes pieces
 */
enum Move{
    STATIC,/**< enum value STATIC. pièce qui ne bouge pas  */
    NORMAL,/**< enum value NORMAL. pièce qui fait un pat  */
    INFINITE/**< enum value INFINITE. pièce qui bouge à l'infinie  */
};

#endif // MOVE_H
