/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:01:18 by hans              #+#    #+#             */
/*   Updated: 2022/05/31 12:19:32 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	t_flag	f;
	char	s[] = "je teste\nla fonction memmove";

	f.eol = 9;
	printf("memmove=%s\n", gnl_memmove(&f, s));
	return (0);
}
