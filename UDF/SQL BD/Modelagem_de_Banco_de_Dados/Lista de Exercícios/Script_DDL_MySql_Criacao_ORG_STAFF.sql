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

-- Funções agregadas
-- SUM( ) - retorna o somatório
-- MAX( ) - retorna o maior valor
-- MIN( ) - retorna o menor valor
-- COUNT( ) - retorna a contagem (quantidade)
-- AVG( ) - retorna a média (mesmo que SUM() / COUNT())