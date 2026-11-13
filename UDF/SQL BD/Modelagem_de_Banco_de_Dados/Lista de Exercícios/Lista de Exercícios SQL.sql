-- Lista de Exercícios Banco de Dados - EMPRESA-FUNCIONARIOS (ORG-STAFF)

-- Exercicio 01 --
-- 01) Liste os DEPARTAMENTOS cuja média salarial seja inferior à MÉDIA da empresa.
--     Ignore os GERENTES. Mostre as MÉDIAS salariais e ordene por essas médias.
SELECT ORG.DEPTCOD       AS 'CODIGO FILIAL',
       ORG.DEPTNOME      AS 'NOME FILIAL',
       format(AVG(STAFF.SALARIO), 2) AS 'MEDIA SALARIAL FILIAL'
FROM ORG,
     STAFF
WHERE ORG.DEPTCOD = STAFF.DEPT  -- join (relação) entre as tabelas
	AND STAFF.CARGO NOT LIKE 'GER' -- ignore os gerentes
GROUP BY ORG.DEPTCOD, ORG.DEPTNOME
HAVING AVG(STAFF.SALARIO) < (SELECT AVG(ST.SALARIO)
							 FROM STAFF AS ST
							 WHERE ST.CARGO NOT LIKE 'GER')
ORDER BY 3 ASC;

-- Ecercício 02 --
-- Selecione(simule) os salários reajustados pela localidade (filial),
-- sendo que a região SUDESTE receberá um aumento de 10%, a região NORDESTE
-- receberá um reajuste de 15% e a região SUL um aumento de 20%.
SELECT ORG.DIVISAO, STAFF.NOME, STAFF.CARGO, STAFF.SALARIO,
       FORMAT((STAFF.SALARIO * 0.10), 2) AS 'REAJUSTE',
       FORMAT((STAFF.SALARIO * 1.10), 2) AS 'SALÁRIO REAJUSTADO'
FROM ORG JOIN STAFF ON ORG.DEPTCOD = STAFF.DEPT
WHERE ORG.DIVISAO LIKE 'SUDESTE'
UNION
SELECT ORG.DIVISAO, STAFF.NOME, STAFF.CARGO, STAFF.SALARIO,
       FORMAT((STAFF.SALARIO * 0.15), 2) AS 'REAJUSTE',
       FORMAT((STAFF.SALARIO * 1.15), 2) AS 'SALÁRIO REAJUSTADO'
FROM ORG JOIN STAFF ON ORG.DEPTCOD = STAFF.DEPT
WHERE ORG.DIVISAO LIKE 'NORDESTE'
UNION
SELECT ORG.DIVISAO, STAFF.NOME, STAFF.CARGO, STAFF.SALARIO,
       FORMAT((STAFF.SALARIO * 0.20), 2) AS 'REAJUSTE',
       FORMAT((STAFF.SALARIO * 1.20), 2) AS 'SALÁRIO REAJUSTADO'
FROM ORG JOIN STAFF ON ORG.DEPTCOD = STAFF.DEPT
WHERE ORG.DIVISAO LIKE 'SUL';

-- Exercício 03 --
-- Listar os funcionários com salário superior à média da empresa,
-- em ordem decrescente.
SELECT ST.NOME AS 'NOME FUNCIONÁRIO', 
	   ST.CARGO, 
       ST.SALARIO AS 'SALÁRIOS ACIMA DA MÉDIA DA EMPRESA'
FROM STAFF AS ST
WHERE ST.SALARIO > (SELECT AVG(STAFF.SALARIO) FROM STAFF);

-- Exercício 04 --
-- Listar os funcionários com SALÁRIO inferior à média de algum DEPARTAMENTO,
-- exceto CAMPINAS
SELECT ST.CARGO, 
	   ST.NOME AS 'NOME FUNCIONÁRIO',
       ST.SALARIO AS 'SALÁRIOS MENOR QUE A MÉDIA DE ALGUM DEPARTAMENTO'
