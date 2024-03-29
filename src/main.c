/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:01 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/02/16 11:13:02 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static void	clear_win(fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

static int	handle_input(int keysym, fdf *data)
{
	if (keysym == XK_Escape)
	{	
		exit (0);
		clear_win(data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	fdf	*data;

	(void) argc;
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, &handle_input, &data);
	mlx_loop(data->mlx_ptr);
	free(data->z_pos);
	free(data);
}
