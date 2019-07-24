/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:49:12 by niragne           #+#    #+#             */
/*   Updated: 2019/07/24 14:58:07 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

#define FLAG_REVERSE 1

struct arg_option
{
	char *long_name;
	unsigned char short_name;
	int 	arg : 1;
	int		multiple_args : 1;
	int     set;
	int		value;
	unsigned	char flag_index;
	struct arg_option	*next;
};

struct arg_parser
{
	struct arg_option	*opt_list;
};

void	add_to_parser(struct arg_parser *parser, struct arg_option opt)
{

	struct arg_option *lst;

	

}

void	init_parser(struct arg_parser *parser)
{
	bzero(parser, sizeof(*parser));
}

void	parse_str(struct arg_parser *parser, char *str)
{
	int i;
	int flag = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (flag)
			{
				
			}
			flag = 1;
			i++;
		}
		else
		{
			if (flag)
			{
				int k = 0;
				printf("Str[i] == %d\n", str[i]);
			}
			i++;		
		}
	}
}

void	parse_args(struct arg_parser *parser, char **av)
{
	int i = 0;

	while (av[i])
	{
		parse_str(parser, av[i]);
		i++;
	}
}

int main(int ac, char **av)
{
    struct arg_parser parser;

	init_parser(&parser);
    add_to_parser(&parser, (struct arg_option){"reverse", 'r', 0, 0, 0, FLAG_REVERSE});
    add_to_parser(&parser, (struct arg_option){"banane", 'b', 0, 0, 0, 2});
	parse_args(&parser, av + 1);
	
	
}