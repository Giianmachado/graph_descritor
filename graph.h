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
        void build_graph(Mat img);
    private:
        void edges_init(igraph_vector_t v, Mat img);
        void weights_init(igraph_real_t *weights_data, Mat img);
};

#endif // GRAPH_H
