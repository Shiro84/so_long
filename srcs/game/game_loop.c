/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:34:12 by matomas           #+#    #+#             */
/*   Updated: 2024/11/27 16:34:29 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "so_long.h"
#include <mlx.h>

void game_loop(t_info_map *data)
{
    mlx_clear_window(data->mlx, data->win);  // Limpiar la ventana
    ft_draw_map(data);  // Dibujar el mapa
    move_enemies(data);  // Mover enemigos
    update_player_position(data);  // Actualizar posición del jugador
    // Verificar condiciones de fin del juego (victoria, derrota)
    if (data->count == 0 && data->player == 1 && data->finish == 1)
        game_exit(data);
}
