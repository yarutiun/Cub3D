/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels_and_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:48:44 by yarutiun          #+#    #+#             */
/*   Updated: 2023/05/01 01:52:45 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;
	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_texture(t_cube *cube, int type)
{
	t_wall	*wall;

	wall = &cube->rc.walls[type];
	wall->img = malloc(sizeof(t_img));
	wall->img->img = mlx_xpm_file_to_image(cube->mlx.mlx_ptr, cube->param.wall_path[type], &wall->width, &wall->height);
	if (!wall->img)
	{
		free(wall->img);
		texture_not_loaded_error(cube);
	}
	wall->img->address = mlx_get_data_addr(wall->img->img, &wall->img->bits_per_pixel,
				&wall->img->line_length, &wall->img->endian);
}

void	load_textures(t_cube *cube)
{
	t_rc	*rc;

	rc = &cube->rc;
	init_texture(cube, NORTH_WALL);
	init_texture(cube, SOUTH_WALL);
	init_texture(cube, WEST_WALL);
	init_texture(cube, EAST_WALL);
	rc->walls[NORTH_WALL].height = 128;
	rc->walls[NORTH_WALL].width = 128;
	rc->walls[SOUTH_WALL].height = 128;
	rc->walls[SOUTH_WALL].width = 128;
	rc->walls[WEST_WALL].height = 128;
	rc->walls[WEST_WALL].width = 128;
	rc->walls[EAST_WALL].height = 128;
	rc->walls[EAST_WALL].width = 128;
}