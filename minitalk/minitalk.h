#ifndef MINITALK_H
# define MINITALK_H

/*
** ============================================================================
**  Minitalk – 공용 헤더
**  - 클라이언트/서버 간 시그널 기반 통신에 필요한 공용 선언
** ============================================================================
*/

/* 대기 시간(마이크로초) – usleep()에서 사용 */
# define WAIT_US 100

/* ========================  INCLUDES  ====================================== */

# include "libft/libft.h"   /* ft_atoi, ft_strlen, ft_putstr_fd, ft_putnbr_fd */
# include <unistd.h>         /* getpid, write, usleep                         */
# include <signal.h>         /* sigemptyset, sigaction, kill                  */
# include <stdlib.h>         /* exit, malloc, free                             */

/* ========================  PROTOTYPES  ==================================== */
/* minitalk.c (클라이언트 전송 유틸) */
void	configure_sigaction_signals(struct sigaction *sa);
void	send_int(pid_t pid, int num);
void	send_char(pid_t pid, char c);
void	send_bit(pid_t pid, char bit, char flag_to_pause);

/* ========================  TYPES  ========================================= */
/*
** s_protocol
**  - 서버가 비트를 수신하며 조립하는 상태 컨테이너
**    bits   : 현재까지 받은 비트 수(0~7)
**    data   : 누적된 데이터(문자 1개 또는 길이 정수)
**    flag   : 메시지 길이 수신 완료 여부(0/1)
**    message: 완성 중인 수신 메시지 버퍼(동적 할당)
*/
typedef struct s_protocol
{
	int		bits;
	int		data;
	int		flag;
	char	*message;
}			t_protocol;

#endif /* MINITALK_H */
