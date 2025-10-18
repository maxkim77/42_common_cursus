#include "minitalk.h"

static void	client_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\e[33m > ACK signal received from server\n\e[0m", STDOUT_FILENO);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("\e[92m > end of message signal received from server\n\e[0m",
			STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

static void	client_send_message(int server_pid, char *str)
{
	int len = (int)ft_strlen(str);
	int i = 0;

	ft_putstr_fd("\e[92msending length = [", STDOUT_FILENO);
	ft_putnbr_fd(len, STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);

	send_int(server_pid, len);

	ft_putstr_fd("\e[92msending message\n\e[0m", STDOUT_FILENO);
	while (str[i] != '\0')
		send_char(server_pid, str[i++]);

	ft_putstr_fd("\e[92msending null string terminator\n\e[0m", STDOUT_FILENO);
	send_char(server_pid, '\0');
}

int	main(int ac, char **av)
{
	struct sigaction s_client;
	int              server_pid;

	if (ac != 3)
	{
		ft_putstr_fd("\e[31m## error - incorrect syntax ##\n\e[0m", STDOUT_FILENO);
		ft_putstr_fd("\e[92m./client <server PID> <string>\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}

	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0) < 0)
	{
		ft_putstr_fd("\e[31m## error - invalid PID ##\n\e[0m", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}

	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);

	client_send_message(server_pid, av[2]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
