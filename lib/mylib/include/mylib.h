/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:54:43 by eguelin           #+#    #+#             */
/*   Updated: 2023/06/22 13:54:27 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_double_list
{
	void					*content;
	struct s_double_list	*previous;
	struct s_double_list	*next;
}	t_dlist;

////////// [ dlst ] //////////
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
void	ft_dlstclear(t_dlist **dlst, void (*del)(void*));
void	ft_dlstdelone(t_dlist *dlst, void (*del)(void*));
t_dlist	*ft_dlstfirst(t_dlist *dlst);
t_dlist	*ft_dlstlast(t_dlist *dlst);
t_dlist	*ft_dlstnew(void *content);
int		ft_dlstsize(t_dlist *dlst);

////////// [ get ] //////////
char	*get_next_line(int fd);

////////// [ is ] //////////
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

////////// [ lst ] //////////
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

////////// [ mem ] //////////
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

////////// [ other ] //////////
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_free_split(char **tab);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_tolower(int c);
int		ft_toupper(int c);

////////// [ print ] //////////
int		ft_print_address(unsigned long un);
int		ft_print_all(char c, va_list arg);
int		ft_print_base(unsigned long un, unsigned long size_set, char *set);
int		ft_print_char(char c);
int		ft_print_nbr(int n);
int		ft_print_str(const char *s);
int		ft_printf(const char *format, ...);

////////// [ print_error ] //////////
int		ft_print_error_address(unsigned long un);
int		ft_print_error_all(char c, va_list arg);
int		ft_print_error_base(unsigned long un, unsigned long size_set, \
char *set);
int		ft_print_error_char(char c);
int		ft_print_error_nbr(int n);
int		ft_print_error_str(const char *s);
int		ft_printf_error(const char *format, ...);

////////// [ print_fd ] //////////
int		ft_print_fd_address(unsigned long un, int fd);
int		ft_print_fd_all(char c, va_list arg, int fd);
int		ft_print_fd_base(unsigned long un, unsigned long size_set, \
char *set, int fd);
int		ft_print_fd_char(char c, int fd);
int		ft_print_fd_nbr(int n, int fd);
int		ft_print_fd_str(const char *s, int fd);
int		ft_printf_fd(int fd, const char *format, ...);

////////// [ put ] //////////
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

////////// [ str ] //////////
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin_tab(char **tab);
char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
