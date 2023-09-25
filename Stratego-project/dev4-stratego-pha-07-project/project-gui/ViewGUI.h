#ifndef VIEWGUI_H
#define VIEWGUI_H
#include "facade.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
class ViewGUI{
private :
    Game * game;
public :
    /**
     * @brief ViewGUI constructeur ViewGUI
     * @param game objet Game permet de jouer au jeu
     */
    ViewGUI(Game * game);

    /**
     * @brief updatePieceOnBoard permet de mettre a jour le tableau board
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void updatePieceOnBoard(Ui::MainWindow * mainWindow);

    /**
     * @brief buttonVisibility permet de mettre une visibilité aux pieces
     * @param btn boutton a mettre visible ou pas
     * @param i nombre ordonée
     * @param j nombre abcisses
     */
    void buttonVisibility(QPushButton *btn,int i,int j);

    /**
     * @brief updateButton permet de mettre le style au boutton
     * @param btn boutton
     */
    void updateButton(QPushButton *btn);

    /**
     * @brief updateButtonDeck met a jour les bouton du deck
     * @param color couleur du joueur
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void updateButtonDeck(PlayerColor color, Ui::MainWindow *mainWindow);

    /**
     * @brief updateDeck met a jour les bouton du deck
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void updateDeck(Ui::MainWindow * mainWindow);

    /**
     * @brief changeStyleSquare permet de mettre un style au boutton square (LAND or WATER)
     * @param square enum square (LAND or WATER)
     * @param pos objet position
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void changeStyleSquare(const SquareType &square, const Position &pos, Ui::MainWindow * mainWindow);

    /**
     * @brief currentPlayer met à jour le current player
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void currentPlayer(Ui::MainWindow *mainWindow);

    /**
     * @brief currentWinner affiche le gagnant
     * @param mainWindow mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void currentWinner(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_play_disableStyle met le style du bouton en mode disable(false)[désactivé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_play_disableStyle(Ui::MainWindow *mainWindow);
    /**
     * @brief btn_enPlacement_disableStyle met le style du bouton en mode disable(false)[désactivé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_enPlacement_disableStyle(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_surrender_disableStyle met le style du bouton en mode disable(false)[désactivé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_surrender_disableStyle(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_default_disableStyle met le style du bouton en mode disable(false)[désactivé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_default_disableStyle(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_quit_disableStyle met le style du bouton en mode disable(false)[désactivé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_quit_disableStyle(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_quit_disableStyle met le style du bouton en mode disable(true)[activé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_play_Style(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_quit_disableStyle met le style du bouton en mode disable(true)[activé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_enPlacement_Style(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_quit_disableStyle met le style du bouton en mode disable(true)[activé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_surrender_Style(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_quit_disableStyle met le style du bouton en mode disable(true)[activé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_default_Style(Ui::MainWindow *mainWindow);

    /**
     * @brief btn_quit_disableStyle met le style du bouton en mode disable(true)[activé]
     * @param mainWindow objet MainWindow c'est ce qui permet de lancer la partie graphique
     */
    void btn_quit_Style(Ui::MainWindow *mainWindow);
};

//
inline ViewGUI::ViewGUI(Game *game): game(game)
{}

inline void ViewGUI::updatePieceOnBoard(Ui::MainWindow *mainWindow)
{
    QLayoutItem *item ;
    QPushButton *btn;
    QString style;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            item=mainWindow->gridLayout->itemAtPosition(i,j);
            if(game->getBoard().getSquare(Position(i,j)).getType()==LAND){
                if(game->getPiece(Position(i,j))!=nullptr){
                    if(game->getPiece(Position(i,j))->getColorPiece()==RED){
                        style="background-color:crimson;padding:10px;color:white;";
                    }
                    else if(game->getPiece(Position(i,j))->getColorPiece()==BLUE) {
                        style="background-color:#318CE7;padding:10px;color:white;";
                    }
                    switch(game->getPiece(Position(i,j))->getSymbol()){
                    case 0:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("D");
                        btn->setStyleSheet(style);
                        break;
                    case 1:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("1");
                        btn->setStyleSheet(style);
                        break;
                    case 2:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("2");
                        btn->setStyleSheet(style);
                        break;
                    case 3:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("3");
                        btn->setStyleSheet(style);
                        break;
                    case 4:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("4");
                        btn->setStyleSheet(style);
                        break;
                    case 5:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("5");
                        btn->setStyleSheet(style);
                        break;
                    case 6:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("6");
                        btn->setStyleSheet(style);
                        break;
                    case 7:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("7");
                        btn->setStyleSheet(style);
                        break;
                    case 8:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("8");
                        btn->setStyleSheet(style);
                        break;
                    case 9:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("9");
                        btn->setStyleSheet(style);
                        break;
                    case 10:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("10");
                        btn->setStyleSheet(style);
                        break;
                    case 11:
                        btn=qobject_cast<QPushButton*>(item->widget());
                        btn->setText("B");
                        btn->setStyleSheet(style);
                        break;
                    }
                    buttonVisibility(btn,i,j);
                }
                else{
                    btn=qobject_cast<QPushButton*>(item->widget());
                    btn->setText("");
                    btn->setStyleSheet("background-color: white; "
                                       "border:2px solid green;padding:10px;");
                }
            }
        }
    }
}

