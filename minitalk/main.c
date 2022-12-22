#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	get_sig(int sig)
{
	// 비트를 저장하는 정적 변수
	static char	temp;
	// 비트를 얼마나 받았는지 확인하는 정적 변수
	static int	bit;

	if (sig == SIGUSR1)
	{
 		// temp와 0을 or연산하여 그 값을 temp에 입력
		temp |= 0;
		// 비트가 8이 아닐경우 좌측으로 1만큼 shift
		if (bit < 7)
			temp <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		// temp와 1을 or연산하여 그 값을 temp에 입력
		temp |= 1;
		// 비트가 8이 아닐경우 좌측으로 1만큼 shift
		if (bit < 7)
			temp <<= 1;
	}
	bit++;
	// 비트가 8이 될 경우 저장된 문자를 출력하고 정적변수 초기화
	if (bit == 8)
	{
		write(1, &temp, 1);
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	// 서버 실행시 pid 출력하는 로직
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	// 사용자 지정 시그널을 받으면 처리할 함수 지정해주기
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	// 요청이 들어올때까지 계속 대기하기
	while (1)
		pause();
}

void	send_sig(int pid, char *str, int length)
{
	// 문자열의 인덱스
	int	byte_index;
	// 문자의 인덱스
	int	bit_index;
	// 전송할 비트를 나누는 변수
	int	bit_temp;

	byte_index = 0;
	// 들어온 문자열의 길이만큼 루프를 돔
	while (byte_index < length)
	{
		bit_index = 0;
		// 문자열의 문자만큼 루프를 돔
		while (bit_index < 8)
		{
	/*
	str[byte_index] >> (7 - bit_index)만큼 shift 연산한다
	그 값을 1로 and연산해서 비트를 구한다.
	뒤 비트부터 보내야 서버에서 비트를 받아서 문자 출력이 가능함.
	*/
			bit_temp = str[byte_index] >> (7 - bit_index) & 1;
		// bit_temp가 0이면 사용자 지정 시그널 1을 보냄
			if (bit_temp == 0)
				kill(pid, SIGUSR1);
		// bit_temp가 0이면 사용자 지정 시그널 2를 보냄
			else if (bit_temp == 1)
				kill(pid, SIGUSR2);
	// 전송 후 다른 처리를 위해 30 마이크로초만큼 스레드 일시정지
			usleep(30);
			bit_index++;
		}
		// 문자 하나 전송 후 300 마이크로초만큼 스레드 일시정지
		usleep(300);
		byte_index++;
	}
}

// 문자열의 길이를 확인하고 마지막부분에 \n을 추가하는 함수
void	get_str(int pid, char *str)
{
	// 문자열의 길이
	int		length;
	// \n까지 포함한 문자열
	char	*send;

	// 문자열 합침
	send = ft_strjoin(str, "\n");
	if (send == NULL)
		exit(1);
	// 문자열의 길이를 구함
	length = ft_strlen(send);
	// 시그널을 보냄
	send_sig(pid, send, length);
	// malloc으로 할당한 문자열 해제
	free(send);
	// 정상 종료
	exit(0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	// 매개변수 2개가 들어왔는지 확인
	if (argc != 3)
	{
		ft_putstr_fd("Argument is Wrong!!\n", 1);
		exit(1);
	}
	// argv는 문자열로 들어오기 때문에 정수로 변환
	pid = ft_atoi(argv[1]);
	// 유효한 pid의 값 범위내에 들어왔는지 확인
	if (pid < 100 || pid > 99998)
	{
		ft_putstr_fd("Invalid PID...\n", 1);
		exit(1);
	}
	// pid와 argv[2]의 문자열을 보냄.
	get_str(pid, argv[2]);
}
