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
    while (i < top) {
        if (stacka[i] > stacka[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int		in_chunk2(int stacka, int chunks[2500]) {
    int		j;

    j = 0;
    while (j < 2500) {
        if (stacka == chunks[j])
            return (1);
        j++;
    }
    return (0);
}

int		in_chunk(int stacka, int chunks[10][50], int i) {
    int		j;

    j = 0;
    while (j <= (chunks[9][49] == 0 ? 19 : 49)) {
        if (stacka == chunks[i][j])
            return (1);
        j++;
    }
    return (0);
}

int		index_smallest(int stacka[], int top, int exclude_val) {
    int		i;
    int		smallest_index;
    int		smallest_val;

    i = 0;
    smallest_index = 0;
    smallest_val = 2000000;
    while (i <= top) {
        if (stacka[i] <= smallest_val && stacka[i] > exclude_val) {
            smallest_val = stacka[i];
            smallest_index = i;
        }
        i++;
    }
    return (smallest_index);
}

int		index_biggest(int stacka[], int top, int exclude_val) {
    int		i;
    int		biggest_index;
    int		biggest_val;

    i = 0;
    biggest_index = 0;
    biggest_val = -1;
    while (i <= top) {
        if (stacka[i] >= biggest_val && stacka[i] < exclude_val) {
            biggest_val = stacka[i];
            biggest_index = i;
        }
        i++;
    }
    return (biggest_index);
}

void	complete2(int stacka[], int stackb[], int top[]) {
    int		ra;
    int		rra;

    ra = index_smallest(stackb, top[1], -1);
    rra = top[0] + 1 - ra;
    if (ra <= rra)
        while (ra > 0) {
            rotate(stacka, top[0]);
            write(1, "ra\n", 3);
            ra--;
        }
    else
        while (rra-- > 0) {
            reverse_rotate(stacka, top[0]);
            write(1, "rra\n", 4);
        }
    write(1, "pb\n", 3);
    pushB(stacka, stackb, top);
}

void	complete(int stacka[], int stackb[], int top[]) {
    int		ra;
    int		rra;

    ra = index_biggest(stackb, top[1], 200000);
    rra = top[1] + 1 - ra;
    if (ra <= rra)
        while (ra > 0) {
            rotate(stackb, top[1]);
            write(1, "rb\n", 3);
            ra--;
        }
    else
        while (rra-- > 0) {
            reverse_rotate(stackb, top[1]);
            write(1, "rrb\n", 4);
        }
    write(1, "pa\n", 3);
    pushA(stacka, stackb, top);
}

void	sortnew(int stack[2][5000], int top[], int chunks[3][2500], int j) {
    int		i;
    int		caught;
    int		ra;

    ra = 7000;
    caught = 0;
    i = 0;
    while (caught == 0) {
        if (in_chunk2(stack[0][i], chunks[j])) {
            ra = i;
            caught = 1;
        }
        i++;
    }
    if (caught == 1) {
        while (ra-- > 0) {
            rotate(stack[0], top[0]);
            write(1, "ra\n", 3);
        }
        pushB(stack[0], stack[1], top);
        write(1, "pb\n", 3);
    }
}

void	sort(int stack[2][5000], int top[], int chunks[10][50], int chunk) {
    int		i;
    int		caught;
    int		ra;

    ra = 7000;
    caught = 0;
    i = 0;
    while (caught == 0) {
        if (in_chunk(stack[0][i], chunks, chunk)) {
            ra = i;
            caught = 1;
        }
        i++;
    }
    while (ra-- > 0) {
        rotate(stack[0], top[0]);
        write(1, "ra\n", 3);
    }
    pushB(stack[0], stack[1], top);
    write(1, "pb\n", 3);
}

void	sort_2(int stack[2][5000], int top[], int chunks[10][50]) {
    int		i;
    int		j;

    j = 0;
    i = 0;
    while (j <= (chunks[9][49] == 0 ? 4 : 9)) {
        while (i++ <= (chunks[9][49] == 0 ? 19 : 49))
            sort(stack, top, chunks, j);
        j++;
        i = 0;
    }
    i = 0;
    while (i++ <= (chunks[9][49] == 0 ? 99 : 499))
        complete(stack[0], stack[1], top);
}

void	make_chunks2(int stacka[], int top[], int chunks[3][2500]) {
    int			i;
    int			j;

    i = 0;
    j = 1;
    chunks[0][0] = stacka[index_smallest(stacka, top[0], -1)];
    while (i < 3) {
        while (j < (top[0] + 1) / 4) {
            chunks[i][j] = stacka[index_smallest(stacka, top[0], chunks[i][j - 1])];
            j++;
        }
        i++;
        j = 1;
        if (i != 3)
            chunks[i][j - 1] = stacka[index_smallest(stacka, top[0], chunks[i - 1][((top[0] + 1) / 4) - 1])];
    }
    i = 0;
    j = 0;
    //
}

void	make_chunks(int stacka[], int top[], int chunks[10][50]) {
    int			i;
    int			j;

    i = 0;
    j = 1;
    chunks[0][0] = stacka[index_smallest(stacka, top[0], -1)];
    while (i < (top[0] == 99 ? 5 : 10)) {
        while (j < (top[0] == 99 ? 20 : 50)) {
            chunks[i][j] = stacka[index_smallest(stacka, top[0], chunks[i][j - 1])];
            j++;
        }
        i++;
        j = 1;
        if (i != (top[0] == 99 ? 5 : 10))
            chunks[i][j - 1] = stacka[index_smallest(stacka, top[0], chunks[i - 1][top[0] == 99 ? 19 : 49])];
    }
}

void	sort5(int stacka[], int stackb[], int top[]) {
    int		i;

    i = index_smallest(stacka, top[0], -1);
    if (i == 0)
        write(1, "pb\n", 3);
    else if (i == 1) {
        rotate(stacka, top[0]);
        write(1, "ra\npb\n", 6);
    }
    else if (i == 2) {
        rotate(stacka, top[0]);
        rotate(stacka, top[0]);
        write(1, "ra\nra\npb\n", 9);
    }
    else if (i == 3) {
        reverse_rotate(stacka, top[0]);
        reverse_rotate(stacka, top[0]);
        write(1, "rra\nrra\npb\n", 11);
    }
    else {
        reverse_rotate(stacka, top[0]);
        write(1, "rra\npb\n", 7);
    }
    pushB(stacka, stackb, top);
}

void	sort3(int stacka[]) {
    if (stacka[2] > stacka[0] && stacka[1] > stacka[2])
        write(1, "rra\nsa\n", 7);
    if (stacka[0] > stacka[1] && stacka[2] > stacka[0])
        write(1, "sa\n", 3);
    if (stacka[0] > stacka[2] && stacka[1] > stacka[0])
        write(1, "rra\n", 4);
    if (stacka[2] > stacka[1] && stacka[0] > stacka[2])
        write(1, "ra\n", 3);
    if (stacka[1] > stacka[2] && stacka[0] > stacka[1])
        write(1, "ra\nsa\n", 6);
}

void stack_init_2(int stack[2][5000], int top[], int argc, char **argv) {
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

void stack_init_1(int stack[2][5000], int top[], char **argv) {
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

int main(int argc, char **argv) {
    int stack[2][5000];
    int top[3];
    int chunks[10][50];

    top[0] = -1;
    top[1] = -1;
    int chunks2[3][2500] = {0};
    if (argc == 2)
        stack_init_1(stack, top, argv);
    else if (argc > 2)
        stack_init_2(stack, top, argc, argv);
    else
        return (0);
    if (has_duplicate(stack[0], top[0])) {
        write(1, "Error", 5);
        return (0);
    }
    top[2] = 0;
    if (is_ordered(stack[0], top[0]))
        return (0);
    if (top[0] == 1)
        write(1, "sa\n", 3);
    else if (top[0] == 2)
        sort3(stack[0]);
    else if (top[0] == 4) {
        sort5(stack[0], stack[1], top);
        sort5(stack[0], stack[1], top);
        sort3(stack[0]);
        write(1, "pa\npa\n", 6);
    }
    else if (top[0] != 99 && top[0] != 499) {
        make_chunks2(stack[0], top, chunks2);
        while (top[2]++ < (top[0] + 1) / 4)
            sortnew(stack, top, chunks2, 0);
        top[2] = 0;
        while (top[2]++ < (top[0] + 1) / 4)
            sortnew(stack, top, chunks2, 1);
        top[2] = 0;
        while (top[2]++ < (top[0] + 1) / 4)
            sortnew(stack, top, chunks2, 2);
        while (top[0] != -1) {
            write(1, "pb\n", 3);
            pushB(stack[0], stack[1], top);
        }
        while (top[1] != -1)
            complete(stack[0], stack[1], top);
    }
    else {
        make_chunks(stack[0], top, chunks);
        sort_2(stack, top, chunks);
    }
    return (0);
}