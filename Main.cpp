#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Needleman.h"
#include <cstdint>


using namespace std;


int main(int argc, const char* argv[])
{


    if (argc != 6)
    {
        std::cout << argv[0] << " <SEQUENZ1> <SEQUENZ2> <DISTANCE> <MATCH> <MISMATCH>" << std::endl;
        return 1;
    }

    std::string seq1 = argv[1];
    std::string seq2 = argv[2];
    int dist = std::stoi(argv[3]);
    int match = std::stoi(argv[4]);
    int mis = std::stoi(argv[5]);

    NeedlemanImpl needleman(dist, match, mis);

    needleman.needleman_calc(seq1, seq2);



    return 0;
}