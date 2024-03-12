#include <stdio.h>
int main(void) {
  int codigopedido[5];
  float totalvenda = 0;
  int qtditens[5];
  char sexo[5];
  int valorpizza[5];
  int opcao;
  int i;
  int maxpedidos = 5;
  char opcao2;
  int valorMaior = 0;
  int qtdvalorMaior = 0;
  int qtdmulher = 0;
  int multiplica = 0;
  float media = 0;
  int qtdvalorMaior2 = 0;
  int itensvendidos = 0;
  int itensvendidosN = 0;
  int codigomaior = 0;
  int codigo1 = 0;
  char continuar;
  float somamedia = 0;
  int somamult = 0;
  int valorMaior2 = 0;

  printf("-- Bem vindos a pizzaria Provolones --\n\n");
  printf("Faça seu cadastro!\n\n");
  for (i = 0; i < 5; i++) {
    printf("Digite o código (1 a 10):");
    scanf("%d", &codigopedido[i]);
    while (codigopedido[i] < 1 || codigopedido[i] > 10) {
      printf("Erro, código inválido.\n");
      printf("Digite o código (1 a 10):");
      scanf("%d", &codigopedido[i]);
    }
    printf("Qual o sexo (m - masculino, f - feminino e n - não declarar):");
    scanf(" %c", &sexo[i]);
    while (sexo[i] != 'f' && sexo[i] != 'm' && sexo[i] != 'n') {
      printf("Erro, gênero inválido.\n");
      printf("Qual o sexo (m - masculino, f - feminino e n - não declarar):");
      scanf(" %c", &sexo[i]);
    }
    printf("Valor da  pizza:");
    scanf("%d", &valorpizza[i]);
    while (valorpizza[i] <= 0) {
      printf("Erro, valor negativo.\n");
      printf("Valor da  pizza:");
      scanf("%d", &valorpizza[i]);
    } 
    printf("Quantidade de pizzas:");
    scanf("%d", &qtditens[i]);
    while(qtditens[i] <= 0){
      printf("Erro, valor negativo.\n");
      printf("Quantidade de pizzas:");
      scanf("%d", &qtditens[i]);
    }

    if (qtditens[i] > codigomaior) {
      codigomaior = qtditens[i];
      codigo1 = codigopedido[i];
    }

    if (sexo[i] == 'm') {
      multiplica = valorpizza[i] * qtditens[i];
      somamult = somamult + multiplica;
    }
    if (sexo[i] == 'f') {
      qtdmulher++;
    }
    if (sexo[i] == 'n') {
      itensvendidosN = qtditens[i] + itensvendidos;
    }

      printf("Cadastro Concluído\n");

  }

  do {
    printf("  \nMenu principal  \n");
    printf("1-Pesquisar pedidos pelo código\n");
    printf("2-Informação de todos os pedidos\n");
    printf("3-Sair do programa\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &opcao);

    switch (opcao) {
      int codigo = 0;
      int achou = 0;

    case 1:
      printf("Qual o código?\n");
      scanf("%d", &codigo);
      for (i = 0; i < 5; i++) {
        if (codigo == codigopedido[i]) {
          printf("\n\nPedido: %d\n", codigopedido[i]);
          printf("Sexo: %c\n", sexo[i]);
          printf("Valor da pizza: %d\n", valorpizza[i]);
          printf("Quantidade de pizzas: %d\n\n", qtditens[i]);
          achou = 1;
        }
      }
      if (achou == 1) {
        printf("Se deseja voltar para o menu principal 's'-sim 'n'-não:\n");
        scanf(" %c", &continuar);
        if (continuar == 'n') {
          break;
        }
      }
      if (achou == 0) {
        printf("Não há pedidos com esse código.");
        printf("Se deseja voltar para o menu principal 's'-sim 'n'-não:");
        scanf(" %c", &continuar);
        if (continuar == 'n') {
          break;
        }
      }
      break;
    case 2:
      for (i = 0; i < 5; i++) {
        printf("Pedido: %d\n", codigopedido[i]);
        printf("Sexo: %c\n", sexo[i]);
        printf("Valor da pizza: %d\n", valorpizza[i]);
        printf("Quantidade de pizzas: %d\n", qtditens[i]);
        media = valorpizza[i] * qtditens[i];
        somamedia = media + somamedia;
        itensvendidos = qtditens[i] + itensvendidos;
        if (media < 40) {
          qtdvalorMaior2++;
        }
      }
      printf("Digite um valor:");
      scanf("%d", &valorMaior);
      for (i = 0; i < 5; i++) {
        valorMaior2 = valorpizza[i] * qtditens[i];
        if (valorMaior2 > valorMaior) {
          qtdvalorMaior++;
        }
      }
      printf("\nQuantidade de mulheres que compraram: %d\n", qtdmulher);
      printf("\nValor total do pedido dos homens: %d\n\n", somamult);
      printf("Pedidos acima do valor: %d\n", qtdvalorMaior);
      printf("Pedidos com valor abaixo de 40,00R$: %d\n", qtdvalorMaior2);
      somamedia = somamedia / 5;
      printf("Média dos pedidos: %.2f\n", somamedia);
      printf("Total de itens vendidos: %d\n", itensvendidos);
      printf("Total de itens vendidos por pessoas que nao declararam o sexo: %d\n\n",itensvendidosN); 
      printf("Código mais vendido: %d\n", codigo1);

      printf("Se deseja voltar para o menu principal 's'-sim 'n'-não: ");
      scanf(" %c", &continuar);
      if (continuar == 'n') {
        break;
      }
      break;
    default:
      printf("Erro!");
    }
  } while (opcao != '3' && continuar != 'n');

  return 0;
}