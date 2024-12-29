/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:28:40 by matomas           #+#    #+#             */
/*   Updated: 2024/11/27 16:28:54 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"
#include <stdlib.h>

void move_player(int key, t_info_map *data)
{
    if (key == 13)  // W: Arriba
        if (data->map[data->y - 1][data->x] != '1')
            data->y--;
    else if (key == 1)  // S: Abajo
        if (data->map[data->y + 1][data->x] != '1')
            data->y++;
    else if (key == 0)  // A: Izquierda
        if (data->map[data->y][data->x - 1] != '1')
            data->x--;
    else if (key == 2)  // D: Derecha
        if (data->map[data->y][data->x + 1] != '1')
            data->x++;
}

void update_player_position(t_info_map *data)
{
    data->map[data->y][data->x] = 'P';  // Colocar al jugador en la nueva posición
}
