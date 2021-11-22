#include <sys/wait.h>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <csignal>

void signal_handler(int signal_num)
{
	std::cout << "\nDetencion no permitida\n";
}

int main(void)
{
	int impar = 1;
	int fib1 = 1;
	int fib2 = 1;
	int fib3 = 0;
	int elfork = fork();

	std::signal(SIGTSTP, signal_handler);
	std::signal(SIGINT, signal_handler);
	std::signal(SIGQUIT, signal_handler);

	if (elfork == 0)
	{
		for (int i = 0; i < 50; i++)
		{
			std::cout << "Valor Impar: " << impar << " - " << "PID = " << getpid() << "\n";
			impar = impar + 2;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	else
	{
		for (int i = 0; i < 50; i++)
		{
			std::cout << "Valor Fibonacci: " << fib1 << " - " << "PPIDE = " << getpid() << "\n";
			fib3 = fib2 + fib1;
			fib2 = fib1;
			fib1 = fib3;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}

	return EXIT_SUCCESS;
}