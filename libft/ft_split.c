/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:07:24 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/26 16:07:29 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*static int	cnt_word(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}*/

static int	len_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static int	cnt_word(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	make_free(char **str, int idx)
{
	while (idx-- > 0)
		free(str[idx]);
	free(str);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		size;
	char	**ret;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	if (!(ret = (char **)malloc((word + 1) * sizeof(char *))))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		if (!(ret[j] = ft_substr(s, i, size)))
		{
			make_free(ret, j);
			return (NULL);
		}
		i += size;
	}
	ret[j] = 0;
	return (ret);
}
