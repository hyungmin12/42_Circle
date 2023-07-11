/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:09:10 by hyyoo             #+#    #+#             */
/*   Updated: 2023/06/29 20:50:47 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_load_img(t_info *info, int tex[][64], char *path, t_img *img)
{
	int	j;
	int	i;

	i = -1;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_w, &img->img_h);
	if (!img->img)
		ft_error();
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->l_size, &img->endian);
	while (++i < img->img_h)
	{
		j = -1;
		while (++j < img->img_w)
			tex[i][j] = img->data[img->img_w * i + j];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	ft_load_tex(t_info *info)
{
	t_img	img;

	ft_load_img(info, info->tex[0], info->element.ea_path, &img);
	ft_load_img(info, info->tex[1], info->element.we_path, &img);
	ft_load_img(info, info->tex[2], info->element.so_path, &img);
	ft_load_img(info, info->tex[3], info->element.no_path, &img);
}
