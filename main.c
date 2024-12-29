/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:41:51 by matomas           #+#    #+#             */
/*   Updated: 2024/11/27 15:42:02 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_info_map data;

    if (argc != 2) {
        ft_error_exit("Error: Número incorrecto de argumentos.");
    }

    data.mlx = mlx_init();
    parse_map(argv[1], &data);  // Cargar y validar el mapa
    ft_reset_data(&data, argv[1]);
    data.win = mlx_new_window(data.mlx, data.width * TILE_SIZE, data.height * TILE_SIZE, "So Long");
    
    mlx_hook(data.win, 17, 0, ft_exit, &data);
    mlx_hook(data.win, 02, 0, ft_press_key, &data);
    mlx_loop_hook(data.mlx, ft_frame, &data);
    mlx_loop(data.mlx);

    return (0);
}
