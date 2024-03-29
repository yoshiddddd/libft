/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:39:28 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/02 16:36:03 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			c2;
	int				i;

	i = 0;
	c2 = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c2)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// char s[] = "tripouille";
//         // char s2[] = "ltripouiel";
//         // char s3[] = "";
// 	char *p;

// 	p = ft_strrchr(s, 0);

// 	printf("検索文字が見つかった場所から表示→%s\n",p);
// }
