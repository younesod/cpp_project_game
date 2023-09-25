<h1>Bienvenue sur Stratego !</h1>

<h3>Projet développé par Oudahya Younes et El kaoui Mohamed </h3>
<img src="images/stratego.png" width="800px" height="500px">

<h1 id="regle">REGLES DU JEU</h1><br>
<p>Une partie se déroule en 2 étapes : le choix d'un plateau fourni par défaut ou le choix du joueur fourni dans le fichier<br>
Ensuite vient le début de la partie ou le joueur Rouge commence et s'ensuit la bataille</p>
<p>Si vous souhaitez connaître les règles complète vous pouvez les consulter [ici](images/stratego-instructions-fr.pdf)
<h1>Comment lancer le jeu </h1>
<h2>MODE CONSOLE</h2>
<p>Vous pouvez executer le main se trouvant dans le projet-tui via Qt-Creator</p>

<h3>Comment modifier le fichier pour la mise en place des pièces ?</p>
<h4>Le fichier doit suivre une structure qui sera imposé :</h4>
<p>Chaque fichier est un fichier texte composé de quatre lignes</p>
<p>Chaque ligne du fichier est composée des symboles repris dans la table ci-dessous, séparés par des espaces</p>
<img src="images/tableauPiece.PNG">

<h3>Le fichier final doit pouvoir ressembler à ça<h3>
<img src="images/structure.png">
<h3> Ou placer le fichier ?</h3>
<p>Si vous souhaitez placer les fichiers contenant la mise en place de votre jeu,<br> vous devez les placer dans le dossier ressourcesGames se trouvant dans le projet</p>
<h2>MODE GRAPHIQUE </h2>
<p>Executer le main se trouvant dans le projet-gui </p>
<h3>- Concernant le déroulement du jeu</h3>
<p>Pour lancer la partie il suffit d'appuyer sur <b>play</b></p>
<p>Après avoir appuyer sur <b>play</b> , chaque joueur place ses pièces et lorsqu'il n'ya plus de pièce à placer il faut appuyer sur <b>endPlacement</b></p>
<p>Il est possible d'abandonner en plein milieu de la partie avec <b>surrender</b>
<p>Si une envie vous vient de quitter sachez qu'un <b>quit</b> est disponible</p>

<h1>Structure du dossier</h1>
Stratego-project<br>
    |---<b>project-dummy</b><br> <p>//Dossier concernant les tests//</p>
    |---<b>project-model</b><br> <p>//Dossier concernant le model du jeu//</p>
    |---<b>project-tui</b><br> <p>//Dossier concernant l'affichage console du jeu//</p>
    |---<b>ressourcesGames</b><br> <p>//Dossier concernant les fichiers pour le placement des pieces//</p>
    |---<b>project-gui</b><br> <p>//Dossier concernant l'affichage graphique du jeu</p>
<h1>Documentation du jeu</h1>
<h4>Vous pouvez consulter la documentation du jeu [ici](Stratego-project/dev4-stratego-pha-07-project/doc/html/index.html)</h4>

               
              





