import networkx as nx
import matplotlib.pyplot as plt
from copy import deepcopy

##################################################################
# Implement by Bruna Almeida Osti                                #
# Universidade Tecnológica Federal do Paraná                     #
# Adjacency Class generates a figure through an adjacency matrix #
##################################################################

class Adjacency(object):

    def __init__(self, nodes):
        self.nodes = nodes              #number of nodes

    
    def Plot_Graph1(self, graph, title = 'Plot 1'):

        G = nx.Graph()
        aux = deepcopy(graph)

        for n in range(1, self.nodes+1):
            G.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(aux[i][j] != 0):
                    G.add_edge(i+1, j+1)
                    aux[i][j] = 0
                    aux[j][i] = 0
        
        pos = nx.spring_layout(G)
        nx.draw_networkx_nodes(G, pos)
        nx.draw_networkx_labels(G, pos)
        nx.draw_networkx_edges(G, pos)
        plt.title(title)
        plt.show()

    def Plot_Graph2(self, graph1, graph2, title1 = 'Plot 1', title2 = 'Plot 2'):
        G = nx.Graph()
        H = nx.Graph()

        px1 = deepcopy(graph1)
        px2 = deepcopy(graph2)

        for n in range(1, self.nodes+1):
            G.add_node(n)
            H.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(px1[i][j] != 0):
                    G.add_edge(i+1, j+1)
                    px1[i][j] = 0
                    px1[j][i] = 0

                if(px2[i][j] != 0):
                    H.add_edge(i+1, j+1)
                    px2[i][j] = 0
                    px2[j][i] = 0

          
        fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(10,5))   
             
        pos1 = nx.spring_layout(G)
        pos2 = nx.spring_layout(H)

        nx.draw_networkx_nodes(G, pos1, ax = axes[0])
        nx.draw_networkx_labels(G, pos1, ax= axes[0])
        nx.draw_networkx_edges(G, pos1, ax = axes[0], edge_color = 'r')
        axes[0].set_title(title1)
        
        nx.draw_networkx_nodes(H, pos2, ax = axes[1])
        nx.draw_networkx_labels(H, pos2, ax= axes[1])
        nx.draw_networkx_edges(H, pos2, ax = axes[1], edge_color = 'b')
        axes[1].set_title(title2)
        plt.show()

    
    def Plot_Graph3(self, graph1, graph2, graph3, title1 = 'Plot 1', title2 = 'Plot 2', title3 = 'Plot 3'):
        G = nx.Graph()
        H = nx.Graph()
        I = nx.Graph()

        px1 = deepcopy(graph1)
        px2 = deepcopy(graph2)
        px3 = deepcopy(graph3)

        for n in range(1, self.nodes+1):
            G.add_node(n)
            H.add_node(n)
            I.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(px1[i][j] != 0):
                    G.add_edge(i+1, j+1)
                    px1[i][j] = 0
                    px1[j][i] = 0

                if(px2[i][j] != 0):
                    H.add_edge(i+1, j+1)
                    px2[i][j] = 0
                    px2[j][i] = 0

                if(px3[i][j] != 0):
                    I.add_edge(i+1, j+1)
                    px3[i][j] = 0
                    px3[j][i] = 0
  
        
        fig, axes = plt.subplots(nrows=1, ncols=3, figsize=(8,4))   
        pos1 = nx.spring_layout(G)
        pos2 = nx.spring_layout(H)
        pos3 = nx.spring_layout(I)


        nx.draw_networkx_nodes(G, pos1, ax = axes[0])
        nx.draw_networkx_labels(G, pos1, ax= axes[0])
        nx.draw_networkx_edges(G, pos1, ax = axes[0], edge_color = 'r')
        axes[0].set_title(title1)
        
        nx.draw_networkx_nodes(H, pos2, ax = axes[1])
        nx.draw_networkx_labels(H, pos2, ax= axes[1])
        nx.draw_networkx_edges(H, pos2, ax = axes[1], edge_color = 'b')
        axes[1].set_title(title2)
        
        nx.draw_networkx_nodes(I, pos3, ax = axes[2])
        nx.draw_networkx_labels(I, pos3, ax = axes[2])
        nx.draw_networkx_edges(I, pos3, ax = axes[2], edge_color= 'g')
        axes[2].set_title(title3)
        plt.show()
    
    def Plot_Graph4(self, graph1, graph2, graph3, graph4, title1 = 'Plot 1', title2 = 'Plot 2', title3 = 'Plot 3', title4 = 'Plot 4'):
        G = nx.Graph()
        H = nx.Graph()
        I = nx.Graph()
        J = nx.Graph()

        px1 = deepcopy(graph1)
        px2 = deepcopy(graph2)
        px3 = deepcopy(graph3)
        px4 = deepcopy(graph4)

        for n in range(1, self.nodes+1):
            G.add_node(n)
            H.add_node(n)
            I.add_node(n)
            J.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(px1[i][j] != 0):
                    G.add_edge(i+1, j+1)
                    px1[i][j] = 0
                    px1[j][i] = 0

                if(px2[i][j] != 0):
                    H.add_edge(i+1, j+1)
                    px2[i][j] = 0
                    px2[j][i] = 0

                if(px3[i][j] != 0):
                    I.add_edge(i+1, j+1)
                    px3[i][j] = 0
                    px3[j][i] = 0

                if(px4[i][j] != 0):
                    J.add_edge(i+1, j+1)
                    px4[i][j] = 0
                    px4[j][i] = 0
  
        
        fig, axes = plt.subplots(nrows=2, ncols=2, figsize=(4,2))   
        pos1 = nx.spring_layout(G)
        pos2 = nx.spring_layout(H)
        pos3 = nx.spring_layout(I)
        pos4 = nx.spring_layout(J)

        nx.draw_networkx_nodes(G, pos1, ax = axes[0,0])
        nx.draw_networkx_labels(G, pos1, ax= axes[0,0])
        nx.draw_networkx_edges(G, pos1, ax = axes[0,0], edge_color = 'r')
        axes[0,0].set_title(title1)
        
        nx.draw_networkx_nodes(H, pos2, ax = axes[0,1])
        nx.draw_networkx_labels(H, pos2, ax= axes[0,1])
        nx.draw_networkx_edges(H, pos2, ax = axes[0,1], edge_color = 'b')
        axes[0,1].set_title(title2)
        
        plt.subplots_adjust(hspace = 0.236, wspace= 0.101)

        nx.draw_networkx_nodes(I, pos3, ax = axes[1,0])
        nx.draw_networkx_labels(I, pos3, ax = axes[1,0])
        nx.draw_networkx_edges(I, pos3, ax = axes[1,0], edge_color= 'g')
        axes[1,0].set_title(title3)

        nx.draw_networkx_nodes(J, pos4, ax = axes[1,1])
        nx.draw_networkx_labels(J, pos4, ax = axes[1,1])
        nx.draw_networkx_edges(J, pos4, ax = axes[1,1], edge_color= 'm')
        axes[1,1].set_title(title4)
        plt.show()

    def Plot_Graph6(self, graph1, graph2, graph3, graph4, graph5, graph6, title1 = 'Plot 1', title2 = 'Plot 2', title3 = 'Plot 3', title4 = 'Plot 4', title5 = 'Plot 5', title6 = 'Plot 6'):
        G = nx.Graph()
        H = nx.Graph()
        I = nx.Graph()
        J = nx.Graph()
        K = nx.Graph()
        L = nx.Graph()

        px1 = deepcopy(graph1)
        px2 = deepcopy(graph2)
        px3 = deepcopy(graph3)
        px4 = deepcopy(graph4)
        px5 = deepcopy(graph5)
        px6 = deepcopy(graph6)

        for n in range(1, self.nodes+1):
            G.add_node(n)
            H.add_node(n)
            I.add_node(n)
            J.add_node(n)
            K.add_node(n)
            L.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(px1[i][j] != 0):
                    G.add_edge(i+1, j+1)
                    px1[i][j] = 0
                    px1[j][i] = 0

                if(px2[i][j] != 0):
                    H.add_edge(i+1, j+1)
                    px2[i][j] = 0
                    px2[j][i] = 0

                if(px3[i][j] != 0):
                    I.add_edge(i+1, j+1)
                    px3[i][j] = 0
                    px3[j][i] = 0

                if(px4[i][j] != 0):
                    J.add_edge(i+1, j+1)
                    px4[i][j] = 0
                    px4[j][i] = 0

                if(px5[i][j] != 0):
                    K.add_edge(i+1, j+1)
                    px5[i][j] = 0
                    px5[j][i] = 0

                if(px6[i][j] != 0):
                    L.add_edge(i+1, j+1)
                    px6[i][j] = 0
                    px6[j][i] = 0
  
        
        fig, axes = plt.subplots(nrows=2, ncols=3, figsize=(24,24))   
        pos1 = nx.spring_layout(G)
        pos2 = nx.spring_layout(H)
        pos3 = nx.spring_layout(I)
        pos4 = nx.spring_layout(J)
        pos5 = nx.spring_layout(K)
        pos6 = nx.spring_layout(L)

        nx.draw_networkx_nodes(G, pos1, ax = axes[0,0])
        nx.draw_networkx_labels(G, pos1, ax= axes[0,0])
        nx.draw_networkx_edges(G, pos1, ax = axes[0,0], edge_color = 'r')
        axes[0,0].set_title(title1)
        
        nx.draw_networkx_nodes(H, pos2, ax = axes[0,1])
        nx.draw_networkx_labels(H, pos2, ax= axes[0,1])
        nx.draw_networkx_edges(H, pos2, ax = axes[0,1], edge_color = 'b')
        axes[0,1].set_title(title2)
        
        plt.subplots_adjust(hspace = 0.236, wspace= 0.176)

        nx.draw_networkx_nodes(I, pos3, ax = axes[0,2])
        nx.draw_networkx_labels(I, pos3, ax = axes[0,2])
        nx.draw_networkx_edges(I, pos3, ax = axes[0,2], edge_color= 'g')
        axes[0,2].set_title(title3)

        nx.draw_networkx_nodes(J, pos4, ax = axes[1,0])
        nx.draw_networkx_labels(J, pos4, ax = axes[1,0])
        nx.draw_networkx_edges(J, pos4, ax = axes[1,0], edge_color= 'm')
        axes[1,0].set_title(title4)

        nx.draw_networkx_nodes(K, pos5, ax = axes[1,1])
        nx.draw_networkx_labels(K, pos5, ax = axes[1,1])
        nx.draw_networkx_edges(K, pos5, ax = axes[1,1], edge_color= 'y')
        axes[1,1].set_title(title5)

        nx.draw_networkx_nodes(L, pos6, ax = axes[1,2])
        nx.draw_networkx_labels(L, pos6, ax = axes[1,2])
        nx.draw_networkx_edges(L, pos6, ax = axes[1,2], edge_color= 'c')
        axes[1,2].set_title(title6)

        plt.show()