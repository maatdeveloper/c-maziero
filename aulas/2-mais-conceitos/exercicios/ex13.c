#include <stdio.h>
#include <string.h>

struct Data
{
    int ano, mes, dia;
};
struct Hora
{
    int hora, minuto, segundo;
};
struct Datahora
{
    struct Data data;
    struct Hora hora;
};

struct Data le_data(int dia, int mes, int ano) {
    struct Data data;
    data.ano = ano;
    data.mes = mes;
    data.dia = dia;
    
    return data;
}

struct Hora le_hora(int hora, int minuto, int segundo) {
    struct Hora horar;
    horar.hora = hora;
    horar.minuto = minuto;
    horar.segundo = segundo;

    return horar;
}

struct Datahora le_datahora(struct Data data, struct Hora hora) {
    struct Datahora datahora;
    datahora.data = data;
    datahora.hora = hora;
    
    return datahora;
}

void esc_data(struct Data data) {
    printf("%.2d/%.2d/%.4d\n", data.dia, data.mes, data.ano);
}

void esc_hora(struct Hora hora) {
    printf("%.2d:%.2d:%.2d\n", hora.hora, hora.minuto, hora.segundo);
}

void esc_datahora(struct Datahora datahora) {
    printf("%.2d/%.2d/%.4d\t%.2d:%.2d:%.2d\n", datahora.data.dia,
                                   datahora.data.mes,
                                   datahora.data.ano,
                                   datahora.hora.hora,
                                   datahora.hora.minuto,
                                   datahora.hora.segundo);
}

int data_dias(struct Data data) {
    int total_dias = 0;
    total_dias += data.dia + (data.mes*30) + (data.ano*365);

    return total_dias;
}

int horas_segundos (struct Hora hora) {
    int total_segundos = 0;
    total_segundos += hora.segundo + (hora.minuto*60) + (hora.hora*3600);

    return total_segundos;
}

int dif_data(struct Data data1, struct Data data2) {
    int dias1 = data1.dia + (data1.mes*30) + (data1.ano*365);
    int dias2 = data2.dia + (data2.mes*30) + (data2.ano*365);
    int total_dias = dias1 - dias2;

    return total_dias;
}

int dif_segundos(struct Hora hora1, struct Hora hora2) {
    int seg1 = hora1.segundo + (hora1.minuto*60) + (hora1.hora*3600);
    int seg2 = hora2.segundo + (hora2.minuto*60) + (hora2.hora*3600);
    int total_segundos = seg1 - seg2;

    return total_segundos;
}

int main() {
    struct Data natal;
    struct Hora quatroE20;
    struct Datahora datahora;

    natal = le_data(25, 12, 2024);
    quatroE20 = le_hora(16, 20, 0);
    datahora = le_datahora(natal, quatroE20);

    esc_data(natal);
    esc_hora(quatroE20);
    esc_datahora(datahora);
    
    printf("Total de dias: %d\n", data_dias(natal));
    printf("Total de segundos: %d\n", horas_segundos(quatroE20));
    
    return 0;
}