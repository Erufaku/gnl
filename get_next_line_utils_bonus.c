#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char*	ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(ft_strlen((s1)) + 1);
	if (!p)
		return (NULL);
	p = ft_memmove(p, s1, ft_strlen(s1) + 1);
	return (p);
}

void*	ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*ls;
	char		*ld;

	d = dst;
	s = src;
	if ((dst == (void *)0) && (src == (void *)0))
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		ls = (char *)(s + (len - 1));
		ld = (char *)(d + (len - 1));
		while (len--)
			*ld-- = *ls--;
	}
	return (dst);
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t 	dst_len;
	size_t 	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (!dstsize)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (src[j] && dst_len + j < dstsize)
		dst[i++] = src[j++];
	if (dst_len + j == dstsize && dst_len < dstsize)
		dst[--i] = '\0';
	else
		dst[i] = '\0';
	return (dst_len + src_len);
}

char 	*ft_strjoin(char const *s1, char const *s2)
{
	char *p;
	int i;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	p = (char *) malloc(i + 1);
	if (!p)
		return ((void *)0);
	p = ft_memmove(p, s1, ft_strlen(s1) + 1);
	ft_strlcat(p, s2, i + 1);
	return (p);
}