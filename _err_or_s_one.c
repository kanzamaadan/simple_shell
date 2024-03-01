#include "shell.h"


/**
 * err_or_pri_nt - this prints error message
 * @info: parameter & return info struct
 * @es_tr: str containing specified error_type
 * Return: 0 if no nums in str, converted number otherwise
 * -1 on error
 */
void err_or_pri_nt(info_t *info, char *es_tr)
{
my_ep_uts(info->fnom);
my_ep_uts(": ");
_d_pri_nt(info->line_count, STDERR_FILENO);
my_ep_uts(": ");
my_ep_uts(info->argv[0]);
my_ep_uts(": ");
my_ep_uts(es_tr);
}

/**
 * _comnts_rm - func replaces 1st instance of '#' with '\0'
 * @bff: address of str to modify
 * Return: always 0
 */
void _comnts_rm(char *bff)
{
int y;

for (y = 0; bff[y] != '\0'; y++)
if (bff[y] == '#' && (!y || bff[y - 1] == ' '))
{
bff[y] = '\0';
break;
}
}



/**
 * my_er_ra_toi - this converts str to int
 * @z: str to be converted
 * Return: 0 if no numbers in str, converted number otherwise
 * -1 on error
 */
int my_er_ra_toi(char *z)
{
int y = 0;
unsigned long int rslt = 0;

if (*z == '+')
z++;
for (y = 0;  z[y] != '\0'; y++)
{
if (z[y] >= '0' && z[y] <= '9')
{
rslt *= 10;
rslt += (z[y] - '0');
if (rslt > INT_MAX)
return (-1);
}
else
return (-1);
}
return (rslt);
}


/**
 * _d_pri_nt - func prints decimal number (base 10)
 * @inpt: input
 * @fld: filedescriptor
 * Return: number of chars printed
 */
int _d_pri_nt(int inpt, int fld)
{
int (*__putchar)(char) = _putchar;
int y, county = 0;
unsigned int _abs_, currnt;

if (fld == STDERR_FILENO)
__putchar = _E_Put_Charc;
if (inpt < 0)
{
_abs_ = -inpt;
__putchar('-');
county++;
}
else
_abs_ = inpt;
currnt = _abs_;
for (y = 1000000000; y > 1; y /= 10)
{
if (_abs_ / y)
{
__putchar('0' + currnt / y);
county++;
}
currnt %= y;
}
__putchar('0' + currnt);
county++;

return (county);
}


/**
 * _num_conv - this converter function, clone of itoa
 * @num: number
 * @ba_se: base
 * @fla_gy_s: argument flagys
 * Return: str
 */
char *_num_conv(long int num, int ba_se, int fla_gy_s)
{
static char *ar_r;
static char buffer[50];
char signy = 0;
char *pntr;
unsigned long u = num;

if (!(fla_gy_s & CONVERT_UNSIGNED) && num < 0)
{
u = -num;
signy = '-';
}
ar_r = fla_gy_s & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
pntr = &buffer[49];
*pntr = '\0';

do	{
*--pntr = ar_r[u % ba_se];
u /= ba_se;
} while (u != 0);

if (signy)
*--pntr = signy;
return (pntr);
}
