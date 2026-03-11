#include <stdio.h>
#include <stdlib.h>

int main() {
    int tipoVeiculo, tipoSeguro, idade, eixos;
    float valorBase = 0, adicionalCat = 0;
    float adicionalIdade = 0;
    float custoCobertura = 0, valorTotal;

    printf("--- SISTEMA DE CALCULO DE SEGURO ---\n");

    // 1. Escolha do Veiculo (com validação)
    do {
        printf("\nSelecione o tipo do veiculo:\n");
        printf("1. Passeio\n2. Carga Pesada\n3. Caminhonete\n4. Motocicleta (ate 1000cc)\n5. Motocicleta (acima 1000cc)\n");
        printf("Opcao: ");
        if (scanf("%d", &tipoVeiculo) != 1) {
            while (getchar() != '\n');
        }
        if (tipoVeiculo < 1 || tipoVeiculo > 5) {
            printf("[ERRO] Opcao invalida! Tente novamente.\n");
        }
    } while (tipoVeiculo < 1 || tipoVeiculo > 5);

    // Definir valor base e adicional categoria
    if (tipoVeiculo >= 4) {
        valorBase = 1200.00; // Motos
        if (tipoVeiculo == 4) adicionalCat = valorBase * 0.80; // 80%
        else adicionalCat = valorBase * 0.90; // 90%
    } else {
        valorBase = 1000.00; // Demais
        if (tipoVeiculo == 1) adicionalCat = valorBase * 0.10; // 10%
        else if (tipoVeiculo == 2) adicionalCat = valorBase * 0.20; // 20%
        else adicionalCat = valorBase * 0.33; // 33%
    }

    // 2. Perfil do condutor
    printf("Digite a idade do condutor: ");
    scanf("%d", &idade);

    if (idade >= 18 && idade <= 25) adicionalIdade = valorBase * 0.15;
    else if (idade > 25 && idade < 30) adicionalIdade = valorBase * 0.10;
    else adicionalIdade = valorBase * 0.05;

    // 3. Tipo de seguro (com validação)
    do {
        printf("Selecione o seguro: 1.Basico | 2.Parcial | 3.Completo: ");
        if (scanf("%d", &tipoSeguro) != 1) {
            while (getchar() != '\n');
        }
    } while (tipoSeguro < 1 || tipoSeguro > 3);

    // --- REGRAS DE NEGOCIO PARA COBERTURA ---

    // Lógica para Carga Pesada (2) e Caminhonete (3)
    if (tipoVeiculo == 2 || tipoVeiculo == 3) {
        printf("Quantidade de eixos: ");
        scanf("%d", &eixos);
        if (tipoSeguro == 1) custoCobertura = (valorBase * 0.03) * eixos;
        else if (tipoSeguro == 2) custoCobertura = (valorBase * 0.05) * eixos;
        else custoCobertura = (valorBase * 0.10) * eixos;
    }
    // Lógica para Passeio (1)
    else if (tipoVeiculo == 1) {
        if (tipoSeguro == 1) custoCobertura = -(valorBase * 0.02); // Desconto de 2%
        else if (tipoSeguro == 2) custoCobertura = (valorBase * 0.02); // Acréscimo 2%
        else custoCobertura = (valorBase * 0.10); // Acréscimo 10%
    }
    // Lógica para Motos (4 e 5)
    else {
        if (tipoVeiculo == 4) { // Até 1000cc
            if (tipoSeguro == 1) custoCobertura = -(valorBase * 0.05); // Desconto 5%
            else if (tipoSeguro == 2) custoCobertura = (valorBase * 0.15);
            else custoCobertura = (valorBase * 0.80);
        } else { // Acima de 1000cc
            if (tipoSeguro == 1) custoCobertura = (valorBase * 0.10);
            else if (tipoSeguro == 2) custoCobertura = (valorBase * 0.20);
            else custoCobertura = (valorBase * 1.00); // 100%
        }
    }

    // 4. Saida de Dados
    valorTotal = valorBase + adicionalCat + adicionalIdade + custoCobertura;

    printf("\n--- RELATORIO FINAL ---\n");
    printf("Valor Base:      R$ %.2f\n", valorBase);
    printf("Adicional Cat:   R$ %.2f\n", adicionalCat);
    printf("Adicional Idade: R$ %.2f\n", adicionalIdade);
    printf("Custo Cobertura: R$ %.2f\n", custoCobertura);
    printf("---------------------------\n");
    printf("VALOR TOTAL:     R$ %.2f\n", valorTotal);

    return 0;
}
