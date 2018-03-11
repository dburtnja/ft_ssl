
#include "libft/libft.h"
#include "ft_ssl.h"

static int	select_command(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "base64"))
		return (my_base64(argc - 1, argv + 1));
	else
		return (1);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		return select_command(argc, argv);
	else
		ft_putendl("usage: ft_ssl command [command opts] [command args]");
	return (1);
}
