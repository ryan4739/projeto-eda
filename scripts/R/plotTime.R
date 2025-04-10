library('ggplot2')
library('plotly')

args <- commandArgs(trailingOnly = TRUE)
input_file <- paste0("data/results/time/", args[1], ".data")
output_file <- paste0("data/results/time/", args[1], ".html")

data = read.table(input_file, header = TRUE)

p <- ggplot(data, aes(x = tamanho, y = tempo, colour = estrutura_linguagem)) +
  geom_line() +
  labs(title = paste0("Tempo de execução por tamanho para método ", args[1]),
       x = "Tamanho (número de inteiros por linha)",
       y = "Tempo (ns)",
		   colour = "Estrutura/linguagem") +
  theme_bw() +
  theme(legend.position = "bottom")

ggsave(output_file,
       plot = p,
       width = 210,
       height = 148,
       dpi = 300,
       units = "mm")

