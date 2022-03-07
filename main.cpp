#include"Liste.hpp"
#include<stdio.h>

int main(){
    Liste l2 = Liste(5);
    printf("\n ------affichage du liste : -----------");
    l2.see();
    printf("\n -------liste.append(10.0) ----------");
    l2.append(10.0);
    l2.see();
    printf("\n -------liste.insert(1,15.0)----------");
    l2.insert(1,15.0);
    l2.see();
    printf("\n -------liste.insert(2,18.0)----------");
    l2.insert(2,18.0);
    l2.see();
    printf("\n -------liste.pop()----------");
    l2.pop();
    l2.see();
    printf("\n -------liste.delet(1)----------");
    l2.delet(1);
    l2.see();
    printf("\n -------liste.delet(3)----------");
    l2.delet(3);
    l2.see();
    printf("\n -------liste.sort(false)----------");
    l2.sort(false);
    l2.see();
    printf("\n -------liste.sort(true)----------");
    l2.sort(true);
    l2.see();
    printf("\n -------liste.extract(0,3)----------");
    Liste temp = l2.extract(0,3);
    temp.see();
    printf("\n -------liste.extend(temp.tab)----------");
    l2.extend(temp.get_tab());
    l2.see();
    printf("\n --------autre resultats : ---------");
    int index_of_7 = l2.index(7);
    float max_all = l2.max();
    float min_all = l2.min();
    float max_1 = l2.max(1);
    float min_1 = l2.min(1);
    float max_3_5 = l2.max(2,5);
    float min_3_5 = l2.min(2,5);
    // affichage des resultats :     
    printf("\n if 3.0 in liste : %d ",l2.in(3.0));
    printf("\n ocurr 3.0 in liste : %d ",l2.occur(3.0));
    return 0;
}