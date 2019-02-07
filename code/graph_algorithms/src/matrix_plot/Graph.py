import networkx as nx
import matplotlib.pyplot as plt
from copy import deepcopy

##################################################################
# Implement by Bruna Almeida Osti                                #
# Universidade Tecnológica Federal do Paraná                     #
# Adjacency Class generates a figure through an adjacency matrix #
##################################################################


class AdjacencyMatrix(object):

    def __init__(self, nodes):
        self.nodes = nodes  # number of nodes

    def plot_graph_1(self, graph, title='Plot 1'):

        graph_layout = nx.Graph()
        adjacent_matrix = deepcopy(graph)

        for n in range(1, self.nodes+1):
            graph_layout.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(adjacent_matrix[i][j] != 0):
                    graph_layout.add_edge(i+1, j+1)
                    adjacent_matrix[i][j] = 0
                    adjacent_matrix[j][i] = 0

        dictionary = nx.spring_layout(Graph_layout)
        nx.draw_networkx_nodes(Graph_layout, dictionary)
        nx.draw_networkx_labels(Graph_layout, dictionary)
        nx.draw_networkx_edges(Graph_layout, dictionary)
        plt.title(title)
        plt.show()

    def plot_graph_2(self, graph1, graph2, title1='Plot 1', title2='Plot 2'):
        graph_layout1 = nx.Graph()
        graph_layout2 = nx.Graph()

        adjacent_matrix1 = deepcopy(graph1)
        adjacent_matrix2 = deepcopy(graph2)

        for n in range(1, self.nodes+1):
            graph_layout1.add_node(n)
            graph_layout2.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(adjacent_matrix1[i][j] != 0):
                    graph_layout1.add_edge(i+1, j+1)
                    adjacent_matrix1[i][j] = 0
                    adjacent_matrix1[j][i] = 0

                if(adjacent_matrix2[i][j] != 0):
                    graph_layout2.add_edge(i+1, j+1)
                    adjacent_matrix2[i][j] = 0
                    adjacent_matrix2[j][i] = 0

        fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(10, 5))

        dictionary1 = nx.spring_layout(G)
        dictionary2 = nx.spring_layout(H)

        nx.draw_networkx_nodes(graph_layout1, dictionary1, ax=axes[0])
        nx.draw_networkx_labels(graph_layout1, dictionary1, ax=axes[0])
        nx.draw_networkx_edges(graph_layout1, dictionary1,
                               ax=axes[0], edge_color='r')
        axes[0].set_title(title1)

        nx.draw_networkx_nodes(graph_layout2, dictionary2, ax=axes[1])
        nx.draw_networkx_labels(graph_layout2, dictionary2, ax=axes[1])
        nx.draw_networkx_edges(graph_layout2, dictionary2,
                               ax=axes[1], edge_color='b')
        axes[1].set_title(title2)
        plt.show()

    def plot_graph_3(self, graph1, graph2, graph3, title1='Plot 1', title2='Plot 2', title3='Plot 3'):
        graph_layout1 = nx.Graph()
        graph_layout2 = nx.Graph()
        graph_layout3 = nx.Graph()

        adjacent_matrix1 = deepcopy(graph1)
        adjacent_matrix2 = deepcopy(graph2)
        adjacent_matrix3 = deepcopy(graph3)

        for n in range(1, self.nodes+1):
            graph_layout1.add_node(n)
            graph_layout2.add_node(n)
            graph_layout3.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(adjacent_matrix1[i][j] != 0):
                    graph_layout1.add_edge(i+1, j+1)
                    adjacent_matrix1[i][j] = 0
                    adjacent_matrix1[j][i] = 0

                if(adjacent_matrix2[i][j] != 0):
                    graph_layout2.add_edge(i+1, j+1)
                    adjacent_matrix2[i][j] = 0
                    adjacent_matrix2[j][i] = 0

                if(adjacent_matrix3[i][j] != 0):
                    graph_layout3.add_edge(i+1, j+1)
                    adjacent_matrix3[i][j] = 0
                    adjacent_matrix3[j][i] = 0

        fig, axes = plt.subplots(nrows=1, ncols=3, figsize=(8, 4))
        dictionary1 = nx.spring_layout(G)
        dictionary2 = nx.spring_layout(H)
        dictionary3 = nx.spring_layout(I)

        nx.draw_networkx_nodes(graph_layout1, dictionary1, ax=axes[0])
        nx.draw_networkx_labels(graph_layout1, dictionary1, ax=axes[0])
        nx.draw_networkx_edges(graph_layout1, dictionary1,
                               ax=axes[0], edge_color='r')
        axes[0].set_title(title1)

        nx.draw_networkx_nodes(graph_layout2, dictionary2, ax=axes[1])
        nx.draw_networkx_labels(graph_layout2, dictionary2, ax=axes[1])
        nx.draw_networkx_edges(graph_layout2, dictionary2,
                               ax=axes[1], edge_color='b')
        axes[1].set_title(title2)

        nx.draw_networkx_nodes(graph_layout3, dictionary3, ax=axes[2])
        nx.draw_networkx_labels(graph_layout3, dictionary3, ax=axes[2])
        nx.draw_networkx_edges(graph_layout3, dictionary3,
                               ax=axes[2], edge_color='g')
        axes[2].set_title(title3)
        plt.show()

    def plot_graph_4(self, graph1, graph2, graph3, graph4, title1='Plot 1', title2='Plot 2', title3='Plot 3', title4='Plot 4'):
        graph_layout1 = nx.Graph()
        graph_layout2 = nx.Graph()
        graph_layout3 = nx.Graph()
        graph_layout4 = nx.Graph()

        adjacent_matrix1 = deepcopy(graph1)
        adjacent_matrix2 = deepcopy(graph2)
        adjacent_matrix3 = deepcopy(graph3)
        adjacent_matrix4 = deepcopy(graph4)

        for n in range(1, self.nodes+1):
            graph_layout1.add_node(n)
            graph_layout2.add_node(n)
            graph_layout3.add_node(n)
            graph_layout4.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(adjacent_matrix1[i][j] != 0):
                    graph_layout1.add_edge(i+1, j+1)
                    adjacent_matrix1[i][j] = 0
                    adjacent_matrix1[j][i] = 0

                if(adjacent_matrix2[i][j] != 0):
                    graph_layout2.add_edge(i+1, j+1)
                    adjacent_matrix2[i][j] = 0
                    adjacent_matrix2[j][i] = 0

                if(adjacent_matrix3[i][j] != 0):
                    graph_layout3.add_edge(i+1, j+1)
                    adjacent_matrix3[i][j] = 0
                    adjacent_matrix3[j][i] = 0

                if(adjacent_matrix4[i][j] != 0):
                    graph_layout4.add_edge(i+1, j+1)
                    adjacent_matrix4[i][j] = 0
                    adjacent_matrix4[j][i] = 0

        fig, axes = plt.subplots(nrows=2, ncols=2, figsize=(4, 2))
        dictionary1 = nx.spring_layout(G)
        dictionary2 = nx.spring_layout(H)
        dictionary3 = nx.spring_layout(I)
        dictionary4 = nx.spring_layout(J)

        nx.draw_networkx_nodes(graph_layout1, dictionary1, ax=axes[0, 0])
        nx.draw_networkx_labels(graph_layout1, dictionary1, ax=axes[0, 0])
        nx.draw_networkx_edges(graph_layout1, dictionary1,
                               ax=axes[0, 0], edge_color='r')
        axes[0, 0].set_title(title1)

        nx.draw_networkx_nodes(graph_layout2, dictionary2, ax=axes[0, 1])
        nx.draw_networkx_labels(graph_layout2, dictionary2, ax=axes[0, 1])
        nx.draw_networkx_edges(graph_layout2, dictionary2,
                               ax=axes[0, 1], edge_color='b')
        axes[0, 1].set_title(title2)

        plt.subplots_adjust(hspace=0.236, wspace=0.101)

        nx.draw_networkx_nodes(graph_layout3, dictionary3, ax=axes[1, 0])
        nx.draw_networkx_labels(graph_layout3, dictionary3, ax=axes[1, 0])
        nx.draw_networkx_edges(graph_layout3, dictionary3,
                               ax=axes[1, 0], edge_color='g')
        axes[1, 0].set_title(title3)

        nx.draw_networkx_nodes(graph_layout4, dictionary4, ax=axes[1, 1])
        nx.draw_networkx_labels(graph_layout4, dictionary4, ax=axes[1, 1])
        nx.draw_networkx_edges(graph_layout4, dictionary4,
                               ax=axes[1, 1], edge_color='m')
        axes[1, 1].set_title(title4)
        plt.show()

    def plot_graph_6(self, graph1, graph2, graph3, graph4, graph5, graph6, title1='Plot 1', title2='Plot 2', title3='Plot 3', title4='Plot 4', title5='Plot 5', title6='Plot 6'):
        graph_layout1 = nx.Graph()
        graph_layout2 = nx.Graph()
        graph_layout3 = nx.Graph()
        graph_layout4 = nx.Graph()
        graph_layout5 = nx.Graph()
        graph_layout6 = nx.Graph()

        adjacent_matrix1 = deepcopy(graph1)
        adjacent_matrix2 = deepcopy(graph2)
        adjacent_matrix3 = deepcopy(graph3)
        adjacent_matrix4 = deepcopy(graph4)
        adjacent_matrix5 = deepcopy(graph5)
        adjacent_matrix6 = deepcopy(graph6)

        for n in range(1, self.nodes+1):
            graph_layout1.add_node(n)
            graph_layout2.add_node(n)
            graph_layout3.add_node(n)
            graph_layout4.add_node(n)
            graph_layout5.add_node(n)
            graph_layout6.add_node(n)

        for i in range(self.nodes):
            for j in range(self.nodes):

                if(adjacent_matrix1[i][j] != 0):
                    graph_layout1.add_edge(i+1, j+1)
                    adjacent_matrix1[i][j] = 0
                    adjacent_matrix1[j][i] = 0

                if(adjacent_matrix2[i][j] != 0):
                    graph_layout2.add_edge(i+1, j+1)
                    adjacent_matrix2[i][j] = 0
                    adjacent_matrix2[j][i] = 0

                if(adjacent_matrix3[i][j] != 0):
                    graph_layout3.add_edge(i+1, j+1)
                    adjacent_matrix3[i][j] = 0
                    adjacent_matrix3[j][i] = 0

                if(adjacent_matrix4[i][j] != 0):
                    graph_layout4.add_edge(i+1, j+1)
                    adjacent_matrix4[i][j] = 0
                    adjacent_matrix4[j][i] = 0

                if(adjacent_matrix5[i][j] != 0):
                    graph_layout5.add_edge(i+1, j+1)
                    adjacent_matrix5[i][j] = 0
                    adjacent_matrix5[j][i] = 0

                if(adjacent_matrix6[i][j] != 0):
                    graph_layout6.add_edge(i+1, j+1)
                    adjacent_matrix6[i][j] = 0
                    adjacent_matrix6[j][i] = 0

        fig, axes = plt.subplots(nrows=2, ncols=3, figsize=(24, 24))
        dictionary1 = nx.spring_layout(G)
        dictionary2 = nx.spring_layout(H)
        dictionary3 = nx.spring_layout(I)
        dictionary4 = nx.spring_layout(J)
        dictionary5 = nx.spring_layout(K)
        dictionary6 = nx.spring_layout(L)

        nx.draw_networkx_nodes(graph_layout1, dictionary1, ax=axes[0, 0])
        nx.draw_networkx_labels(graph_layout1, dictionary1, ax=axes[0, 0])
        nx.draw_networkx_edges(graph_layout1, dictionary1,
                               ax=axes[0, 0], edge_color='r')
        axes[0, 0].set_title(title1)

        nx.draw_networkx_nodes(graph_layout2, dictionary2, ax=axes[0, 1])
        nx.draw_networkx_labels(graph_layout2, dictionary2, ax=axes[0, 1])
        nx.draw_networkx_edges(graph_layout2, dictionary2,
                               ax=axes[0, 1], edge_color='b')
        axes[0, 1].set_title(title2)

        plt.subplots_adjust(hspace=0.236, wspace=0.176)

        nx.draw_networkx_nodes(graph_layout3, dictionary3, ax=axes[0, 2])
        nx.draw_networkx_labels(graph_layout3, dictionary3, ax=axes[0, 2])
        nx.draw_networkx_edges(graph_layout3, dictionary3,
                               ax=axes[0, 2], edge_color='g')
        axes[0, 2].set_title(title3)

        nx.draw_networkx_nodes(graph_layout4, dictionary4, ax=axes[1, 0])
        nx.draw_networkx_labels(graph_layout4, dictionary4, ax=axes[1, 0])
        nx.draw_networkx_edges(graph_layout4, dictionary4,
                               ax=axes[1, 0], edge_color='m')
        axes[1, 0].set_title(title4)

        nx.draw_networkx_nodes(graph_layout5, dictionary5, ax=axes[1, 1])
        nx.draw_networkx_labels(graph_layout5, dictionary5, ax=axes[1, 1])
        nx.draw_networkx_edges(graph_layout5, dictionary5,
                               ax=axes[1, 1], edge_color='y')
        axes[1, 1].set_title(title5)

        nx.draw_networkx_nodes(graph_layout6, dictionary6, ax=axes[1, 2])
        nx.draw_networkx_labels(graph_layout6, dictionary6, ax=axes[1, 2])
        nx.draw_networkx_edges(graph_layout6, dictionary6,
                               ax=axes[1, 2], edge_color='c')
        axes[1, 2].set_title(title6)

        plt.show()

        
