library('ggplot2')
library('plotly')

args <- commandArgs(trailingOnly = TRUE)
input_file <- paste0("data/results/memory/", args[1], ".data")
output_file <- paste0("data/results/memory/", args[1], ".html")

data = read.table(input_file, header = TRUE)

p <- ggplot(data, aes(x = tamanho, y = memoria, colour = estrutura_linguagem)) +
  geom_line() +
  geom_point() +
  labs(title = paste0("Tempo de execução por memória para método ", args[1]),
       x = "Tamanho (número de inteiros por linha)",
       y = "Memória (kB)",
		   colour = "Estrutura/linguagem") +
  theme_bw() +
  theme(legend.position = "bottom")

interactive_plot <- ggplotly(p)
htmlwidgets::saveWidget(interactive_plot, file = output_file, selfcontained = TRUE)