inline void ViewGUI::buttonVisibility(QPushButton *btn, int i, int j){

    if(game->getPiece(Position(i,j)) != nullptr){
        if(game->getPiece(Position(i,j))->getColorPiece() == PlayerColor::BLUE){

            if(game->getPiece(Position(i,j))->getVisible() || game->getCurrentPlayer().getPColor() == PlayerColor::BLUE){
                //afficher boutton
                btn->setStyleSheet("background-color:#318CE7;padding:10px;color:white;");
            }else{
                //invisible bleu
                btn->setStyleSheet("background-color:#318CE7;padding:10px;color:#318CE7;");
            }

        }else{
            if(game->getPiece(Position(i,j))->getVisible() || game->getCurrentPlayer().getPColor() == PlayerColor::RED){
                //afficher boutton
                btn->setStyleSheet("background-color:crimson;padding:10px;color:white;");
            }else{
                //invisible rouge
                btn->setStyleSheet("background-color:crimson;padding:10px;color:crimson;");

            }
        }
    }

}

inline void ViewGUI::updateButton(QPushButton *btn)
{
    QString style;
    if(game->getCurrentPlayer().getPColor()==RED)style="background-color:crimson;padding: 10px;color:white;";
    else style="background-color:#318CE7;padding: 10px;color:white;";
    btn->setStyleSheet(style);
}

inline void ViewGUI::updateButtonDeck(PlayerColor color,Ui::MainWindow * mainWindow)
{
    QString style;
    if(color==RED)style="background-color:crimson;color:white;";
    else style="background-color:#318CE7;color:white;";
    for(int i=0;i<mainWindow->gridLayoutPieces->count();i++){
        QLayoutItem* item= mainWindow->gridLayoutPieces->itemAt(i);
        QPushButton *btn= qobject_cast<QPushButton*>(item->widget());
        btn->setStyleSheet(style);
        btn->resize(40,40);
    }
}

