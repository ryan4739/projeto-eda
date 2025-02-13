import java.util.ArrayList;

/**
* uma classe genérica de ArrayList criada para criar uma lista de tamanho indeterminado
* e realizar operações simples com ela tais quais, adicionar e remover elementos baseado em indices
* e sem indices
*
**/
public class ArrayList{
	
	public static void main(String[] args) {	
		
		/**
		 * declarando uma lista para elementos genericos	
		 **/ 
		private List lista = new ArrayList();
		
		/**
		 * adicionando elementos na lista sem uso de indices na última posição da lista
		 *
		 * @param T elemento genérico que será adicionado na lista
		 **/
		public boolean addElementosList(T elemento){
			lista.add(elemento);
			return true;
		}
		
		/**
		 * adicionando elementos na lista com uso de indice para uma posição n na lista
		 *
		 * @param T elemento genérico que será adicionado na lista
		 * @param index indice onde T será posicionado
		 **/
		public boolean addElementosListIndex(T elemento, int index){
			lista.add(index, elemento);
			return true;
		}

		/**
		 * Buscando elemento na lista através do indice
		 *
		 * @param index indice que será buscado
		 **/
		public boolean getElemento(int index){
			lista.get(index);
			return true;
		}
		
		/**
		 * removendo elemento na lista através do indice
		 *
		 * @param index indice que será removido da lista
		 **/
		public boolean removeElemento(int index){
			lista.pop(index);
			return true;
		}

	}
}	
