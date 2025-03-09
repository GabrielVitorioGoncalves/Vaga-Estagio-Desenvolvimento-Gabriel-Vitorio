
function buscarCEP() {
    let cep = document.getElementById('cep').value.trim();
    let mensagem = document.getElementById('mensagem');
    mensagem.innerText = "";

    //Aqui verficamos se o cep e valido
    if (!/^[0-9]{8}$/.test(cep)) {
        mensagem.innerText = 'CEP inválido!';
        return;
    }

    //Requisicao para a API do ViaCEP
    fetch(`https://viacep.com.br/ws/${cep}/json/`)
        .then(response => {
            if (!response.ok) {
                throw new Error('Erro na requisição');
            }
            return response.json();
        })
        .then(data => {
            if (data.erro) {
                mensagem.innerText = 'CEP não encontrado!';
                return;
            }
            salvarEndereco(data);
            mostrarEnderecos();
        })
        .catch(error => {
            mensagem.innerText = 'Erro ao buscar o CEP. Tente novamente mais tarde.';
            console.error('Erro ao buscar o CEP:', error);
        });
}

function salvarEndereco(data) {
    let enderecos = JSON.parse(localStorage.getItem('enderecos')) || [];
    enderecos.push({ cidade: data.localidade, bairro: data.bairro, estado: data.uf });
    localStorage.setItem('enderecos', JSON.stringify(enderecos));
}


// Aqui armazena no LocalStorage
function mostrarEnderecos() {
    let enderecos = JSON.parse(localStorage.getItem('enderecos')) || [];
    let tabela = document.getElementById('tabela');


    tabela.innerHTML = enderecos.map(e =>
        `<tr><td>${e.cidade}</td><td>${e.bairro}</td><td>${e.estado}</td></tr>`
    ).join('');
}


function ordenar(campo) {
    let enderecos = JSON.parse(localStorage.getItem('enderecos')) || [];
    enderecos.sort((a, b) => a[campo].localeCompare(b[campo]));
    localStorage.setItem('enderecos', JSON.stringify(enderecos));
    mostrarEnderecos();
}
document.addEventListener("DOMContentLoaded", mostrarEnderecos);
