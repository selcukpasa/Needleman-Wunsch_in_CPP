#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Needleman.h"

using namespace std;
//Die Member-Variablen werden mit den uebergebenen Parameterwerten initialisiert.
//Member-Variablen sind Teil der Klasse und k�nnen von allen Methoden und Funktionen innerhalb dieser Klasse verwendet werden.
//Hier sind die Membervariablen dist, match und mis
NeedlemanImpl::NeedlemanImpl(int dis, int match, int mis) : dist(dis), match(match), mis(mis) {}

int NeedlemanImpl::calc_score(const string& a, const string& b, int i, int j) {
    //ueberprueft ob Char aus a mit Char aus b uebereinstimmt, wenn ja dann wird die Variable match ausgegeben, sonst mis.
    return (a[i] == b[j]) ? match : mis;
}
//Gibt das maximum der verschiedenen Faelle aus
int NeedlemanImpl::maximum(int a, int b, int c) {
    return max(max(a, b), c);
}

void NeedlemanImpl::needleman_calc(const string& seq1, const string& seq2) {
    int rows = seq1.length();
    int cols = seq2.length();

    vector<vector<int>> matrix(rows + 1, vector<int>(cols + 1, 0));

    for (int i = 0; i <= rows; ++i) {
        matrix[i][0] = dist * i;
    }
    for (int j = 0; j <= cols; ++j) {
        matrix[0][j] = dist * j;
    }
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            int c1 = matrix[i - 1][j - 1] + calc_score(seq1, seq2, i - 1, j - 1);
            int c2 = matrix[i - 1][j] + dist;
            int c3 = matrix[i][j - 1] + dist;
            int maxValue = maximum(c1, c2, c3);
            matrix[i][j] = maxValue;

            //std::cout << matrix[i][j] << "\t";
        }
        //std::cout << endl;
    }

    int i = rows, j = cols;
    string align1;
    string align2;
    string space;


    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && (matrix[i][j] == (matrix[i - 1][j - 1] + calc_score(seq1, seq2, i - 1, j - 1)))) {
            align1 = seq1[i - 1] + align1;
            align2 = seq2[j - 1] + align2;
            --i;
            --j;
        }
        else if (i > 0 && matrix[i][j] == matrix[i - 1][j] + dist) {
            align1 = seq1[i - 1] + align1;
            align2 = "-" + align2;
            --i;
        }
        else {
            align1 = "-" + align1;
            align2 = seq2[j - 1] + align2;
            --j;
        }
    }
    /*
    while (i > 0) {
        align1 = seq1[i - 1] + align1;
        align2 = '-' + align2;
        --i;
    }

    while (j > 0) {
        align1 = '-' + align1;
        align2 = seq2[j - 1] + align2;
        --j;
    }
    */
    print_alignment(align1, align2);
}

void NeedlemanImpl::print_alignment(const string& alignedSeq1, const string& alignedSeq2) {
    cout << alignedSeq1 << "\n";
    cout << string(alignedSeq1.length(), ' ') << "\n";
    cout << alignedSeq2 << endl;
}