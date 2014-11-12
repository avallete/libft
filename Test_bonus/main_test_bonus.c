#include <libft.h>
#include <stdio.h>

t_list	*test_listpushback(void)
{
	t_list	*listchar;
	t_list	*listchar2;
	t_list	*listchar3;
	char	*a;
	char	*b;
	char	*c;

	a = "A";
	b = "B";
	c = "C";
	printf("Test list pushback expect result : ABC\n");
	listchar = ft_lstnew(a, sizeof(char));
	listchar2 = ft_lstnew(b, sizeof(char));
	listchar3 = ft_lstnew(c, sizeof(char));
	ft_lstpushback(&listchar, listchar2);
	ft_lstpushback(&listchar, listchar3);
	a = (char*)listchar->content;
	b = (char*)listchar->next->content;
	c = (char*)listchar->next->next->content;
	printf("%s->%s->%s\n", a, b, c);
	return (listchar);
}

void	test_listsize(t_list *list)
{
	size_t i;

	printf("Test ft_lstsize, Expect: 2\n");
	i = ft_lstsize(list);
	printf("%d\n", (int)i);
}

void	test_listlast(t_list *list)
{
	t_list *last;

	printf("Test ft_lstlast content, Expect: C\n");
	last = ft_lstlast(list);
	printf("%s\n", (char*)last->content);
}

t_tree	*test_treenew(void)
{
	t_tree	*new;
	char	*a;

	a = "A";
	new = ft_treenew(a, sizeof(a));
	printf("Test ft_treenew, expect result: A, NULL, NULL\n");
	printf("Tree = \n\n		%s		\n	/		\\\n%s			%s\n", (char*)new->content, (char*)new->left, (char*)new->right);
	return (new);
}

void	test_nodeadd(t_tree *tree)
{
	t_tree *father;
	t_tree *left;
	t_tree *right;
	char	*b;
	char	*c;

	father = tree;
	b = "B";
	c = "C";
	left = ft_treenew(b, sizeof(b));
	right = ft_treenew(c, sizeof(c));
	ft_nodeaddleft(left, &father);
	ft_nodeaddright(right, &father);
	printf("\nTest ft_nodeadd* : \n");
	printf("Tree = \n\n		%s		\n	|		|\n	%s		%s\n", (char*)father->content, (char*)father->left->content, (char*)father->right->content);
}

void	test_calloc(void)
{
	char *s;

	printf("\nTest ft_calloc Expect : Titi\n");
	s = (char*)ft_calloc(sizeof(char), 30);
	s[0] = 'T';
	s[1] = 'i';
	s[2] = 't';
	s[3] = 'i';
	s[5] = '0';
	s[30] = '0';
	printf("%s\n", s);
}

void test_ft_realloc(void)
{
	char *s = "Voila un beau test";
	char *d;

	d = ft_strnew(ft_strlen(s) + 1);
	ft_memcpy(d, s, ft_strlen(s) + 1);
	printf("\nTest ft_realloc:\nBase string: %s\nExpect: 'Voila un beau'\n", d);
	d = ft_realloc(d, ft_strlen(d) - 5);
	printf("Result : '%s'\n", d);
}

int main(void)
{
	t_list *list;
	t_tree *tree;

	list = test_listpushback();
	if (list)
	{
		test_listsize(list);
		test_listlast(list);
	}
	tree = test_treenew();
	if (tree)
		test_nodeadd(tree);
	test_calloc();
	test_ft_realloc();
	return (0);
}
