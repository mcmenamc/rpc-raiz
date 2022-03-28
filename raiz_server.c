#include "raiz.h"
#include <math.h>
struct raiz *
resuelve_1_svc(datos *argp, struct svc_req *rqstp)
{
    static struct raiz res;
    int temp;
    res.error = 0;
    temp = (argp->b * argp->b) - (4 * argp->a * argp->c);
    if (temp < 0)
        res.error = 1;
    else
    {
        res.r1 = (-argp->b + sqrt((double)temp)) / (2 * argp->a);
        res.r2 = (-argp->b - sqrt((double)temp)) / (2 * argp->a);
    }
    return (&res);
}
struct complex *
complejo_1_svc(datos *argp, struct svc_req *rqstp)
{
    static struct complex res;
    float temp;
    temp = (argp->b * argp->b) - (4 * argp->a * argp->c);
    res.real = (-argp->b) / (2 * argp->a);
    res.imag = (temp) / (2 * argp->a);
    return (&res);
}
