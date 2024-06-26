#include <stdio.h>
#include <stdlib.h>

    typedef struct habitantes{
        double salario;
        int idade;
        char sexo;
        int num_filhos;
    } Habitantes;

int main(){

    int qtd, i=0;
    double cont_sal_inferior=0.0;
    double menor_idade = 0.0,total_sal = 0.0,total_filhos=0.0, maior_sal=0.0;

    printf("Quantos usuários deseja cadastrar? \n ");
    scanf("%d",&qtd);
    Habitantes h[qtd];

    while (i != qtd){
        printf("\nDigite o salário da pessoa:\n ");
        scanf("%lf",&h[i].salario);
        total_sal += h[i].salario;
        maior_sal = h[i].salario;
        if (maior_sal> h[i].salario){
            maior_sal= h[i].salario;
        }

        printf("\nDigite a idade da pessoa:\n ");
        scanf("%d",&h[i].idade);
        menor_idade = h[i].idade;

        if (h[i].idade < menor_idade){
            menor_idade = h[i].idade; 
        }

        if (h[i].idade == 0) break;

        printf("\nDigite o sexo da pessoa (f ou m):\n ");
        scanf("%s",&h[i].sexo);

        printf("\nDigite o numero de filhos da pessoa:\n ");
        scanf("%d",&h[i].num_filhos);
        total_filhos += h[i].num_filhos;

        if (h[i].salario < 300 && h[i].sexo == 'f') cont_sal_inferior++;
        i++;
        printf("\n");
    }

    printf("Média de mulheres com salário menor de 300 reais: %.2lf\n",cont_sal_inferior/i);
    printf("Média de salário da população: %.2lf\n",total_sal/i);
    printf("Média de número de filhos: %.2lf\n",total_filhos/i);
    printf("Maior salário: %.2lf\n",maior_sal);
    printf("Menor idade: %.2lf\n",menor_idade);

}