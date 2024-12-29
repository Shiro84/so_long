/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:34:47 by matomas           #+#    #+#             */
/*   Updated: 2024/11/27 16:35:48 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

void game_exit(t_info_map *data)
{
    mlx_destroy_window(data->mlx, data->win);  // Destruir ventana
    free(data->map);  // Liberar mapa
    exit(0);  // Salir del juego
}
