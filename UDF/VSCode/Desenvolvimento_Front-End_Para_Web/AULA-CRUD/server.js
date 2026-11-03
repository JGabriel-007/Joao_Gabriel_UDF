// Importando os pacotes
const express = require('express');
const mysql = require('mysql2');
const bodyParser = require('body-parser');

// Nercessário para passar alguns caminhos de arquivos estáticos
const path = require('path');

// Pequena parte do servidor web express do módulo para criar as rotas da aplicação
const app = express();

// Criando um porta de (rede) acessp ap servodpr
const port = 3000;

// Para trabalhar com arquivos estáticos como o .css, por exemplo
app.use(express.static(
    path.join(__dirname, 'public')));

// Configurando a conexão com o banco de dados
const connection = mysql.createConnection(
{
    host: '127.0.0.1',
    user: 'root',
    password: 'udf2025',
    database: 'aula',
    port: '3306'
});

// Conectando com o banco de dados
connection.connect( erro => {
    if (erro) {
        console.error('Erro ao conectar ao banco de dados', erro);
        return;
    }
    console.log('Conectado ao banco de dados!');
});

// Configurando o body-parser (é um middleware para Node.js que analisa requisições de formulários HTTP (req, post e put))
app.use(
    bodyParser.urlencoded( {extended: true}));

// Servir o formulário HTML para trabalhar com arquivo estático
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'UDF/VSCode/Desenvolvimento_Front-End_Para_Web/AULA-CRUD/frontend/index.html'))
});

// Postagem dos dados digitados no formulário (inserirCliente) para o BD
app.post('/inserirCliente', (req, res) => {
    // O que estiver cindo do corpo da página, o atributo req captura
    const{nome, email, telefone, endereco} = req.body
// Constant slq com o atributo da documentação do MySQL para usar a procedure sql
const sql = 'CALL inserirCliente(?, ?, ?, ?)';
// Passando (desestruturando os dados) para o BD a consulta SQL de inserção dos dados
connection.query(sql, [nome, email, telefone, endereco],
    (err, results) => {
        if (err) {
            console.error('Erro ao inserir cliente:', err);
            res.send('Erro ao inserir cliente');
            return;
        }
        res.redirect('/?mensagem=sucesso');
    });
});

// Inicializar a aplicação CRUD, digite no prompt do terminal: node server.js e clique na url http://localhost:3000
// Insira dados do cliente no formulário html e verifique no banco (select * from cliente) no MySQL Workbench