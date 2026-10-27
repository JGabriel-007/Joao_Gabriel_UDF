// Exercício 1. Mensagem
console.log("Exercício 1: Hello Mundo!");

// Exercício 2. Soma de dois números
console.log("--------------------");
console.log("Exercício 2");
console.log("--------------------");
let num1 = 5, num2 = 3, resultadoSoma = num1 + num2;
console.log("Exercício 2: O resultado da Soma é: " + resultadoSoma);

// Exercídio 3. Verifica se um número é par
console.log("--------------------");
console.log("Exercício 3");
console.log("--------------------");
let numero = 12;
if (numero % 2 === 0) {
    console.log("Exercício 3: Número é par!");
} else {
    console.log("Exercício 3: O número é ímpar!");
}

// Exercício 4. Calcular a média de notas do aluno
console.log("--------------------");
console.log("Exercício 4");
console.log("--------------------");
let nota1 = 8.0, nota2 = 7.5, nota3 = 5.0, nota4 = 6.5;
let mediaNotas = (nota1 + nota2 + nota3 + nota4) / 4;
console.log("Exercício 4: A média de notas do alunbo é: " + mediaNotas);

// Exercício 5. Exibir números de 1 a 20
console.log("--------------------");
console.log("Exercício 5");
console.log("--------------------");
console.log("Exercício 5: Imprimindo 20 números.");
for (let i = 1; i <= 20; i++) {
    console.log(i);
}

// Exercício 6. Gerar a tabuada do número 7
console.log("--------------------");
console.log("Exercício 6");
console.log("--------------------");
let num = 7;
console.log("Exercício 6: Tabuada do número 7.")
for (let i = 1; i <= 10; i++) {
    console.log(`${num} x ${i} = ${num * i}`);
}

// Exercício 7. Calcular o fatorial de um número
console.log("--------------------");
console.log("Exercício 7");
console.log("--------------------");
let numBaseFatorial = 5, fatorial = 1;
for (let i = 1; i <+ numBaseFatorial; i++) {
    fatorial *= i;
}
console.log("Exercício 7: O fatorial de " + numBaseFatorial + "é igual á: " + fatorial);

// Exercício 8. Encontrar o maior de três números
console.log("--------------------");
console.log("Exercício 8");
console.log("--------------------");
let a = 15, b = 20, c = 10;
let maiorDeTres = Math.max(a, b, c);

console.log("Exercício 8: O maior dos três números é igual a: ", maiorDeTres);

// Exercício 9. Inverter uma String
console.log("--------------------");
console.log("Exercício 9");
console.log("--------------------");
let texto = "Stephany";
let textoInvertido = texto.split("").reverse().join("");
console.log("Exercício 9: A palavra:", texto, "fica invertida assim:", textoInvertido);

// Exercício 10. Verificar se uma palavra é palíndromo
console.log("--------------------");
console.log("Exercício 10");
console.log("--------------------");
let palavra = "arara";
let palindromoInvertido = palavra.split("").reverse().join("");
console.log("Exercício 10: A palavra:", palavra, "é um palíndromo (invertido)?", palavra === palindromoInvertido);