library('ggplot2')

args <- commandArgs(trailingOnly = TRUE)
input_file <- paste0("data/results/time/", args[1], ".data")
output_file <- paste0("data/results/time/", args[1], ".png")

data = read.table(input_file, header = TRUE)

p <- ggplot(data, aes(x = tamanho, y = tempo, colour = estrutura_linguagem)) +
  geom_line() +
  labs(title = "Tempo de Execução por tamanho",
       x = "Tamanho",
       y = "Tempo",
		   colour = "Estrutura/linguagem") +
  theme_bw() +
  theme(legend.position = "bottom")

ggsave(output_file,
       plot = p,
       width = 210,
       height = 148,
       dpi = 300,
       units = "mm")

