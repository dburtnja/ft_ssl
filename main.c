
#include "libft/libft.h"
#include "ft_ssl.h"



static int	select_command(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "base64") == 0)
		return (my_base64(argc - 2, argv + 2));
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n"
					  "Standard commands:\n\n"
					  "Message Digest command:\n\n"
					  "Cipher commands:\n"
					  "base64\n"
					  "des\n"
					  "des-ecb\n"
					  "des-cbc\n", argv[1]);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		return select_command(argc, argv);
	else
		ft_putendl("usage: ft_ssl command [command opts] [command args]");
	return (1);
}
