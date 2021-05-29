#include <cstdlib>
#include <iostream>
#include <locale.h>
#include <algorithm>
using namespace std;

class WorkingSet
{
      private:
      		 
             int *WS;
             int ProximaPosicaoLivre;   
      
			
      public:
      		int qtdCheck;
      		int MAX;
             WorkingSet(int qtde)
             {
                 MAX = qtde;
                 WS = new int[MAX];
                 ProximaPosicaoLivre = 0;          
			}
                 
             void insereWS(int n)
             {
                  if(ProximaPosicaoLivre <= MAX) WS[ProximaPosicaoLivre++] = n;
             }
             void MostraWorkingSet()
             {
             	cout << "\n\n\n";
                  for(int i = 0; i<ProximaPosicaoLivre; i++)
                  {
                          cout <<WS[i] <<" | ";
                  }
             }
             
             bool verifica(int array[]){
             	qtdCheck = 0;
             	int arrSize = sizeof(array)/sizeof(array[0]);
             	for(int i = 0; i < MAX; i++){
					for(int j = 0; j < arrSize; j++){
						if(WS[i] == array[j]){							
							qtdCheck++;
						}
					}
				}
             	if(qtdCheck == MAX){
             		return true;	
				 }
				else{
					return false;
				}
             	
			 }
			 
			 bool verificaPagina(int val){

			 	for(int i = 0; i < MAX; i++){
					if(WS[i] == val){
						return true;
					}
				}
				return false;
			 	
			 }
			 
			 
};



int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	int paginasCarregadasEmMemoria[6] = {1, 3, 5, 7, 8, 9};
	cout <<"\n Páginas carregadas em memória:";
	for(int y=0; y<6; y++){
        cout<<paginasCarregadasEmMemoria[y]<<" | "; 
	}
	int i = 1, aux = 0, opcao = 0, ordemRemocao = 0;
	cout <<"\n\n\nDigite o tamanho do Working set (até 6):\n";
	cin >> aux;
    WorkingSet ws(aux);
    
    for (int j = 1; j <= ws.MAX; j++){
    	cout <<"\n Digite a "<< j  <<"ª página do Working set:\n";
    	cin >> aux;
    	ws.insereWS(aux);
	}
    while (i == 1){
    	cout <<"\n\n\nEscolha uma opção pelo número:\n";
    	cout <<"\n 1 - Carregar página";
    	cout <<"\n 2 - Executar processo";
    	cout <<"\n 3 - Exibir working set do processo";
    	cout <<"\n 4 - Exibir páginas carregadas em memória";
    	cout <<"\n 5 - Sair\n";
    	cin >> opcao;
    	switch(opcao){
    		case 1:
    			cout <<"\n Digite a página a ser carregada em memória: \n";
    			cin >> aux;
    			for(int x = 0; x < 6; x++){
    				if(ordemRemocao > 5){
	    				ordemRemocao = 0;
					}
					if(!ws.verificaPagina(paginasCarregadasEmMemoria[ordemRemocao])){
						paginasCarregadasEmMemoria[ordemRemocao] = aux;
						break;
					}
	    			else{
	    				ordemRemocao++;
					}
	    			
				}
	    			
    			break;
    		case 2: 
    			if(ws.verifica(paginasCarregadasEmMemoria) == true){
    				cout << "\n\n O processo foi executado com sucesso";
				}
				else{
					cout << "\n\nPage fault! Infelizmente as páginas necessárias para o processo não foram todas carregadas em memória. Por favor, carregue uma nova";
				}
				break;
			case 3: 
				ws.MostraWorkingSet();
				break;
			case 4: 
				cout <<"\n Páginas carregadas em memória:\n";
				for(int y=0; y<6; y++){
			        cout<<paginasCarregadasEmMemoria[y]<<" | "; 
				}
				break;
			case 5:
				return EXIT_SUCCESS;
    			
		}
	}
}
