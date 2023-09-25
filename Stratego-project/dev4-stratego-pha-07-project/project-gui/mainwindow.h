#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ViewGUI.h"
#include "facade.h"
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
struct Pos{int row;
           int col;};
class MainWindow : public QMainWindow, public observer::Observer
{
    Q_OBJECT

public:

    /**
     * @brief MainWindow constructeur pour la partie graphique du jeu
     * @param game objet Game qui permet de jouer au jeu
     * @param view  objet ViewGui
     * @param parent objet widget parent de QPushbutton
     */
    MainWindow(Game * game,ViewGUI * view,QWidget *parent = nullptr);

    ~MainWindow();

    /**
     * @brief updateDeck permet de mettre à jour le deck
     */
    void updateDeck();

    /**
     * @brief gridPosition permet de donner la position du bouton dans le grid
     * @param widget parent de QPushbutton
     * @return retourne la position du boutton
     */
    Pos gridPosition(QWidget * widget);

    /**
     * @brief affichagePiece
     */
    void affichagePiece();

    /**
     * @brief getDirection permet de retourner une direction pour le move dans le game (Model)
     * @param start position de départ du boutton
     * @param end position d'arrivé
     * @return retourne la direction souhaité par l'utilisateur
     */
    Direction getDirection(const Position &start, const Position &end);

    /**
     * @brief getNbSteps nombre de pas
     * @param start position de départ du boutton
     * @param end position d'arrivé
     * @return retourne le nombre de pas
     */
    int getNbSteps(const Position& start, const Position &end);

    /**
     * @brief getUi
     * @return retourne ui
     */
    Ui::MainWindow *getUi() const;


    /**
     * @brief virtual met a jouer tout les observers
     * @param obs objet observable.
     */
    void update(const State state)override;

private slots:
    /**
     * @brief on_playButton_clicked l'orsque l'utilisateur appuie sur le boutton play
     * la methode est appelée
     */
    void on_playButton_clicked();

    /**
     * @brief on_surrenderButton_clicked l'orsque l'utilisateur appuie sur le boutton surrender
     * la methode est appelée
     */
    void on_surrenderButton_clicked();

    /**
     * @brief on_quitButton_clicked l'orsque l'utilisateur appuie sur le boutton quit
     * la methode est appelée
     */
    void on_quitButton_clicked();

    /**
     * @brief onPieceClicked l'orsque l'utilisateur appuie sur un boutton du deck cette
     * methode est apellée qui permet de mettre en attribut le text du boutton
     */
    void onPieceClicked();

    /**
     * @brief onPieceBoardClicked l'orsque l'utilisateur appuie sur un des boutton du board la methode est apellée
     */
    void onPieceBoardClicked();

    /**
     * @brief on_endPlacement_clicked l'orsque l'utilisateur appuie sur le boutton endPlacement
     * la methode est appelée
     */
    void on_endPlacement_clicked();

    /**
     * @brief moveSoldier cette methode permet de bouger la piece dans le board
     */
    void moveSoldier();

    /**
     * @brief on_defaultGame_clicked l'orsque l'utilisateur appuie sur le boutton defalt
     * les pieces ce posent dans le tableau automatiquement
     */
    void on_defaultGame_clicked();


private:
    Ui::MainWindow *ui;
    std::string pieceChoosed;
    Position positionStart;
    Position positionEnd;
    Game * game;
    ViewGUI * view;

    /**
     * @brief connectPieceOnBoard permet de connecter les boutton des pieces dans le board
     */
    void connectPieceOnBoard();

    /**
     * @brief disconnectAllPiece permet de mettre a disable (true) tout les pieces du board
     */
    void disconnectAllPiece();
//    Position positionChoosed;
};


#endif // MAINWINDOW_H


