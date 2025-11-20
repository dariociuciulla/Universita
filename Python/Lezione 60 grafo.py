from collections import defaultdict
from collections import deque
import heapq
import networkx as nx           
import matplotlib.pyplot as plt 

class GrafoNonOrientato:

    def __init__(self, vertici):
        self.V = vertici
        self.grafico = defaultdict(list)    

    def aggiungiArco(self, u, v):
        if u not in self.grafico:
            self.grafico[u] = []
        if v not in self.grafico:
            self.grafico[v] = []
        self.grafico[u].append(v)
        self.grafico[v].append(u)

    def stampa(self):
        for vertici in self.grafico:
            print("Il vertice: " + str(vertici) + " ha come adiacenti: " + str(self.grafico[vertici]))    

    def disegna(self):
        # Crea un grafo vuoto di NetworkX
        G = nx.Graph()
        
        # Aggiungi tutti gli archi dal tuo dizionario al grafo di NetworkX
        for nodo, vicini in self.grafico.items():
            for vicino in vicini:
                G.add_edge(nodo, vicino)
        
        # Disegna il grafo
        plt.figure("Grafo") # Imposta il nome della finestra
        plt.title("Il mio Grafo") # Titolo sopra il disegno
        pos = nx.spring_layout(G) # Algoritmo per posizionare i nodi in modo ordinato
        nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=2000, font_size=15, font_weight='bold')
        plt.show() # Mostra la finestra con il disegno      
class GrafoOrientatoPesato:
    def __init__(self, vertici):
        self.V = vertici
        self.grafico = defaultdict(list)

    def aggiungiArco(self, u, v, peso):
        # Con defaultdict non servono controlli se la chiave esiste
        self.grafico[u].append((v, peso))
        
    def stampa(self):
        for u in self.grafico:
            print("Il vertice: " + str(u) + " ha come adiacenti:")    
            for v, peso in self.grafico[u]:
                print(" -> " + str(v) + " con peso: " + str(peso))

    def disegna(self):
        # Usa DiGraph invece di Graph per avere le frecce (Directed Graph)
        G = nx.DiGraph()
        
        # Aggiungi tutti gli archi con il loro peso
        for u, vicini in self.grafico.items():
            for v, peso in vicini:
                G.add_edge(u, v, weight=peso)
        
        # Imposta la finestra
        plt.figure("Grafo Orientato Pesato") 
        plt.title("Visualizzazione Grafo Pesato") 
        
        pos = nx.spring_layout(G) 
        
        # Disegna nodi e archi (frecce)
        nx.draw(G, pos, with_labels=True, node_color='lightgreen', node_size=2000, font_size=15, font_weight='bold', arrows=True)
        
        # Disegna le etichette dei pesi sugli archi
        edge_labels = nx.get_edge_attributes(G, 'weight')
        nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)
        
        plt.show()    
def bfs(grafico, inizio):
    # 1. Teniamo traccia di chi abbiamo già visto per non girare in tondo
    visitati = set()
    
    # 2. Creiamo la coda e ci mettiamo subito il nodo di partenza
    coda = deque([inizio])
    
    # 3. Segniamo la partenza come "già vista"
    visitati.add(inizio)
    
    # 4. Finché c'è qualcuno nella coda, continuiamo a lavorare
    while coda:
        # 5. Estraiamo il PRIMO della fila (popleft è fondamentale!)
        vertice = coda.popleft()
        
        # 6. "Visitiamo" il nodo (qui lo stampiamo solo)
        print(vertice, end=" ")
        
        # 7. Guardiamo tutti gli amici di questo nodo
        for vicino in grafico[vertice]:
            # 8. Se l'amico non l'abbiamo mai visto prima...
            if vicino not in visitati:
                # ...lo mettiamo in coda per visitarlo dopo
                coda.append(vicino)
                # ...e lo segniamo come visto per non rimetterlo in coda due volte
                visitati.add(vicino)    
def dfs(grafico, inizio):
    # 1. Teniamo traccia di chi abbiamo già visto
    visitati = set()
    
    # 2. Creiamo la PILA (Stack) e ci mettiamo subito il nodo di partenza
    # Nota: Usiamo sempre deque, ma useremo pop() invece di popleft()
    pila = deque([inizio])
    
    # 3. Finché c'è qualcuno nella pila...
    while pila:
        # 4. Estraiamo l'ULTIMO arrivato (LIFO - Last In First Out)
        # Questa è la differenza chiave con la BFS!
        vertice = pila.pop()
        
        # 5. Se non l'abbiamo ancora visitato...
        if vertice not in visitati:
            # ...lo visitiamo ora
            print(vertice, end=" ")
            visitati.add(vertice)
            
            # 6. Aggiungiamo i vicini alla pila
            # Nota: Li aggiungiamo tutti, poi controlleremo se sono visitati quando li estraiamo
            for vicino in grafico[vertice]:
                if vicino not in visitati:
                    pila.append(vicino)   
