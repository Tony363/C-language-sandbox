#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

typedef struct profile{
    char name[100];
    char plan;
    int talk_minutes;
    int data_MB;
    double charges;
} Profile;

double plan_a(Profile a){
    double talk_charge=0,data_charge=0,monthly_charge=60;
    if (a.talk_minutes > 1000){
        talk_charge = (a.talk_minutes - 1000) * 0.5;
    }
    if (a.data_MB > 10000){
        data_charge = (a.data_MB - 10000) * 0.25;
    }
    return talk_charge+data_charge+monthly_charge;
}

double plan_b(Profile b){
    double talk_charge=0,data_charge=0,monthly_charge=85;
    if (b.talk_minutes > 2000){
        talk_charge = (b.talk_minutes - 2000) * 0.4;
    }
    if (b.data_MB > 20000){
        data_charge = (b.data_MB - 20000) * 0.15;
    }
    return talk_charge+data_charge+monthly_charge;
}

void alph_sort(Profile profiles[],int n){
    char temp[100];
    for (int i = 0; i < n - 1 ; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(profiles[j].name, profiles[i].name) > 0){
                strcpy(temp, profiles[i].name);
                strcpy(profiles[i].name, profiles[j].name);
                strcpy(profiles[j].name, temp);
            }
        }
    }
}

int main (void){
    double min=INT_MAX,max=0,total=0,average;
    int count = 0,iter=0;
    Profile profile_array[100];
    Profile person;
    char str[100] = {0};
    FILE *file = fopen("Texts/customers.txt","r");
    if (file){
        while (fgets(str,100,file)){
            if (count == 0){
                strcpy(person.name,str);
                profile_array[iter] = person;
                count++;
            }else if (count == 1){
                person.plan = str[0];
                count++;
            }else if (count == 2){
                person.talk_minutes = atoi(str);
                count++;
            }else {
                person.data_MB = atoi(str);
                count=0;
                iter++;
                profile_array[iter] = person;
                if (profile_array[iter].plan == 'A'){
                    profile_array[iter].charges = plan_a(profile_array[iter]);
                    if (profile_array[iter].charges<min){
                        min = profile_array[iter].charges;
                    }
                    if (profile_array[iter].charges>max){
                        max = profile_array[iter].charges;
                    }
                }else {
                    profile_array[iter].charges = plan_b(profile_array[iter]);
                    if (profile_array[iter].charges<min){
                        min = profile_array[iter].charges;
                    }
                    if (profile_array[iter].charges>max){
                        max = profile_array[iter].charges;
                    }
                }
                total = total + profile_array[iter].charges;
                average = total/iter;
            }
        }
        fclose(file);
        alph_sort(profile_array,iter);
        FILE *f = fopen("Texts/charges.txt","w");
        if(f == NULL){
            printf("Error opening file!\n");
            exit(1);
        }
        fprintf(f, "Total: %.2f\n", (float)total);
        fprintf(f, "Average: %.2f\n", (float)average);
        fprintf(f, "Max: %.2f\n", (float)max);
        fprintf(f, "Min: %.2f\n", (float)min);
        fclose(f);
    }else{
        printf("file does not exist\n");
    }
    return 0;
}