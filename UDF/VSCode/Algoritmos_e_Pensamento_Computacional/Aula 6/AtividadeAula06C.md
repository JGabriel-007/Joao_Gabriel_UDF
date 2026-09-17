01	#include <stdio.h>						//  Linha 01: Biblioteca padrão de entrada e saída.

02								

03	int main() {							                    //  Linhas 03 a 08

04		int vet\[20];						                   // Declaração das variáveis; vetor, contadores, acumuladores e variáveis de controle.

05		int i, somaMult3 = 0, somaPares = 0;

06		int contNeg = 0, contPos = 0, contPares = 0;

07		float mediaPares = 0.0;

08		int maior, menor;

09

10		printf("Digite 20 números inteiros:\\n");		        //  Linhas 10 a 13

11		for (i = 0; i < 20; i++) {				                // Leitura dos 20 números e armazenamento no vetor

12			scanf("%d", \&vet\[i]);

13		}

14

15		maior = vet\[0];						                // Linhas 15 e 16

16		menor = vet\[0];						                // Inicializa o maior e o menor valor com o primeiro elemento do vetor.

17

18		for (i = 0; i < 20; i++) {				                // Linhas 18 a 33

19			if (vet\[i] % 3 == 0)				                // Percorre o vetor e processa as informações:

20				somaMult3 += vet\[1];			                // - soma dos múltiplos de 3 (linhas 19-20);

21			if (vet\[1] % 2 == 0) {				                // - soma e contagem dos pares (linhas 21-24);

22				somaPares += vet\[i];			                // - contagem de negativos e positivos (linhas 25-28);

23				contPares++;				                    // - atualização do maior e do menor valor (linhas 29-32).

24			}

25			if (vet\[i] < 0)

26				contNeg++;

27			else if (vet\[i] > 0)

28				contPos++;

29			if (vet\[i] > maior)

30				maior = vet\[i];

31			if (vet\[i] < menor)

32				menor = vet\[i];

33		}

34

35		if (contPares > 0)					                    // Linhas 35 e 36

36			mediaPares = (float)somaPares / contPares;	        // Calcula a média dos pares (evita divisão por zero).

37

38		printf("\\nResultados:\\n");				            // Linhas 38 a 44

39		printf("Soma dos múltiplos de 3: %d\\n", somaMult3);	// Exibe os resultados calculados.

40		printf("Média dos pares: %.2f\\n", mediaPares);

41		printf("Quantidade de negativos: %d\\n", contNeg);

42		printf("Quantidade de positivos: %d\\n", contPos);

43		printf("Maior valor: %d\\n", maior);

44		printf("Menor valor: %d\\n", menor);			// }

45

46		printf("\\nElementos do vetor:\\n");			// } Linhas 46 a 50

47		for (i = 0; i < 20; i++) {				// Mostra todos os elementos do vetor na tela.

48			printf("%d ", vet\[i]);

49		}

50		return 0;						// }

51

52	}								// } Linha 52: Finaliza o programa.

