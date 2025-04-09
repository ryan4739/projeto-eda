library('ggplot2')

args <- commandArgs(trailingOnly = TRUE)
input_file <- paste0("data/results/memory/", args[1], ".data")
output_file <- paste0("data/results/memory/", args[1], ".png")

data = read.table(input_file, header = TRUE)

p <- ggplot(data, aes(x = tamanho, y = memoria, colour = estrutura_linguagem)) +
  geom_line() +
  labs(title = paste0("Tempo de execução por memória para método ", args[1]),
       x = "Tamanho",
       y = "Memória",
		   colour = "Estrutura/linguagem") +
  theme_bw() +
  theme(legend.position = "bottom")

ggsave(output_file,
       plot = p,
       width = 210,
       height = 148,
       dpi = 300,
       units = "mm")

