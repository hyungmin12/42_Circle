/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:53:21 by hyyoo             #+#    #+#             */
/*   Updated: 2023/07/03 18:28:37 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void a(void){
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_info	info;

	atexit(a);
	if (argc != 2)
		ft_error();
	ft_get_file_and_path(argv[1], &info);
	ft_init(info.map.start_dir, &info);
	mlx_loop_hook(info.mlx, ft_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, 17, 0, ft_redbutton, NULL);
	mlx_loop(info.mlx);
	exit(0);
}
