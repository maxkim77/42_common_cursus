/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:30:15 by jeongkim          #+#    #+#             */
/*   Updated: 2025/10/18 16:41:29 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void client_handler(int sig)
{
    if (sig == SIGUSR1)
        ft_putstr_fd("\e[33m > ACK signal received from server\n\e[0m",STDOUT_FILENO);
    else if (sig == SIGUSR2)
    {
            ft_putstr_fd("\e[92m > end of message signal received from server\n\e[0m", STDOUT_FILENO);
            exit(EXIT_SUCCESS);
    }
}

static void client_send_message(int server_pid, char *str)
{
    int i;

    i = 0;
    {
        ft_putstr_fd("\e[92msending length = [", STDOUT_FILENO);
        ft_putnbr_fd(ft_strlen(str), STDOUT_FILENO);
        ft_putstr_fd("]\n\e")
        send_int(server_pid, ft_strlen(str));
        ft_putstr_fd("\e[92msending message\n\e[0m",STDOUT_FILENO);
        while (str[i] != '\0')
            send_char(server_pid, str[i++]);
        ft_putstr_fd("\e[92msending null string terminator\n\e[0m", STDOUT_FILENO);
        send_char(server_pid, '\0');
    }
}

int main(int ac, char **av)
{
    struct sigaction s_client;

    if (ac != 3)
    {
        ft_putstr_fd("\e[31m ##error - incorrect syntax ##\0]")
    }
}