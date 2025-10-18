#include "minitalk.h"

static void	server_is_message_finished(t_protocol *t_server, int *i, pid_t client_pid)
{
	if (t_server->bits == 8 && t_server->flag == 1)
	{
		t_server->message[*i] = (char)t_server->data;
		(*i)++;
		if (t_server->data == '\0')
		{
			ft_putstr_fd("\e[92mreceived message = [", STDOUT_FILENO);
			ft_putstr_fd(t_server->message, STDOUT_FILENO);
			ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
			free(t_server->message);
			t_server->message = NULL;
			t_server->flag = 0;
			*i = 0;
			send_bit(client_pid, 1, 0); // 메시지 종료 신호
		}
		t_server->bits = 0;
	}
}

static void	server_is_str_length_finished(t_protocol *t_server)
{
	if (t_server->bits == (int)sizeof(int) * 8 && t_server->flag == 0)
	{
		t_server->flag = 1;
		ft_putstr_fd("\e[92mreceived length = [", STDOUT_FILENO);
		ft_putnbr_fd(t_server->data, STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);

		t_server->message = ft_calloc((size_t)t_server->data + 1, sizeof(char));
		if (!t_server->message)
		{
			ft_putstr_fd("\e[31m## error - ft_calloc() ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		t_server->message[t_server->data] = '\0';
		t_server->bits = 0;
	}
}

static void	server_handler(int sig, siginfo_t *info, void *context)
{
	static t_protocol	t_server;
	static int			i;

	(void)context;
	usleep(WAIT_US);

	if (t_server.bits == 0)
		t_server.data = 0;

	/* 길이(정수) 수신 중일 때만 비트를 MSB-first로 적재 */
	if (sig == SIGUSR2 && t_server.flag == 0)
		t_server.data |= 1 << (((int)sizeof(int) * 8 - 1) - t_server.bits);

	/* 메시지(문자) 수신 중일 때는 8비트로 조립 */
	if (t_server.flag == 1)
	{
		if (sig == SIGUSR2)
			t_server.data |= 1 << (7 - t_server.bits);
	}

	t_server.bits++;

	server_is_str_length_finished(&t_server);
	server_is_message_finished(&t_server, &i, info->si_pid);

	/* 매 비트 수신 ACK */
	send_bit(info->si_pid, 0, 0);
}

int	main(void)
{
	struct sigaction	s_server;

	sigemptyset(&s_server.sa_mask);
	s_server.sa_sigaction = server_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_sigaction_signals(&s_server);

	ft_putstr_fd("\e[92mserver [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);

	while (1)
		pause();
	return (EXIT_SUCCESS);
}
