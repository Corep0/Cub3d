#include "raycasting.h"
#include <math.h>
#include <stdlib.h>

void raycast_and_draw(t_game *game)
{
    int x;
    for (x = 0; x < game->screenWidth; x++)
    {
        // 1. Calcul du rayon pour chaque colonne
        double cameraX = 2 * x / (double)game->screenWidth - 1;
        double rayDirX = game->player.dirX + game->player.planeX * cameraX;
        double rayDirY = game->player.dirY + game->player.planeY * cameraX;

        // 2. Position actuelle dans la map
        int mapX = (int)game->player.posX;
        int mapY = (int)game->player.posY;

        // 3. Calcul de la distance vers le prochain mur
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double sideDistX, sideDistY;
        int stepX, stepY;
        int hit = 0, side;

        // 4. Calcul du pas et de la distance initiale
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (game->player.posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->player.posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (game->player.posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->player.posY) * deltaDistY;
        }

        // 5. DDA : Parcours de la map jusqu'à toucher un mur
        while (!hit)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (game->map[mapY][mapX] == '1') // Attention, map[y][x] pour 2D
                hit = 1;
        }

        // 6. Calcul de la distance au mur
        double perpWallDist;
        if (side == 0)
            perpWallDist = (mapX - game->player.posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - game->player.posY + (1 - stepY) / 2) / rayDirY;

        // 7. Calcul de la hauteur du mur à dessiner
        int lineHeight = (int)(game->screenHeight / perpWallDist);
        int drawStart = -lineHeight / 2 + game->screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + game->screenHeight / 2;
        if (drawEnd >= game->screenHeight) drawEnd = game->screenHeight - 1;

        // 8. Choix de couleur (à remplacer par gestion de textures plus tard)
        int color = 0xFFFFFF;
        if (side == 1) color = 0xAAAAAA; // mur côté Y plus sombre

        // 9. Dessin de la colonne
        draw_vertical_line(game, x, drawStart, drawEnd, color);
    }
}
