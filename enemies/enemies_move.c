/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:31:44 by matomas           #+#    #+#             */
/*   Updated: 2024/11/27 16:32:06 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemies.h"
#include "so_long.h"
#include <stdlib.h>

// Movimiento de los enemigos, por ejemplo, se mueve un paso hacia el jugador
void move_enemies(t_info_map *data)
{
    // Ejemplo simple: mueven en un solo eje
    // Este es solo un ejemplo de lógica simple de movimiento, se puede hacer más compleja
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'X')  // Si es un enemigo
            {
                // Lógica simple de movimiento (modificar según sea necesario)
                if (data->map[i + 1][j] != '1')
                    i++;  // Mover hacia abajo
            }
            j++;
        }
        i++;
    }
}
