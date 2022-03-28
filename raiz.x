struct datos{
    float a;
    float b;
    float c;
};
struct raiz {
    float r1;
    float r2;
    int error;
};
struct complex {
    float real;
    float imag;
};
program RAIZ_PROG {
    version RAIZ_VERS{
        struct raiz RESUELVE(datos) = 1;
        struct complex COMPLEJO(datos) = 2;
        } = 1;
} = 2;
