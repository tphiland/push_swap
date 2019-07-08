/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:50:52 by tphiland          #+#    #+#             */
/*   Updated: 2019/07/08 17:56:26 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//initialize an empty stack
void	stackInit(stackT *stackP, int maxSize)
{
	stackElementT *newContents;

	newContents = (stackElementT *)malloc(sizeof(stackElementT) * maxSize);
	if (newContents == NULL)
		return (NULL);

	stackP->contents = newContents;
	stackP->maxSize = maxSize;
	stackP->top = -1 //i.e empty//
}

int		isEmpty(stackT *stackP)
{
	return (stackP->top < 0);
}

int		isFull(stackT *stackP)
{
	return (stackP->top >= stackP->maxSize - 1);
}

//push onto stack
void	stackPush(stackT *stackP, stackElementT element)
{
	stackP->contents[++stackP->top] = element;
}

void	stackPop(stackT *stackP)
{
	stackP->contents[stackP->top--];
}

//main starts here
int main()
{
	stackT s1, s2; //when u need stacks..initialise them
	


}
