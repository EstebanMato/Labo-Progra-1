#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED

Employee* employee_new();//listo
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);// lista
int employee_delete(Employee* this);//lista retorna -1 si no lo encontro o 0 si lo encontro y libero

int employee_setId(Employee* this,int id);//lista
int employee_getId(Employee* this,int* id);//retorna si esta ok o no. Y el get lo hace directamente al puntero que le pasamos

int employee_setNombre(Employee* this,char* nombre);//listo valida longitud
int employee_getNombre(Employee* this,char* nombre);//listo

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);//listo
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);// lista

int employee_setSueldo(Employee* this,int sueldo);//listo
int employee_getSueldo(Employee* this,int* sueldo);//lista