def ordinamento_topologico(grafico):
    # 1. Set per tenere traccia dei nodi già visitati completamente
    visitati = set()
    # 2. Pila per memorizzare l'ordine finale (al contrario)
    pila = []
    
    # Funzione ricorsiva interna (DFS)
    def visita(vertice):
        # 3. Se non l'abbiamo già visitato...
        if vertice not in visitati:
            visitati.add(vertice)
            # 4. ...visitiamo prima TUTTI i suoi figli (dipendenze)
            for vicino in grafico[vertice]:
                # Nota: nel grafo pesato 'vicino' è una tupla (nodo, peso)
                # Se il grafo è pesato dobbiamo prendere solo il nodo [0]
                if isinstance(vicino, tuple):
                    vicino = vicino[0]
                visita(vicino)
            # 5. Solo quando ho finito tutti i figli, aggiungo ME STESSO alla pila
            # (Significa: "Tutte le mie dipendenze sono risolte, ora tocca a me")
            pila.append(vertice)
    
    # 6. Lanciamo la visita su tutti i nodi del grafo
    # (Serve perché il grafo potrebbe essere sconnesso, cioè fatto a isole)
    for vertice in list(grafico): # Usiamo list() per evitare errori se il dizionario cambia
        visita(vertice)
    
    # 7. Restituiamo la pila al contrario
    # (Perché abbiamo inserito per ultimi quelli che non avevano più dipendenze)
    return pila[::-1]           
#Cammini minimi
def bellman_ford(grafico, sorgente):
    # 1. Troviamo TUTTI i nodi del grafo (sia chiavi che valori)
    #    Perché nel dizionario 'grafico' ci sono solo i nodi che hanno archi in uscita!
    #    Se un nodo (es. 3) riceve solo archi ma non ne fa partire, non è una chiave.
    nodi = set(grafico.keys())
    for u in grafico:
        for v, peso in grafico[u]:
            nodi.add(v)
            
    # 2. Inizializziamo i pesi di tutti i nodi a infinito
    distanze = {vertice: float('inf') for vertice in nodi}
    
    # 3. Il peso della sorgente è 0
    distanze[sorgente] = 0
    
    # 4. Facciamo al più |V| - 1 iterazioni (|V| è il numero di nodi)
    for _ in range(len(nodi) - 1):
        # 5. Per ogni arco (u, v, peso)
        for u in grafico:
            for v, peso in grafico[u]:
                # 6. Se il percorso attraverso u è più corto...
                if distanze[u] + peso < distanze[v]:
                    # ...aggiorniamo il peso
                    distanze[v] = distanze[u] + peso
    
    # 7. Restituiamo i pesi finali
    return distanze
def dijkstra(grafico, sorgente):
    # 1. Priority Queue (Heap): contiene (distanza, nodo) ordinati per distanza
    # All'inizio c'è solo la sorgente con distanza 0
    coda_priorita = [(0, sorgente)]
    
    # 2. Dizionario delle distanze minime trovate finora
    distanze = {sorgente: 0}
    
    # 3. Set dei nodi già visitati definitivamente
    visitati = set()

    while coda_priorita:
        # 4. Estrai il nodo con distanza minima (Greedy)
        distanza_attuale, nodo_corrente = heapq.heappop(coda_priorita)
        
        # 5. Se l'abbiamo già visitato, ignoralo
        if nodo_corrente in visitati:
            continue
        
        # Segnalo come visitato
        visitati.add(nodo_corrente)
        
        # 6. Esplora i vicini
        for vicino, peso in grafico[nodo_corrente]:
            nuova_distanza = distanza_attuale + peso
            
            # 7. Rilassamento: Se trovo un percorso più breve...
            # (Nota: .get() restituisce infinito se il nodo non è ancora nel dizionario)
            if nuova_distanza < distanze.get(vicino, float('inf')):
                # ...aggiorno la distanza
                distanze[vicino] = nuova_distanza
                # ...e lo aggiungo alla coda
                heapq.heappush(coda_priorita, (nuova_distanza, vicino))
                
    return distanze

#main
print("Grafo Non Orientato")
g = GrafoNonOrientato(4)
g.aggiungiArco(0, 1)
g.aggiungiArco(0, 2)
g.aggiungiArco(1, 2)
g.aggiungiArco(1, 3)
g.aggiungiArco(2, 3)
g.stampa()            
#g.disegna()
print("\n\nBFS (Visita in Ampiezza):")
bfs(g.grafico, 0)
print("\n\nDFS (Visita in Profondità):")
dfs(g.grafico, 0)
print("\n\nGrafo Orientato Pesato")
gp = GrafoOrientatoPesato(4)
gp.aggiungiArco(0, 1, 2)
gp.aggiungiArco(0, 2, 3)
gp.aggiungiArco(1, 2, 1)
gp.aggiungiArco(1, 3, 2)
gp.aggiungiArco(2, 3, 1)
gp.stampa() 
print("\n\nOrdinamento Topologico:")
print(ordinamento_topologico(g.grafico))
print("\n")
print("\nBellman-Ford:")
print(bellman_ford(gp.grafico, 0))           
print("\n\nDijkstra:")
print(dijkstra(gp.grafico, 0))           
#gp.disegna()
