/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:27:53 by matomas           #+#    #+#             */
/*   Updated: 2024/11/27 16:28:03 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"
#include <stdlib.h>

void init_player(t_info_map *data)
{
    int i;
    int j;

    // Buscar la posición inicial del jugador en el mapa
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')  // 'P' es el jugador
            {
                data->player = 1;
                data->x = j;
                data->y = i;
                return;
            }
            j++;
        }
        i++;
    }
}
