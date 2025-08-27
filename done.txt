1. Validation finale de la map
    Pour garantir qu’aucun bug ne survienne à l’exécution. V
     Vérifier que la map est entièrement fermée par des 1. V
     Vérifier qu’il y a exactement un seul joueur. V
     Interdire tout caractère invalide (a-z, autres symboles). V
     Gérer les espaces et lignes vides en dehors des zones valides. V
________________________DONE_______________________________________________
A refaire, l'ordre d'entree des elements de la map. NO, SO, WE, EA, F, C
	les informations peuvent etre dans tous les ordres possibles.
	A ranger preferablement dans l'ordre enumere pour eviter de devoir TOUT changer.
___________________________________________________________________________

 2. Initialisation du jeu
    Préparer les structures avant d’entrer dans la boucle de rendu.  V
     Convertir la direction (N, S, E, W) en vecteur direction + caméra plane. V
		* Function to re-scale every image.xpm
     Stocker les dimensions de la map. V
     Charger les textures .xpm avec la mlx.
     Créer la fenêtre (mlx_new_window) et l’image (mlx_new_image).
____________________________________________________________________________

3. Boucle principale (event loop)
    Le cœur du jeu.
     Boucle mlx_loop() pour gérer :
        Entrées clavier (mlx_hook ou mlx_key_hook).
        Fermeture de la fenêtre.
        Rafraîchissement de l’écran (à chaque frame).
____________________________________________________________________________

 4. Raycasting
    Rendu 3D basé sur la map 2D.
     Lancer un rayon pour chaque colonne de l’écran.
     Trouver le mur rencontré par chaque rayon (DDA ou autre algo).
     Calculer la distance, la hauteur du mur à afficher.
     Appliquer la texture correspondante.
____________________________________________________________________________

 5. Mouvements du joueur
    Interaction clavier + collision.
     Avancer / Reculer (W/S).
     Rotation gauche/droite (A/D ou flèches).
     Détection de collision avec les 1 (ne pas traverser les murs).
____________________________________________________________________________

 6. Améliorations possibles (bonus)


* Verifier l'ordre de fermetures du programme (leaks possibles)
* Banque d'image des images deja generes. Conserver un stock des images generes (composing) 
