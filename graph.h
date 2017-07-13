#ifndef GRAPH_H
#define GRAPH_H
#include <opencv2/opencv.hpp>
#include <igraph/igraph.h>

using namespace std;
using namespace cv;

class graph
{
    public:
        graph();
        void build_graph(Mat img, int choice, string filename);
    private:
        void edges_init(igraph_vector_t v, Mat img);
        void weights_init(igraph_real_t *weights_data, Mat img);
        void average(igraph_t *g, igraph_vector_t *weights, igraph_real_t *weights_data, string filename, Mat img);
        void calcSumAndAverage(igraph_vector_t edge, igraph_real_t *weights_data, string filename);
        void standard_deviation(igraph_t *g, igraph_vector_t *weights, igraph_real_t *weights_data, string filename, Mat img);
        void calcSumAndStandardDeviation(igraph_vector_t edge, igraph_real_t *weights_data, string filename);
        void average_spanning_tree(igraph_t *g, igraph_vector_t *weights, igraph_real_t *weights_data, string filename, Mat img);
        void standard_deviation_spanning_tree(igraph_t *g, igraph_vector_t *weights, igraph_real_t *weights_data, string filename, Mat img);
};

#endif // GRAPH_H
