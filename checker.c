#include "libft/libft.h"

int		has_duplicate(int stacka[], int top) {
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < top)
    {
        while (j <= top)
        {
            if (stacka[i] == stacka[j])
                return (1);
            j++;
        }
        i++;
        j = i + 1;
    }
    return (0);
}

int	is_ordered(int stacka[], int top) {
    int i;

    i = 0;
    while (i < top)
    {
        if (stacka[i] > stacka[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void stack_init_2(int stack[2][5000], int top[2], int argc, char **argv) {
    int i;

    i = 0;
    while (i < argc - 1) {
        if ((!ft_atoi(argv[i + 1]) && argv[i + 1][0] != '0') || \
                    ft_atoi(argv[i + 1]) < 0 || \
                    ft_strlen(argv[i + 1]) > 10) {
            write(1, "Error", 5);
            exit(0);
        }
        stack[0][i] = ft_atoi(argv[i + 1]);
        i++;
        top[0]++;
    }
}

void stack_init_1(int stack[2][5000], int top[2], char **argv) {
    int i;
    char **array;

    i = 0;
    array = ft_strsplit(argv[1], ' ');
    while (array[i]) {
        if ((!ft_atoi(array[i]) && array[i][0] != '0') || \
                    ft_atoi(array[i]) < 0 || \
                    ft_strlen(array[i]) > 10) {
            write(1, "Error", 5);
            exit(0);
        }
        stack[0][i] = ft_atoi(array[i]);
        i++;
        top[0]++;
    }
    i--;
    while (i >= 0)
        free(array[i--]);
    free(array);
}

void apply_command(int stacka[], int stackb[], int top[], char **line) {
    if (!ft_strcmp("pa", *line))
        pushA(stacka, stackb, top);
    else if (!ft_strcmp("pb", *line))
        pushB(stacka, stackb, top);
    else if (!ft_strcmp("ra", *line))
        rotate(stacka, top[0]);
    else if (!ft_strcmp("rb", *line))
        rotate(stackb, top[1]);
    else if (!ft_strcmp("sa", *line))
        swap(stacka);
    else if (!ft_strcmp("sb", *line))
        swap(stackb);
    else if (!ft_strcmp("rra", *line))
        reverse_rotate(stacka, top[0]);
    else if (!ft_strcmp("rrb", *line))
        reverse_rotate(stackb, top[1]);
    else if (ft_strcmp("rr", *line) != 0 && ft_strcmp("rrr", *line) != 0) {
        write(1, "Error", 5);
        exit(0);
    }
}

int main(int argc, char **argv) {
    int stack[2][5000];
    int top[2];
    char *line[1000000];

    top[0] = -1;
    top[1] = -1;
    if (argc == 2)
        stack_init_1(stack, top, argv);
    else if (argc > 2)
        stack_init_2(stack, top, argc, argv);
    else
        return(0);
    if (has_duplicate(stack[0], top[0]))
        write(1, "Error", 5);
    if (!has_duplicate(stack[0], top[0]))
    while (get_next_line(0, line) >= 1)
        apply_command(stack[0], stack[1], top, line);
    if (!has_duplicate(stack[0], top[0]) && is_ordered(stack[0], top[0]) && top[1] == -1)
        write(1, "OK", 2);
    else if (!has_duplicate(stack[0], top[0]))
        write(1, "KO", 2);
    return 0;
}