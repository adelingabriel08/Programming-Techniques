#include <stdio.h>

typedef struct _table
{
    unsigned int id, marked;
    char repair_type[256];
    unsigned long long IMEI;
    float price, investment, profit, total_profit, total_influx;
} entity;

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rab");
    if (!f)
    {
        perror("File not found or command argument missing");
        return 0;
    }
    int op;
    printf("Enter option: 0 - Add, 1 - Delete, 2 - Display by IMEI, 3 - Mark or Unmark\n");
    scanf(" %d", &op);
    int counter = 0;
    float profit = 0, influx = 0;
    switch (op)
    {
    case 0:
    {
        entity newEntity;
        printf("Enter Repair Type: ");
        scanf("%s", newEntity.repair_type);
        printf("Enter IMEI: ");
        scanf(" %llu", &newEntity.IMEI);
        printf("Enter price: ");
        scanf(" %f", &newEntity.price);
        printf("Enter investment: ");
        scanf(" %f", &newEntity.investment);
        newEntity.profit = newEntity.price - newEntity.investment;
        newEntity.marked = 0;
        newEntity.total_influx = 0;
        newEntity.total_profit = 0;
        profit += newEntity.profit;
        influx += newEntity.price;
        FILE *output = fopen("temp.bdb", "wb");
        entity aux;
        if (fread(&aux, sizeof(entity), 1, f))
        {
            aux.total_profit = profit;
            aux.total_influx = influx;
            counter++;
            fwrite(&aux, sizeof(entity), 1, output);
            while (fread(&aux, sizeof(entity), 1, f))
            {
                fwrite(&aux, sizeof(entity), 1, output);
                counter++;
            }
        }
        else
        {
            newEntity.total_profit = profit;
            newEntity.total_influx = influx;
        }
        newEntity.id = counter++;
        fwrite(&newEntity, sizeof(entity), 1, output);
        remove(argv[1]);
        rename("temp.bdb", argv[1]);
        break;
    }
    case 1:
    {
        unsigned int id;
        printf("Enter the entity id to delete it: ");
        scanf(" %u", &id);
        FILE *output = fopen("temp.bdb", "wb");
        entity aux;
        int count = 0;
        while (fread(&aux, sizeof(entity), 1, f))
        {
            if (aux.id == id)
            {
                counter--;
            }
            else
            {
                aux.id = count;
                fwrite(&aux, sizeof(entity), 1, output);
                count++;
            }
            counter++;
        }
        remove(argv[1]);
        rename("temp.bdb", argv[1]);
        break;
    }
    case 2:
    {
        unsigned long long IMEI;
        printf("Enter the IMEI: ");
        scanf(" %llu", &IMEI);
        entity aux;
        while (fread(&aux, sizeof(entity), 1, f))
        {
            if (aux.IMEI == IMEI)
            {
                printf("%d | %s | %llu | %f | %f | %f | %f | %f | %u\n", aux.id, aux.repair_type, aux.IMEI, aux.price, aux.investment, aux.profit, aux.total_profit, aux.total_influx, aux.marked);
            }
        }
        break;
    }
    case 3:
    {
        unsigned long long IMEI;
        unsigned mark;
        printf("Enter the IMEI: ");
        scanf(" %llu", &IMEI);
        printf("Mark or unmark? 0/1: ");
        scanf("%u", &mark);
        FILE *output = fopen("temp.bdb", "wb");
        entity aux;
        while (fread(&aux, sizeof(entity), 1, f))
        {
            if (aux.IMEI == IMEI && aux.marked != mark)
                aux.marked = mark;
            fwrite(&aux, sizeof(entity), 1, output);
        }
        remove(argv[1]);
        rename("temp.bdb", argv[1]);
        break;
    }
    }
    return 0;
}