FROM STAFF AS ST JOIN ORG AS O ON O.DEPTCOD = ST.DEPT
WHERE O.DEPTNOME NOT LIKE 'CAMPINAS'
	AND ST.SALARIO < ANY (SELECT AVG(STAFF.SALARIO) FROM STAFF GROUP BY STAFF.DEPT)
    ORDER BY 1, 2;

SELECT S.SALARIO
FROM STAFF S
WHERE S.SALARIO BETWEEN 15000 AND 20000.00
ORDER BY 1 DESC;

-- Funções agregadas
-- SUM( ) - retorna o somatório
-- MAX( ) - retorna o maior valor
-- MIN( ) - retorna o menor valor
-- COUNT( ) - retorna a contagem (quantidade)
-- AVG( ) - retorna a média (mesmo que SUM() / COUNT())

-- Exercício 05
-- Mostre em apenas uma coluna maior SALÁRIO reajustado de 15%,
-- juntamente com o NOME do funcionário e o LOCAL de tarbalho
-- na empresa
SELECT
    S.SALARIO * 1.15 AS 'Salario reajustado em 15%'
FROM STAFF AS S
UNION ALL
SELECT
    S1.NOME
FROM STAFF AS S1
UNION ALL
SELECT
    O.LOCAL
FROM ORG AS O;

-- Exercício 06
-- Selecione o NOME, o CARGO e TEMPO DE SERVIÇO dos
-- funcionários que recebem as três maiores comissões
SELECT FUNC.NOME AS 'NOME FUNCIONÁRIO',
	   FUNC.CARGO,
       FUNC.ANOS AS 'TEMPO DE SERVIÇO',
       FUNC.COMIS AS 'COMISSÃO'
FROM STAFF AS FUNC
WHERE FUNC.COMIS IS NOT NULL
ORDER BY 4 DESC LIMIT 3; -- Classificando da maior comissão
						 -- para a menor, e limitando o resultado
                         -- nas 3 primeiras linhas
                         
-- Exercício 07
-- Selecione todas as informações dos funcionários,
-- agrupados por CARGO, que tenham a média de SALÁRIO
-- inferior à média dos salários da empresa (companhia)
SELECT S.*
FROM STAFF as S
WHERE S.CARGO IN (SELECT STAFF.CARGO
                 FROM STAFF
                 GROUP BY STAFF.CARGO
                 HAVING AVG(STAFF.SALARIO) <
                        (SELECT AVG(S2.SALARIO)
                                FROM STAFF as S2));

-- Exercício 08
-- Atualize uma tabela comissão de 10% para os GERENTES da MATRIZ
UPDATE STAFF, ORG
SET STAFF.COMIS = STAFF.SALARIO * 0.10
WHERE ORG.DEPTCOD = STAFF.DEPT
  AND STAFF.CARGO LIKE 'GER'
  AND ORG.DEPTNOME LIKE 'MATRIZ';

SELECT ORG.DEPTCOD,
       ORG.DEPTNOME,
       STAFF.NOME,
       STAFF.CARGO,
       STAFF.SALARIO,
       STAFF.COMIS
FROM STAFF, ORG
WHERE ORG.DEPTCOD = STAFF.DEPT
  AND STAFF.CARGO LIKE 'GER'
  AND ORG.DEPTNOME = 'MATRIZ';
  
-- Exercício 09
-- Apresente a quantidade de funcionários por filial e
-- depois apresente na sequência, a quantidade de funcionários por
-- região do país
SELECT ORG.DIVISAO,
       COUNT(STAFF.ID) AS 'QTD FUNCIONÁRIOS'
FROM ORG INNER JOIN STAFF ON ORG.DEPTCOD = STAFF.DEPT
GROUP BY ORG.DIVISAO
UNION
SELECT ORG.DEPTNOME,
       COUNT(STAFF.ID)
FROM ORG INNER JOIN STAFF ON ORG.DEPTCOD = STAFF.DEPT
GROUP BY ORG.DEPTNOME;