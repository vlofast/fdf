/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:23:48 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/02/15 13:23:50 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef struct
{
	int		width;
	int		height;
	int		**z_pos;
	int		zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
	
	float	xpos;
	float	ypos;
	float	xpos1;
	float	ypos1;
	
}		fdf;

float	mod(float i);
void	read_file(char *file, fdf *data);
void	algory(fdf *data);
void	algory2(fdf *data);
void	draw(fdf *data);
void	isometric(float *x, float *y, int z);
void	position(fdf *data);

#endif
