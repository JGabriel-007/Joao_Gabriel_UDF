// Exercicio 11. Criar uma função que retorna o
// quadrado dos primeiros 20 números
function calculaQuadrado(numero) {
    return numero * numero;
}
// agora iremos chamar a execução da função calculaQuadrado
console.log("------------------------");
console.log("Exercicio 11");
console.log("------------------------");
for (let numero = 1; numero <= 20; numero++){
    console.log('O quadrado de ', numero, ' é igual a ', calculaQuadrado(numero));
}

// Exercício 12. Calcular a soma dos elementos de um array
console.log("--------------------");
console.log("Exercício 12");
console.log("--------------------");
let listaNumeros = [2, 4, 6, 8, 10, 12];
let somaNumerosArray = 0;

for (let elementoArray of listaNumeros) {
    somaNumerosArray += elementoArray
}
console.log("O resultado da soma é igual a: ", somaNumerosArray);

// Exercício 13. Filtrar números pares de uma lista 9(Array)
console.log("--------------------");
console.log("Exercício 13");
console.log("--------------------");
let numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
let numerosPares = listaNumeros.filter(num => num % 2 === 0);
console.log(numerosPares);

// Exercício 15. Procurar um nome em uma lista array
console.log("--------------------------");
console.log("Exercício 15");
console.log("--------------------------");
let colecaoNomes = ["Helena", "Rayka", "Jean", "Kevin", "Davi"];
let busca = "Kevin";
// método includes da classe Array procura um elemento
console.log ("O nome " + busca + " encontra-se na lista? " + colecaoNomes.includes(busca));

// Exercício 16. Ordenar um array de números
console.log("--------------------------");
console.log("Exercício 16");
console.log("--------------------------");
let numerosPraOrdenar = [7, 3, 5, 2, 14, 20, 4, 9, 1];
console.log("Lista desordenada");
console.log(numerosPraOrdenar);
numerosPraOrdenar.sort((a, b) => a - b);
console.log("Lista ordenada");
console.log(numerosPraOrdenar);

// Exercício 17. Retorna todos indices que o número aparece na lista de números array
console.log("--------------------------");
console.log("Exercício 17");
console.log("--------------------------");
function todosIndices(vetor, num) {
    let indices = [];
    for (let i = 0; i < vetor.length; i++) {
        if (vetor[i] === num) {
            indices.push(i);
        }
    }
    return indices;
}
console.log(todosIndices([1, 2, 3, 5, 2, 8, 4], 2));

// Exercício 18. Vamos gerar a série Fibonacci de até n numerosPraOrdenar
console.log("--------------------------");
console.log("Exercício 18");
console.log("--------------------------");
function serieFibonacci(num) {
    let fibo = [0, 1];
    while (fibo.length < num) {
        fibo.push(fibo[fibo.length - 1] + fibo[fibo.length - 2]);
    }
    return fibo.slice(0, num);
}
console.log(serieFibonacci(20));

// Exercício 19. Cria um tabuleiro 3x3 para jogo da velha e função para marcar posição
console.log("--------------------------");
console.log("Exercício 19");
console.log("--------------------------");

function criarTabuleiro() {
    let tabuleiro = [];
    for (let i = 0; i < 3; i++) {
        tabuleiro[i] = ['', '', ''];
    }
    return tabuleiro;
}

function marcarPosicao (tabuleiro, linha, coluna, jogador) {
    if (tabuleiro[linha][coluna] === '') {
        tabuleiro[linha][coluna] = jogador;
        return true;
    }
    return false;
}

function exibirTabuleiro(tabuleiro) {
    for(let i = 0; i < 3; i++) {
        console.log(tabuleiro[i].join(' | '));
    }
}

let tabuleiro = criarTabuleiro();
                marcarPosicao(tabuleiro, 1, 1, 'x');
                marcarPosicao(tabuleiro, 0, 0, 'x');
                marcarPosicao(tabuleiro, 0, 1, 'x');
                exibirTabuleiro(tabuleiro);