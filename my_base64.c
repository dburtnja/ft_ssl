
#include <fcntl.h>
#include "ft_ssl.h"

//static int	encode()
//{
//	open()
//}
//
//static int	decode()
//{
//
//}

int my_base64(int argc, char **argv)
{
	int		in_fd;
	int		out_fd;
	int		flag_nbr;

	in_fd = 0;
	out_fd = 1;
	if ((flag_nbr = get_flag_args(argc, argv, "-i")) == -2)
		ft_putendl("usage: ft_ssl base64 [command opts] [command args]");
	return (1);
}