-- Criando uma nova base de dados para CRUD
CREATE DATABASE IF NOT EXISTS AULA;

USE AULA;

CREATE TABLE IF NOT EXISTS cliente (
	id			INT AUTO_INCREMENT PRIMARY KEY,
    nome		VARCHAR(100) NOT NULL,
    email		VARCHAR(100) NOT NULL,
    telefone	VARCHAR(20),
    endereco	VARCHAR(255)
);


DELIMITER //

CREATE PROCEDURE inserirCliente (
	IN p_nome		VARCHAR(100),
    IN p_email		VARCHAR(100),
    IN p_telefone	VARCHAR(20),
    IN p_endereco	VARCHAR(255)
)
BEGIN
	INSERT INTO cliente (nome, email, telefone, endereco)
    VALUES (p_nome, p_email, p_telefone, p_endereco);
END

// DELIMITER ; 