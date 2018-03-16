//
// Created by Denys Burtnyak on 3/11/18.
//

#include "ft_ssl.h"

int		get_flag_args(int argc, char **argv, char *flag)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(flag, argv[i]) == 0)
			return i;
		i++;
	}
	return -1;
}