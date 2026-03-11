#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tipoVeiculo, tipoSeguro, idade, eixos = 0;
    float valorBase = 0, adicionalCat = 0;
    float adicionalIdade = 0;
    float custoCobertura = 0, valorTotal;
    float subtotal;

    printf("--- SISTEMA DE CALCULO DE SEGURO ---\n");

    // 1. Escolha do Veiculo
    do{
        printf("\nSelecione o tipo do veiculo:\n");
        printf("1. Passeio\n");
        printf("2. Carga Pesada\n");
        printf("3. Caminhonete\n");
        printf("4. Motocicleta (<1000cc)\n");
        printf("5. Motocicleta (1000cc+)\n");
        printf("Opcao: ");

        if(scanf("%d",&tipoVeiculo)!=1){
            while(getchar()!= '\n');
        }

        if(tipoVeiculo < 1 || tipoVeiculo > 5){
            printf("[ERRO] Opcao invalida! Tente novamente.\n");
        }

    }while(tipoVeiculo < 1 || tipoVeiculo > 5);


    // Definir valor base e adicional categoria
    if(tipoVeiculo >= 4){
        valorBase = 1200.00;

        if(tipoVeiculo == 4)
            adicionalCat = valorBase * 0.80;
        else
            adicionalCat = valorBase * 0.90;
    }
    else{
        valorBase = 1000.00;

        if(tipoVeiculo == 1)
            adicionalCat = valorBase * 0.10;
        else if(tipoVeiculo == 2)
            adicionalCat = valorBase * 0.20;
        else
            adicionalCat = valorBase * 0.33;
    }


    // 2.Idade
    do{
        printf("\nSelecione Idade:\n");
        printf("1. Menos de 25 anos\n");
        printf("2. Entre 25 a 29 anos\n");
        printf("3. 30 anos ou mais\n");
        printf("Opcao: ");

        if(scanf("%d",&idade)!=1){
            while(getchar()!= '\n');
        }

        if(idade < 1 || idade > 3){
            printf("[ERRO] Opcao invalida! Tente novamente.\n");
        }

    }while(idade < 1 || idade > 3);


    // Adicional idade
    if(idade == 1)
        adicionalIdade = valorBase * 0.15;
    else if(idade == 2)
        adicionalIdade = valorBase * 0.10;
    else
        adicionalIdade = valorBase * 0.05;


    // 3. Plano de cobertura
    do{
        printf("\nSelecione o plano de cobertura:\n");
        printf("1. Basico\n");
        printf("2. Parcial\n");
        printf("3. Completo\n");
        printf("Opcao: ");

        if(scanf("%d",&tipoSeguro)!=1){
            while(getchar()!= '\n');
        }

        if(tipoSeguro < 1 || tipoSeguro > 3){
            printf("[ERRO] Opcao invalida! Tente novamente.\n");
        }

    }while(tipoSeguro < 1 || tipoSeguro > 3);


    // Pedir eixos se for carga ou caminhonete
    if(tipoVeiculo == 2 || tipoVeiculo == 3){
        printf("Informe o numero de eixos: ");
        scanf("%d",&eixos);
    }


    // Subtotal
    subtotal = valorBase + adicionalCat + adicionalIdade;


    // Calculo da cobertura
    if(tipoVeiculo == 1){ // Passeio

        if(tipoSeguro == 1)
            custoCobertura = subtotal * -0.02;
        else if(tipoSeguro == 2)
            custoCobertura = subtotal * 0.02;
        else
            custoCobertura = subtotal * 0.10;
    }

    else if(tipoVeiculo == 2 || tipoVeiculo == 3){ // Carga ou Caminhonete

        if(tipoSeguro == 1)
            custoCobertura = subtotal * (0.03 * eixos);
        else if(tipoSeguro == 2)
            custoCobertura = subtotal * (0.05 * eixos);
        else
            custoCobertura = subtotal * (0.10 * eixos);
    }

    else if(tipoVeiculo == 4){ // Moto <1000cc

        if(tipoSeguro == 1)
            custoCobertura = subtotal * -0.05;
        else if(tipoSeguro == 2)
            custoCobertura = subtotal * 0.15;
        else
            custoCobertura = subtotal * 0.80;
    }

    else if(tipoVeiculo == 5){ // Moto >1000cc

        if(tipoSeguro == 1)
            custoCobertura = subtotal * 0.10;
        else if(tipoSeguro == 2)
            custoCobertura = subtotal * 0.20;
        else
            custoCobertura = subtotal * 1.00;
    }


    // Valor final
    valorTotal = subtotal + custoCobertura;


    // Relatorio final
    printf("\n----- RELATORIO DO SEGURO -----\n");
    printf("Valor Base: R$ %.2f\n", valorBase);
    printf("Adicional Categoria: R$ %.2f\n", adicionalCat);
    printf("Adicional Idade: R$ %.2f\n", adicionalIdade);
    printf("Valor Cobertura Plano: R$ %.2f\n", custoCobertura);
    printf("-------------------------------\n");
    printf("VALOR TOTAL FINAL: R$ %.2f\n", valorTotal);

    return 0;
}
