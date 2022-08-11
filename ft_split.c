/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:02:44 by hyyoo             #+#    #+#             */
/*   Updated: 2022/08/08 17:40:22 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_word(char *word, char const *s, int k, int word_len)
{
	int		i;

	i = 0;
	while (word_len > 0)
	{
		word[i++] = s[k - word_len--];
	}
	word[i] = '\0';
	return (word);
}

char	**split(char **ret, char const *s, char c, int num)
{
	int		i;
	int		k;
	int		word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < num)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		ret[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!ret)
			return (NULL);
		make_word(ret[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	word_cnt(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		num;

	if (s == 0)
		return (NULL);
	num = word_cnt(s, c);
	ret = (char **)malloc(sizeof(char *) * (num + 1));
	if (!ret)
		return (NULL);
	split(ret, s, c, num);
	return (ret);
}
