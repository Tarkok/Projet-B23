Projet de Théo Lejeune et Maxime Engloo - 2018

On a trouvé le problème ! Mauvaise gestion de la mémoire dans la fonction loadSnake.
On a réservé de la mémoire avec la ligne 65 : 

" s->positionCorps = (SDL_Rect**)malloc(sizeof(SDL_Rect**)*1200); "

L'execution se fait maintenant correctement, il reste quelques petits bugs mais ça fonctionne!



Pour rappel:

Les maps sont personnalisables dans le dossier txt, un txt pour chaque level

Les textures sont dans le dossier media/assets, également personnalisables