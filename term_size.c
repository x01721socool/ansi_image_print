#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"

int main(int argc, char **argv)
{
	char	c = 0;
    struct winsize w;
	printf(HIDE_CURSOR);
	while (1)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		printf ("lines %d | columns %d \r", w.ws_row, w.ws_col);
	}
	printf(SHOW_CURSOR);
    return (0);
}