inline void ViewGUI::updateDeck(Ui::MainWindow *mainWindow)
{
    if ( mainWindow->gridLayoutPieces->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = mainWindow->gridLayoutPieces->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
}

inline void ViewGUI::changeStyleSquare(const SquareType &square,const Position& pos,Ui::MainWindow *mainWindow)
{
    if(square==LAND){
        mainWindow->gridLayout->itemAtPosition(pos.getRow(),pos.getColumn())->widget()->setStyleSheet("border:2px solid green;padding:10px;");
    }
    else{
        mainWindow->gridLayout->itemAtPosition(pos.getRow(),pos.getColumn())->widget()->setStyleSheet("background-color:BLUE");
    }
}

inline void ViewGUI::btn_play_disableStyle(Ui::MainWindow *mainWindow){
        mainWindow->playButton->setStyleSheet("background-color:#c0c0c0;"
                                      "border-radius:8px;"
                                      "border:1px solid #c0c0c0;"
                                      "font-family:Arial;"
                                      "font-size:17px;"
                                      "color:black;"
                                      "padding:10px 20px;"
                                      "text-decoration:none;");
}

inline void ViewGUI::btn_enPlacement_disableStyle(Ui::MainWindow *mainWindow){
    mainWindow->endPlacement->setStyleSheet("background-color:#c0c0c0;"
                                    "border-radius:8px;"
                                    "border:1px solid #c0c0c0;"
                                    "font-family:Arial;"
                                    "font-size:17px;"
                                    "color:black;"
                                    "padding:10px 20px;"
                                    "text-decoration:none;");
}

inline void ViewGUI::btn_surrender_disableStyle(Ui::MainWindow *mainWindow){
    mainWindow->surrenderButton->setStyleSheet("background-color:#c0c0c0;"
                                    "border-radius:8px;"
                                    "border:1px solid #c0c0c0;"
                                    "font-family:Arial;"
                                    "font-size:17px;"
                                    "color:black;"
                                    "padding:10px 20px;"
                                    "text-decoration:none;");
}

inline void ViewGUI::btn_default_disableStyle(Ui::MainWindow *mainWindow){
    mainWindow->defaultGame->setStyleSheet("background-color:#c0c0c0;"
                                    "border-radius:8px;"
                                    "border:1px solid #c0c0c0;"
                                    "font-family:Arial;"
                                    "font-size:17px;"
                                    "color:black;"
                                    "padding:10px 20px;"
                                    "text-decoration:none;");
}

inline void ViewGUI::btn_quit_disableStyle(Ui::MainWindow *mainWindow){
    mainWindow->quitButton->setStyleSheet("background-color:#c0c0c0;"
                                    "border-radius:8px;"
                                    "border:1px solid #c0c0c0;"
                                    "font-family:Arial;"
                                    "font-size:17px;"
                                    "color:black;"
                                    "padding:10px 20px;"
                                    "text-decoration:none;");
}

inline void ViewGUI::btn_play_Style(Ui::MainWindow *mainWindow){
    mainWindow->playButton->setStyleSheet("background-color:#44c767;"
                                  "border-radius:8px;"
                                  "border:1px solid #18ab29;"
                                  "font-family:Arial;"
                                  "font-size:17px;"
                                  "padding:10px 20px;"
                                  "text-decoration:none;");
}

inline void ViewGUI::btn_enPlacement_Style(Ui::MainWindow *mainWindow){
    mainWindow->endPlacement->setStyleSheet("background-color:#44c767;"
                                    "border-radius:8px;"
                                    "border:1px solid #18ab29;"
                                    "font-family:Arial;"
                                    "font-size:17px;"
                                    "padding:10px 20px;"
                                    "text-decoration:none;");
}

inline void ViewGUI::btn_surrender_Style(Ui::MainWindow *mainWindow){
    mainWindow->surrenderButton->setStyleSheet("background-color:#44c767;"
                                       "border-radius:8px;"
                                       "border:1px solid #18ab29;"
                                       "font-family:Arial;"
                                       "font-size:17px;"
                                       "padding:10px 20px;"
                                       "text-decoration:none;");
}

inline void ViewGUI::btn_default_Style(Ui::MainWindow *mainWindow){
    mainWindow->defaultGame->setStyleSheet("background-color:#44c767;"
                                  "border-radius:8px;"
                                  "border:1px solid #18ab29;"
                                  "font-family:Arial;"
                                  "font-size:17px;"
                                  "padding:10px 20px;"
                                  "text-decoration:none;");
}

inline void ViewGUI::btn_quit_Style(Ui::MainWindow *mainWindow){
    mainWindow->quitButton->setStyleSheet("background-color:#44c767;"
                                  "border-radius:8px;"
                                  "border:1px solid #18ab29;"
                                  "font-family:Arial;"
                                  "font-size:17px;"
                                  "padding:10px 20px;"
                                  "text-decoration:none;");
}

inline void ViewGUI::currentPlayer(Ui::MainWindow *mainWindow)
{
    if(game->getCurrentPlayer().getPColor() == RED){
        mainWindow->label_player->setText("RED");
        mainWindow->label_player->setStyleSheet("color:crimson;");
    }else if(game->getCurrentPlayer().getPColor() == BLUE){
        mainWindow->label_player->setText("BLEU");
        mainWindow->label_player->setStyleSheet("color:#318CE7;");
    }

}

inline void ViewGUI::currentWinner(Ui::MainWindow *mainWindow){
    if(game->getWinner() == RED){
        mainWindow->label_txt->setText("WINNER");
        mainWindow->label_player->setText("RED");
        mainWindow->label_player->setStyleSheet("color:crimson;");
    }else if(game->getWinner() == BLUE){
        mainWindow->label_txt->setText("WINNER");
        mainWindow->label_player->setText("BLEU");
        mainWindow->label_player->setStyleSheet("color:#318CE7;");

    }
}






#endif // VIEWGUI_H
