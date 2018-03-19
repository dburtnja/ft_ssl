
#include <fcntl.h>
#include "ft_ssl.h"

static int  encode(int in_fd, int out_fd)
{
    char    buf[4];
    char    result[5];
    ssize_t read_bytes;

    while ((read_bytes = read(in_fd, &buf[0], 3)) > 0)
    {
        result[0] = BASE64_ARRAY[buf[0] >> 2];
        result[1] = BASE64_ARRAY[buf[1] >> 4 | (buf[0] & 3) << 4];
        result[2] = BASE64_ARRAY[buf[2] >> 6 | (buf[1] & 15) << 2];
        result[3] = BASE64_ARRAY[buf[2] & 63];
        while (read_bytes < 3)
        {
            read_bytes++;
            result[read_bytes] = '=';
        }
        ft_putstr_fd(result, out_fd);
        if (read_bytes < 3)
            return (0);
    }
	ft_putendl_fd("", out_fd);
    return (0);
}

static int  decode(int in_fd, int out_fd)
{
	ssize_t	read_bytes;
	char	buf[5];
	char	result[4];

	while ((read_bytes = read(in_fd, &buf[0], 4)) > 0)
	{
		ft_putendl(buf);
		if (read_bytes < 4)
			return (0);
	}
	return (0);
}

static int  run(int argc, char **argv, int in_fd, int out_fd)
{
    int e_arg;
    int d_arg;

    e_arg = get_flag_args(argc, argv, "-e");
    d_arg = get_flag_args(argc, argv, "-d");
    if (e_arg >= 0 && d_arg >= 0)
        return (ft_printf("ft_ssl: Error: only one -e or -d allowed\n"));
    if (e_arg == -1 && d_arg == -1)
        return (ft_printf("ft_ssl: Error: one -d or -e required\n"));
    if (e_arg >= 0)
        return encode(in_fd, out_fd);
    return decode(in_fd, out_fd);
}

static int my_open(int argc, char **argv, int flag_nbr, int open_flag)
{
    int flag_arg_nbr;
    int fd;

    flag_arg_nbr = flag_nbr + 1;
    if (argc <= flag_arg_nbr)
        return (-ft_printf("ft_ssl: Error: no required argument after %s flag\n", argv[flag_arg_nbr]));
    if ((fd = open(argv[flag_arg_nbr], open_flag, 0666)) < 0)
        return (-ft_printf("ft_ssl: Error: could'nt open file '%s'\n", argv[flag_arg_nbr]));
    return (fd);
}

int my_base64(int argc, char **argv)
{
	int		in_fd;
	int		out_fd;
	int		flag_nbr;

	in_fd = 0;
	out_fd = 1;
	if ((flag_nbr = get_flag_args(argc, argv, "-i")) >= 0)
    {
        if ((in_fd = my_open(argc, argv, flag_nbr, O_RDONLY)) < 0)
            return (1);
    }
    if ((flag_nbr = get_flag_args(argc, argv, "-o")) >= 0)
    {
        if ((out_fd = my_open(argc, argv, flag_nbr, O_WRONLY | O_CREAT)) < 0)
            return (1);
    }
    if (run(argc, argv, in_fd, out_fd) != 0)
        ft_putendl("usage: ft_ssl base64 [command opts] [command args]");
	return (0);
}