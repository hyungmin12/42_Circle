/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:36:13 by hyyoo             #+#    #+#             */
/*   Updated: 2022/07/15 16:36:26 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

long long	ft_word_count(char *str, char *charset)
{
	long long	count;

	count = 0;
	while (*str)
	{
		if (!ft_is_charset(*str, charset))
		{
			count++;
			while (*str && (!(ft_is_charset(*str, charset))))
				str++;
		}
		str++;
	}
	return (count);
}

void	ft_strcpy(char *dest, char *src, char *until)
{
	while (src < until)
		*(dest++) = *(src++);
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	char		**ret;
	long long	idx;
	char		*src;

	ret = (char **)malloc(sizeof(char *) * ft_word_count(str, charset) + 1);
	idx = 0;
	while (*str)
	{
		if (!ft_is_charset(*str, charset))
		{
			src = str;
			while (*str && (!ft_is_charset(*str, charset)))
				str++;
			ret[idx] = (char *)malloc(str - src + 1);
			ft_strcpy(ret[idx++], src, str);
		}
		str++;
	}
	ret[idx] = 0;
	return (ret);
}
