#include "cub3d.h"

void	change_angle(t_player *player, double speed)
{
	player->angle += speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	else if (player->angle < 0)
		player->angle += 2 * PI;
}
