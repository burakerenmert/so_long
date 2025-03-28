/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_ops2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:12:06 by buramert          #+#    #+#             */
/*   Updated: 2025/03/28 08:03:44 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_wall(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->b_image, width * 64, height * 64);
}

void	place_player(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->p_image, width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->c_image, width * 64, height * 64);
	game->collectables++;
}

void	place_exit(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->e_image, width * 64, height * 64);
}

void	place_floor(t_gamecntrl *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->f_image, width * 64, height * 64);
}
