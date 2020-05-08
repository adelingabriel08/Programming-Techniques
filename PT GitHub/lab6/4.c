#include<stdio.h>
#include<string.h>
/*
OOP:
//ignore public keywords
class ceva{
    public string Nume;
    public int pret;
    public int dămiPretu()
    {
        return this.pret; // to ignore ish
    }
}
int main()
{
    ceva Obiect = new ceva();// to ignore 
    Obiect.Nume = "UnNumeRandom";
    Obiect.pret = 12;
    printf("%d\n", Obiect.dămiPretu(parametrii daca are functia ));
}
*/
struct ceva{
    char nume[256];
    int pret;
    int (*daPretu)(struct ceva);
};
int arataPretu(struct ceva object)
{
    return object.pret;
}
int main()
{
    struct ceva obiectul;
    strcpy(obiectul.nume, "UnNumeRandom");
    obiectul.pret = 12;
    obiectul.daPretu = &arataPretu; // mapez functia daPretu din struct la functia arataPretu, se apeleaza functia arataPretul cand o folosesti
                                    // pe cea din struct
    printf("Nume: %s\n", obiectul.nume);
    printf("Pretul: %d\n", obiectul.daPretu(obiectul));
    return 0;
}