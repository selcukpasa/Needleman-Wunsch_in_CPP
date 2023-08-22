#pragma once

#include <iostream>
#include <string>
#include <vector>

class NeedlemanImpl{
private:
    int dist;
    int match;
    int mis;

    int calc_score(const std::string& a, const std::string& b, int i, int j);
    int maximum(int a, int b, int c);

public:
    NeedlemanImpl(int dis, int match, int mis);

    void needleman_calc(const std::string& seq1, const std::string& seq2);

    void print_alignment(const std::string& alignedSeq1, const std::string& alignedSeq2);
};
