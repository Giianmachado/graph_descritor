#include "graph.h"
#include <opencv2/opencv.hpp>
#include <igraph/igraph.h>
#include <utils.h>

using namespace std;
using namespace cv;

graph::graph(){}

/**
 * @brief graph::build_graph
 * @param img
 * Build a graph and calc the djkistra path
 */
void graph::build_graph(Mat img){
    //Declarações
    //Utils methods
    utils u;
    //Graph
    igraph_t g;
    //Edges
    igraph_vector_t v;
    //Number of edges
    int num_of_edges = ((img.cols-1)*(img.rows))*2;
    //Vector of weigths
    igraph_real_t weights_data[num_of_edges];
    //Vector of weigths used by igraph
    igraph_vector_t weights;
    //Result matrix
    igraph_matrix_t res;

    //Initialize graph with the number of nodes
    igraph_empty(&g /*Graph*/, img.cols*img.rows /*Number of nodes*/, IGRAPH_UNDIRECTED /*Type pf graph = undirected*/);
    //Initialize the vector of the conexion between the rows and cols
    igraph_vector_init(&v /*Vector of edges*/, num_of_edges*2 /*Number of edges*/);
    //Initialize vector of the edges
    edges_init(v /*Vector of edges*/,img /*Image*/);
    //Add edges to graph
    igraph_add_edges(&g /*Graph*/,&v /*vector of edges*/,0);
    //Make the weights of according the structure of edges 0-1 1-2 2-1 ...
    weights_init(weights_data /*vector of weights*/, img /*image*/);
    //make a cast type on the vector of the weights to the type igraph_real_t
    igraph_vector_view(&weights /*weights result transformation*/, weights_data /*weights data with weights*/,sizeof(weights_data)/sizeof(igraph_real_t));
    //Initialize result matrix with 0's
    igraph_matrix_init(&res /*result matrix*/, 0, 0);
    //Build the matrix with the graph and all weights
    igraph_shortest_paths_dijkstra(&g, &res, igraph_vss_all(), igraph_vss_all(),&weights, IGRAPH_ALL);
    //u.showImage(img);
}

/**
 * @brief graph::weights_init
 * Make a vector with weights based on structure of the edge ids
 *
 * 0-1 = w_1
 * 1-2 = w_2
 *
 * In the same sequence
 *
 */
void graph::weights_init(igraph_real_t *weights_data, Mat img){
    // declarations
    int i, j, k, aux;

    //Get weights horizontal
    for(i = 0, k = 0, aux = 0;i < img.rows; i++, aux++)
        for(j = 0;j < img.cols-1;j++, k++, aux++)
            weights_data[k] =  (abs(img.at<uchar>(i,j) - img.at<uchar>(i,j+1))) + ((img.at<uchar>(i,j) + img.at<uchar>(i,j+1))/2);

    //Get weights vertical
    for(i = 0, aux = 0;i < img.cols;i++, aux = i)
        for(j = 0;j < img.rows-1;j++, k++, aux+=img.cols)
            weights_data[k] = (abs(img.at<uchar>(j,i) - img.at<uchar>(j+1,i))) + ((img.at<uchar>(j,i) + img.at<uchar>(j+1,i))/2);
}

/**
 * @brief graph::edges_init
 * @param v
 * @param img
 * This function makes a vector of the conexion between the edges. Ex image ids:
 *
 *  0  1  2  3  4
 *  5  6  7  8  9
 * 10 11 12 13 14
 * 15 16 17 18 19
 * 20 21 22 23 24
 *
 * In the horizontal
 * the result is: 0 1 1 2 2 3 3 4 5 6 6 7.... 23 24
 * Simulating the conexion between: 0-1 1-2 2-3 3-4 .... 23-24
 *
 *
 * In the vertical
 * the result is: 0 5 5 10 10 15 15 20 1 6 6 11 ... 19 24
 * Simulating the conexion between: 0-5 5-10 10-15 15-20 .... 19-24
 *
 */
void graph::edges_init(igraph_vector_t v, Mat img){

    //Declarations
    int i, j, k, aux;

    //Loop to make conexions between edges Ex: 0-1 1-2 3-4... horizontal
    for(i = 0, aux = 0, k = 0;i < img.rows; i++){
        for(j = 0; j < img.cols-1; j++){
            VECTOR(v)[k] = aux;
            VECTOR(v)[k+1] = aux+1;
            aux++;
            k+=2;
        }
        aux++;        
    }

    //Loop to make conexions between edges Ex: 0-5 5-10 10-15... vertical
    for(i = 0;i < img.cols;i++){
        aux = i;
        for(j = 0;j < (img.rows-1);j++){
            VECTOR(v)[k] = aux;
            VECTOR(v)[k+1] = aux+img.cols;
            aux+=img.cols;
            k+=2;
        }
    }
}
