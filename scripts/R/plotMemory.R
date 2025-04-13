# Script para gerar gráficos interativos de memória de execução
# Uso: Rscript {caminho}/plotMemory.R <nome_do_metodo>
# 
# Exemplo:
#   Rscript scripts/R/plotMemory.R addFirst
#
# O script espera encontrar um arquivo de dados em:
#   data/results/memory/addFirst.data
#
# O gráfico interativo será salvo em:
#   data/results/memory/addFirst.html
#
# Para instalar uma biblioteca utilize, dentro de um ambiente R:
# install.packages("<nome_da_biblioteca>")

# Importa as bibliotecas utilizadas
library('ggplot2')
library('plotly')

# Verifica se o argumento foi fornecido
if(length(commandArgs(trailingOnly = TRUE)) == 0) {
  cat("\nERRO: argumento não foi fornecido!\n")
  quit(status = 1)
}

# Define os diretórios de trabalho
args <- commandArgs(trailingOnly = TRUE)
input_file <- paste0("data/results/memory/", args[1], ".data")
output_file <- paste0("data/results/memory/", args[1], ".html")

# Verifica se o arquivo de entrada existe
if(!file.exists(input_file)) {
  cat("\nERRO: Arquivo de entrada não encontrado!\n")
  cat("Procurado em:", input_file, "\n\n")
  quit(status = 1)
}

# Lê e carrega conteúdo
data <- read.table(input_file, header = TRUE)

# Cria o gráfico com linhas e pontos
p <- ggplot(data, aes(x = tamanho,
                      y = memoria,
                      colour = estrutura_linguagem,
                      group = estrutura_linguagem,
                      # Personaliza os tooltips
                      text = paste("Tamanho:", tamanho, "<br>Memória:", memoria))) +
  geom_line(linewidth = 0.8) +
  geom_point(size = 2.5, alpha = 0.8) +
  labs(title = paste0("Memória de execução por tamanho para método ", args[1]),
       x = "Tamanho (número de inteiros por linha)",
       y = "Memória (kB)",
       colour = "Estrutura/linguagem") +
  theme_bw() +
  theme(legend.position = "bottom")

# Converte para gráfico interativo
interactive_plot <- ggplotly(p, tooltip = "text") %>% 
  layout(hoverlabel = list(bgcolor = "white"))

# Salva o gráfico interativo
htmlwidgets::saveWidget(interactive_plot, 
                        file = output_file,
                        selfcontained = TRUE,
                        title = paste("Memória para execução -", args[1]))

# Exibe mensagens de sucesso
cat("\nGrágico interativo gerado com sucesso:\n")
cat("  ", output_file, "\n\n")
