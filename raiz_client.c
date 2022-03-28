#include "raiz.h"
#include <math.h>
CLIENT *clnt;
struct raiz *raices;
datos data;
struct complex *rescom;
int main(argc, argv) int argc;
char *argv[];
{
	char *host;
	if(argc != 5)
	{
		printf("uso: %s host a b c \n", argv[0]);
		exit(1);
	}
	host = argv[1];
	data.a = (float)atoi(argv[2]);
	data.b = (float)atoi(argv[3]);
	data.c = (float)atoi(argv[4]);
	clnt = clnt_create(host, RAIZ_PROG, RAIZ_VERS, "udp");
	if (clnt == (CLIENT *)NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
	raices = resuelve_1(&data, clnt);
	if (raices == (struct raiz *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	if (!raices->error)
	{
		printf("La solucion de (%.1f %.1f %.1f)\n", data.a, data.b, data.c);
		printf("es %.5f y %.5f\n", raices->r1, raices->r2);
	}
	else
	{
		rescom = complejo_1(&data, clnt);
		if (rescom == (struct complex *)NULL)
		{
			clnt_perror(clnt, "call failed");
		}
		printf("La solucion de (%.1f %.1f %.1f)\n", data.a, data.b, data.c);
		printf("es (%.5f %.5fj) y (%.5f %.5fj)\n", rescom->real, rescom->imag,
			   rescom->real, (-1) * (rescom->imag));
	}
	clnt_destroy(clnt);
}