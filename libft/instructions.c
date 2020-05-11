/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:32:04 by tphiland          #+#    #+#             */
/*   Updated: 2019/09/17 12:07:05 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    swap(int stack[])
{
    int temp;
    
    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
}

void    rotate(int stack[], int top)
{
    int    i;
    int temp;
    
    i = 0;
    temp = stack[0];
    while (i < top)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[i] = temp;
}

void    reverse_rotate(int stack[], int top)
{
    int    i;
    int temp;
    
    i = top;
    temp = stack[top];
    while (i > 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[i] = temp;
}

void    pushB(int stackA[], int stackB[], int top[])
{
    int i;
    int temp;
    
    i = 1;
    temp = stackA[0];
    while (i <= top[0])
    {
        stackA[i - 1] = stackA[i];
        i++;
    }
    i = top[1];
    while (i >= 0)
    {
        stackB[i + 1] = stackB[i];
        i--;
    }
    stackB[0] = temp;
    top[0]--;
    top[1]++;
}

void    pushA(int stackA[], int stackB[], int top[])
{
    int i;
    int temp;
    
    i = 1;
    temp = stackB[0];
    while (i <= top[1])
    {
        stackB[i - 1] = stackB[i];
        i++;
    }
    i = top[0];
    while (i >= 0)
    {
        stackA[i + 1] = stackA[i];
        i--;
    }
    stackA[0] = temp;
    top[1]--;
    top[0]++;
}
