#include "so_long.h"

void print_error(char *msg)
{
    write(2, "Error\n", 6);
    write(2, msg, ft_strlen(msg));
    exit(1);
}

int key_press(int key, t_game *game)
{
    if (key == KEY_ESC)
        Destroy_game(game);
    else if(key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

int Destroy_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
}

int main(int ac, char **av)
{
    t_game  *game;
    
    if (ac != 2)
        print_error("No Map");
    game = malloc(sizeof(t_game));
    game->mlx = mlx_init();
    game->img = img_init(game->mlx);
    read_map(av[1], game);
    check_map(game);
    game->win = mlx_new_window(game->mlx, game->wid * 64, game->hei * 64, "so_long");
    set_img(&game);
    mlx_hook (game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
    mlx_hook (game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
    mlx_loop(game->mlx);
    return (0);
}