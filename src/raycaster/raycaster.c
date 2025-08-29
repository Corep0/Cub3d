/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:48:07 by seruff            #+#    #+#             */
/*   Updated: 2025/08/29 16:38:12 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	render(t_data *data);

void	init_ray(t_data *data)
{
	t_visu	visu;
	t_camera cam;

	visu->map = data->content->map;
	visu->map_width = content->width;
	visu->map_height = content->height;
	visu->screen_width = SCREEN_W;
	visu->screen_height = SCREEN_H;
	visu->data = data;
	visu->player = data->player;
	visu->cam = cam;
}

static void	step_count_and_distance(t_visu *visu, t_cam *cam, t_player *player)
{
	int	side;

	cam->hit = 0;
	if (cam->raydir_x >= 0)
	{
		cam->step_x = 1;
		cam->side_dist_x = (cam->map_x + 1.0 - player->x_pos) * cam->delta_dist_x;
	}
	else
	{
		cam->step_x = -1
		cam->side_dist_x = (player->x_pos - cam->map_x) * cam->delta_dist_x;
	}
	if (cam->raydir_y >= 0)
	{
		cam->step_y = 1;
		cam->side_dist_y = (cam->map_y + 1.0 - player->y_pos) * cam->delta_dist_y;
	}
	else
	{
		cam->step_y = -1
		cam->side_dist_y = (player->y_pos - cam->map_y) * cam->delta_dist_y;
	}
}

/*
 * - calcul des rayons pour chaques colonnes
 * - Position du player
 * - Calcul distance mur
 */
static void	calculate_ray(t_visu *visu, t_camera *cam, int x)
{
	cam->camera_x = 2 * x / (double)visu->screen_width - 1;
	cam->raydir_x = visu->player->x_dir + visu->player->x_plane * cam->camera_x;
	cam->raydir_y = visu->player->y_dir + visu->player->y_plane * cam->camera_x;
	cam->map_x = (int)visu->player->x_pos;
	cam->map_y = (int)visu->player->y_pos;
	if (cam->raydir_x == 0)
		cam->delta_dist_x = 1e30;
	else
		cam->delta_dist_x = fabs(1 / cam->raydir_x);
	if (cam->raydir_y == 0)
		cam->delta_dist_y = 1e30;
	else
		cam->delta_dist_y = fabs(1 / cam->raydir_y);
}

/* 
 * DDA : Parcours de la map jusqu'à toucher un mur
*/
static void	algo_touch_wall(t_visu *visu, t_camera *cam)
{
	while (!cam->hit)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			cam->map_x += cam->step_x;
			cam->side = 0;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			cam->map_y += cam->step_y;
			side = 1;
		}
		if (visu->map[cam->map_y][cam->map_x] == '1')
			hit = 1;
	}
}

void	raycaster(t_data *data, t_visu *visu, t_camera *cam)
{
	int	x;
	
	x = 0;
	while (x < visu->screen_width)
	{
		calculate_ray(visu, cam, x);
		step_count_and_distance(visu, cam, visu->player);
		x++;
	}
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
