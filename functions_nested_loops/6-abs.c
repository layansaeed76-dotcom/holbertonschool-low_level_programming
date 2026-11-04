cat > 6-abs.c <<'EOF'
#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @n: number to check
 *
 * Return: absolute value of n
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);

	return (n);
}
EOF
