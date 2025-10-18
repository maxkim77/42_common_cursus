#include "minitalk.h"

void	configure_sigaction_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - sigaction(SIGUSR1) ##\n\e[0m", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - sigaction(SIGUSR2) ##\n\e[0m", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	send_bit(pid_t pid, char bit, char flag_to_pause)
{
	int sig = (bit == 0) ? SIGUSR1 : SIGUSR2;

	if (kill(pid, sig) < 0)
	{
		ft_putstr_fd("\e[31m## error - kill() ##\n\e[0m", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (flag_to_pause)
		pause();
	else
		usleep(WAIT_US);
}

void	send_char(pid_t pid, char c)
{
	int i = 7;
	while (i >= 0)
	{
		char bit = (c >> i) & 1;
		send_bit(pid, bit, 1); // 매 비트마다 ACK 대기
		i--;
	}
}

void	send_int(pid_t pid, int num)
{
	int i = (int)(sizeof(int) * 8) - 1;
	while (i >= 0)
	{
		char bit = (num >> i) & 1;
		send_bit(pid, bit, 1); // 매 비트마다 ACK 대기
		i--;
	}
}
