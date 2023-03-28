#include "main.h"

/**
 * print_buffer - A local buffer that calls write
 * @buffer: A char buffer array
 * @buff_ind: A buffer resetter
 * Return: void
 */

void print_buffer(char buffer[], int *buff_ind)
{
	/*static char local_buffer[1024];*/
	int local_buff_ind = 0;

	for (int i = 0; i < *buff_ind; i++)
	{
		local_buffer[local_buff_ind++] = buffer[i];
		/* If the local buffer is full, write its content */
	if (local_buff_ind == 1024)
	{
		write(1, local_buffer, 1024);
		local_buff_ind = 0;
	}
	}
	/* Reset the input buffer index */
	*buff_ind = 0;
	/* Write any remaining characters in the local buffer to the console */
	if (local_buff_ind > 0)
	{
		write(1, local_buffer, local_buff_ind);
	}
}
