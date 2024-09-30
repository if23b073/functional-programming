#include <iostream>
#include <functional>
#include <numeric>
#include <vector>
#include <algorithm>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;
using namespace std::placeholders;

using Line = vector<char>;
using Board = vector<Line>;
using Lines = vector<Line>;


// Überprüft, ob die Anzahl der Tokens zwischen den Spielern um nicht mehr als 1 abweicht
auto checkTokenNumber = [](const Board& board) {
    return [=](char token1) {
        return [=](char token2) {
            int count1 = accumulate(board.begin(), board.end(), 0, [token1](int acc, const Line& line) {
                return acc + count(line.begin(), line.end(), token1);
            });
            int count2 = accumulate(board.begin(), board.end(), 0, [token2](int acc, const Line& line) {
                return acc + count(line.begin(), line.end(), token2);
            });
            return abs(count1 - count2) <= 1;
        };
    };
};

// Überprüft, ob nur gültige Tokens auf dem Spielfeld vorhanden sind
//von innen nach außen --> innerste Funktion find() überprüft die einzelnen Token auf Gültigkeit. Mittlere Funktion geht durch alle Tokens in einer Zeile, diese ruft finf auf. Die äußerste geht durch alle Zeilen und ruft die mittlere auf
auto checkValidTokens = [](const vector<char>& validTokens) {
    return [=](const Board& board) {
        return all_of(board.begin(), board.end(), [&validTokens](const Line& line) { 
            return all_of(line.begin(), line.end(), [&validTokens](char token) {
                return find(validTokens.begin(), validTokens.end(), token) != validTokens.end();
            });
        });
    };
};

// Überprüft, ob das Spielfeld die erwartete Größe hat
//Board.size() gibt Anzahl der Zeilen zurück, line.size() gibt die Anzahl der Spalten zurück
auto checkBoardDimension = [](size_t expectedRows) {
    return [=](size_t expectedCols) {
        return [=](const Board& board) {
            return board.size() == expectedRows && all_of(board.begin(), board.end(), [expectedCols](const Line& line) {
                return line.size() == expectedCols;
            });
        };
    };
};

// Test 1
TEST_CASE("Difference number of tokens >1") {
    Board board = {
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'}
    };
    CHECK(checkTokenNumber(board)('X')('O'));
}

// Test 2
TEST_CASE("Only correct tokens are present") {
    Board board = {
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'}
    };
    vector<char> validTokens = {'X', 'O', ' '};
    CHECK(checkValidTokens(validTokens)(board));
}

// Test 3
TEST_CASE("One wrong token is present") {
    Board board = {
        {'X', 'O', 'X', 'X', 'O', 'A', 'O'},  
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'}
    };
    vector<char> validTokens = {'X', 'O', ' '};
    CHECK_FALSE(checkValidTokens(validTokens)(board));
}

// Test 4
TEST_CASE("Board dimension is correct") {
    Board board = {
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'}
    };
    CHECK(checkBoardDimension(6)(7)(board));
}

// Test 5
TEST_CASE("Board dimension is incorrect") {
    Board board = {
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X', 'O'}
    };
    CHECK_FALSE(checkBoardDimension(6)(7)(board));
}
