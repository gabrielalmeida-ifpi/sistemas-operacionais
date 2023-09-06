import { exec } from 'child_process'

const arquivo = 'arquivo.txt'
const texto = 'Só alegria hahaha.\n'

exec(`echo ${texto} > ${arquivo}`, { shell: 'cmd.exe' }, (erro, stdout, stderr) => {
    if (erro) {
        console.error(`Erro ao criar e escrever no arquivo: ${erro}`)
        return
    }
    console.log(`Arquivo ${arquivo} criado e texto escrito com sucesso.`)
}
)