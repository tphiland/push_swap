#include "libft/libft.h"

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

void	complete(int stacka[], int stackb[], int top[2]) {
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
        while (rra > 0) {
            reverse_rotate(stackb, top[1]);
            write(1, "rrb\n", 4);
            rra--;
        }
    write(1, "pa\n", 3);
    pushA(stacka, stackb, top);
}

void	sort(int stack[2][500], int top[2], int chunks[10][50], int chunk) {
    int		i;
    int		caught;
    int		ra;

    ra = 1000;
    caught = 0;
    i = 0;
    while (stack[0][i] && caught == 0) {
        if (in_chunk(stack[0][i], chunks, chunk)) {
            ra = i;
            caught = 1;
        }
        i++;
    }
    while (ra > 0) {
        rotate(stack[0], top[0]);
        write(1, "ra\n", 3);
        ra--;
    }
    pushB(stack[0], stack[1], top);
    write(1, "pb\n", 3);
}

void	sort_2(int stack[2][500], int top[2], int chunks[10][50]) {
    int		i;
    int		j;

    j = 0;
    i = 0;
    while (j <= (chunks[9][49] == 0 ? 4 : 9)) {
        while (i <= (chunks[9][49] == 0 ? 19 : 49)) {
            sort(stack, top, chunks, j);
            i++;
        }
        j++;
        i = 0;
    }
    i = 0;
    while (i <= (chunks[9][49] == 0 ? 99 : 499)) {
        complete(stack[0], stack[1], top);
        i++;
    }
}

void	make_chunks(int stacka[], int top[2], int chunks[10][50]) {
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

void	sort5(int stacka[], int stackb[], int top[2]) {
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

void stack_init_2(int stack[2][500], int top[2], int argc, char **argv) {
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

void stack_init_1(int stack[2][500], int top[2], char **argv) {
    int i;
    char **array;

    i = 0;
    array = ft_strsplit(argv[1], ' ');
    while (array[i]) {
        stack[0][i] = ft_atoi(array[i]);
        i++;
        top[0]++;
    }
    i--;
    while (i >= 0) {
        free(array[i]);
        i--;
    }
    free(array);
}

int main(int argc, char **argv) {
    int stack[2][500];
    int top[2];
    int chunks[10][50];

    top[0] = -1;
    top[1] = -1;
    if ((argc == 2 && ft_strlen(argv[1]) < 5) || argc == 5 || argc == 11)
        return (0);
    if (argc == 2)
        stack_init_1(stack, top, argv);
    if (argc > 2)
        stack_init_2(stack, top, argc, argv);

    if (top[0] == 2)
        sort3(stack[0]);
    else if (top[0] == 4) {
        sort5(stack[0], stack[1], top);
        sort5(stack[0], stack[1], top);
        sort3(stack[0]);
        write(1, "pa\npa\n", 6);
    }
    else {
        make_chunks(stack[0], top, chunks);
        sort_2(stack, top, chunks);
    }

    return (0);
}