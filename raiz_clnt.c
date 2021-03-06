/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "raiz.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

struct raiz *
resuelve_1(datos *argp, CLIENT *clnt)
{
	static struct raiz clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, RESUELVE,
		(xdrproc_t) xdr_datos, (caddr_t) argp,
		(xdrproc_t) xdr_raiz, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

struct complex *
complejo_1(datos *argp, CLIENT *clnt)
{
	static struct complex clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, COMPLEJO,
		(xdrproc_t) xdr_datos, (caddr_t) argp,
		(xdrproc_t) xdr_complex, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
