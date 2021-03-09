// Tic Tac Toe Project

#include <iostream>
using namespace std;

string box[9] = {" ", " ", " ",
                 " ", " ", " ",
                 " ", " ", " "};
bool play_game = true;
string player1 = "X";
string player2 = "O";

void show_board() {
    string row1 = box[0] + "|" + box[1] + "|" + box[2];
    string row2 = box[3] + "|" + box[4] + "|" + box[5];
    string row3 = box[6] + "|" + box[7] + "|" + box[8];

    cout << row1 << endl;
    cout << row2 << endl;
    cout << row3 << endl;
}

int player_enter_move() {
    string str_move;
    int int_move;
    while (true) {
        cout << "Player 's turn. Pick a spot from 1-9: ";
        cin >> str_move;
        int_move = stoi(str_move);
        if (box[int_move-1] == " ") {
            break;
        }
    }
    return int_move-1;
}

bool check_game_still_going(){
    bool state = true;
    if (box[0] == box[1] && box[0] == box[2] && box[0] != " "){
        state = false;
    } else if (box[3] == box[4] && box[3] == box[5] && box[3] != " "){
        state = false;
    } else if (box[6] == box[7] && box[6] == box[8] && box[6] != " "){
        state = false;
    } else if (box[0] == box[3] && box[0] == box[6] && box[0] != " "){
        state = false;
    } else if (box[1] == box[4] && box[1] == box[7] && box[1] != " "){
        state = false;
    } else if (box[2] == box[5] && box[2] == box[8] && box[2] != " "){
        state = false;
    } else if (box[0] == box[4] && box[0] == box[8] && box[0] != " "){
        state = false;
    } else if (box[2] == box[4] && box[2] == box[6] && box[2] != " "){
        state = false;
    } else {
        state = true;
    }
    return state;
}

int main() {

    show_board();
    string player_turn = player1;
    bool game_still_going = true;

    while (game_still_going == true) {
        int move = player_enter_move();
        box[move] = player_turn;
        show_board();
        if (check_game_still_going() == false) {
            break;
        }
        if (player_turn == player1) {
            player_turn = player2;
        } else {
            player_turn = player1;
        }
    }

    string winner = player_turn;
    cout << "Congrats " + player_turn;

    return 0;
}

