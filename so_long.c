/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:12:06 by buramert          #+#    #+#             */
/*   Updated: 2025/03/28 08:04:01 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_gamecntrl *game)
{
	if (game->f_image)
		mlx_destroy_image(game->mlxpointer, game->f_image);
	if (game->b_image)
		mlx_destroy_image(game->mlxpointer, game->b_image);
	if (game->p_image)
		mlx_destroy_image(game->mlxpointer, game->p_image);
	if (game->e_image)
		mlx_destroy_image(game->mlxpointer, game->e_image);
	if (game->c_image)
		mlx_destroy_image(game->mlxpointer, game->c_image);
}

int	ft_exit(t_gamecntrl *game)
{
	int	line;

	line = 0;
	destroy_images(game);
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	if (game->mlxpointer)
		mlx_destroy_display(game->mlxpointer);
	free(game->mlxpointer);
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_gamecntrl	game;

	if (argc == 2)
	{
		ft_pathchecker(argv[1]);
		ft_imagechecker();
		ft_memset(&game, 0, sizeof(t_gamecntrl));
		map_reading(&game, argv);
		ft_mapchecker(&game);
		game.mlxpointer = mlx_init();
		game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 64),
				(game.heightmap * 64), "so_long");
		place_images_in_game(&game);
		place_graphics(&game);
		mlx_key_hook(game.winpointer, controls_manager, &game);
		mlx_hook(game.winpointer, 17, 0, exit, 0);
		mlx_loop(game.mlxpointer);
	}
	return (0);
}
