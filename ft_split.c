/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:45:15 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/02 14:25:25 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **ans, int len)
{
	while (len >= 0)
	{
		free(ans[len]);
		len--;
	}
	free(ans);
	return (-1);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_checkword(char **ans, char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			ans[count] = (char *)malloc(sizeof(char) * j + 1);
			if (ans[count] == NULL)
				return (ft_free(ans, count));
			ft_strlcpy(ans[count], s + i, j + 1);
			i = i + j;
			count++;
		}
	}
	ans[count] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		len;

	len = ft_wordcount(s, c);
	ans = (char **)malloc(sizeof(char *) * (len + 1));
	if (ans == NULL)
		return (NULL);
	if (ft_checkword(ans, s, c) == -1)
		return (NULL);
	return (ans);
}

// int	main(void)
//  {
//  	int		index;
//  	char	**tab;
//  	tab = ft_split("AxBxCCCxDDDDxEExxxF", 'x');
//  	index = 0;
//  	while (tab[index])
//  	{
//  		free(tab[index++]);
//  	}
//  	free(tab);
//  	while (1);
//  }
// int	main(void)
// {
// 	int index;
// 	char **tab = ft_split("ss", "");
// 	printf("%s", tab[0]);
// 	index = 0;
// 	// while (tab[index])
// 	// {
// 	// 	free(tab[0][index++]);
// 	// }
// 	// free(tab);
// }