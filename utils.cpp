#include "utils.h"
#include <opencv2/opencv.hpp>
#include <unistd.h>

using namespace std;
using namespace cv;

utils::utils(){}

/**
 * @brief utils::showImage
 * @param img
 * Show image
 */
void utils::showImage(Mat img){
    namedWindow("image", 2);
    imshow("image", img);
    waitKey(0);
}

/**
 * @brief utils::maxDivisor
 * @param r
 * return max divisor to the r boxes
 */
int utils::maxDivisor(Mat img, int r){
    return floor(img.cols/r);
}

/**
 * @brief utils::abort_programa
 */
void utils::abort_programa(){
    exit(0);
}

/**
 * @brief utils::verify_r
 * @param r
 * @return
 */
bool utils::verify_r(int r){
    if(r == 100)
        return true;
    else if(r == 50)
        return true;
    else if(r == 40)
        return true;
    else if(r == 25)
        return true;
    else if(r == 20)
        return true;
    else if(r == 10)
        return true;
    else if(r == 8)
        return true;
    else if(r == 5)
        return true;
    else if(r == 4)
        return true;
    else
        return false;
}

/**
 * @brief utils::print_divider
 */
void utils::print_divider(){
   cout << "*************************************************************************************************" << endl;
   cout << "*************************************************************************************************" << endl << endl;
}

/**
 * @brief utils::print_information_author
 */
void utils::print_information_author(){
    print_divider();
    cout << "Autor: Gianluca Maziero Machado" << endl;
    cout << "Curso: Engenharia de Computação" << endl;
    cout << "Universidade Tecnologica Federal do Parana - UTFPR" << endl;
    cout << "Campus Cornelio Procopio" << endl;
    cout << "Titulo: Tecnicas de Descriçao de Imagens Baseadas em Grafos" << endl;
    cout << "Vinculado ao Projeto Personalização de Consultas por Similaridade em Dados Complexos" << endl;
    cout << "Orientador: Prof. Dr. Pedro Henrique Bugatti" << endl << endl;
    print_divider();
    usleep(10000000);
}

/**
 * @brief utils::print_error_r
 */
void utils::print_error_r(){
    print_divider();
    cerr << "The argument r is invalid" << endl << endl;
    print_divider();
    abort_programa();
}

/**
 * @brief utils::print_error_choice
 */
void utils::print_error_choice(){
    print_divider();
    cout << "The choice value c is not valid. Choose the one of following options the next time." << endl;
    cout << "1 - average" << endl;
    cout << "2 - standard deviation" << endl;
    cout << "3 - 1 concat with 2" << endl;
    cout << "4 - Spanning tree average" << endl;
    cout << "5 - Spanning tree standard deviation" << endl;
    cout << "6 - 4 concat with 5" << endl;
    cout << "7 - 1 concat with 4" << endl;
    cout << "8 - 2 concat with 5" << endl;
    cout << "9 - 3 concat with 6" << endl << endl;
    print_divider();
    abort_programa();
}
