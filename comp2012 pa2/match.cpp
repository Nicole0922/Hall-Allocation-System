#include "match.h"

bool Match::outOfBound(int row, int col) const {
    // Task 4.1: Check whether a given position is out of bound.
    if (row >= BOARD_SIZE || col >= BOARD_SIZE) return true;
    return false;
}

bool Match::setPlayer(Player* p, int index){
    // Task 4.2: Set the player with the given index.
    // Case 1: Wrong index.
    if (index != 0 && index != 1) return false;

    // Case 2: Player already exists.
    if (players[index] != nullptr) return false;

    // Case 3: Out of bound or the position is already occupied.
    if (outOfBound(p->row, p->col) == true) return false;
    for (int i=0; i<2; i++){
        if (players[i] != nullptr){
            if (p->row == players[i]->row && p->col == players[i]->col){
                return false;
            }
        }
    }

    // Case 4: Otherwise, the player can be set.
    players[index] = p;
    board[p->row][p->col] = p;
    return true;
}

bool Match::addItem(Item* item, int row, int col){
    // Task 4.3: Add the item to the board.
    // Case 1: Out of bound or the position is already occupied.
    if (outOfBound(row, col) == true) return false;
    if (board[row][col] != nullptr) return false;
    
    // Case 2: Scan the whole board to check whether there exists any item with the same name.
    for (int i=0; i<BOARD_SIZE; i++){
        for (int j=0; j<BOARD_SIZE; j++){
            if (board[i][j] != nullptr){
                if (board[i][j]->getName() == item->getName()) return false;
            }
        }
    }

    // Case 3: Otherwise, the item can be added.
    board[row][col] = item;
    return true;
}

bool Match::move(char c){
    // Task 4.4: Move the player.
    if (c != 'w' && c != 'a' && c != 's' && c != 'd') return false;

    int roww = players[curRound]->row;
    int coll = players[curRound]->col;
    int fu_row = roww;
    int fu_col = coll;

    // check up, down, left, right direction
    if (c == 'w'){
        if (roww > 0) fu_row--;
        else return false;
    }
    else if (c == 's'){
        if (roww < BOARD_SIZE-1) fu_row++;
        else return false;
    }
    else if (c == 'a'){
        if (coll > 0) fu_col--;
        else return false;
    }
    else if (c == 'd'){
        if (coll < BOARD_SIZE-1) fu_col++;
        else return false;
    }

    // check if the target position contains items
    // have nth
    if (board[fu_row][fu_col] == nullptr){
        board[fu_row][fu_col] = players[curRound];
        board[roww][coll] = nullptr;
    }
    // have a bomb
    else if (board[fu_row][fu_col]->getPieceType() == BOMB){
        // addtional updates
        players[curRound]->hp -= dynamic_cast <Item*>(board[fu_row][fu_col])->getDefaultPower();
        if (players[curRound]->hp <= 0){
            curRound = -1;
            return true;
        }

        // normal updates
        delete board[fu_row][fu_col];
        board[fu_row][fu_col] = players[curRound];
        board[roww][coll] = nullptr;
    }
    // get AttackItem
    else if (board[fu_row][fu_col]->getPieceType() == ATTACK_ITEM){
        // addtional updates
        players[curRound]->insertAttackItem(dynamic_cast <AttackItem*>(board[fu_row][fu_col]));

        // normal updates
        board[fu_row][fu_col] = players[curRound];
        board[roww][coll] = nullptr;
    }
    // get DefenseItem
    else if (board[fu_row][fu_col]->getPieceType() == DEFENSE_ITEM){
        // addtional updates
        players[curRound]->insertDefenseItem(dynamic_cast <DefenseItem*>(board[fu_row][fu_col]));

        // normal updates
        board[fu_row][fu_col] = players[curRound];
        board[roww][coll] = nullptr;
    }
    // 2 players meet!!!
    else if (board[fu_row][fu_col]->getPieceType() == PLAYER){
        battle();
        curRound = -1;
        return true;
    }
    players[curRound]->row = fu_row;
    players[curRound]->col = fu_col;

    curRound++;
    curRound %= 2;
    return true;
}

void Match::battle(){
    // Task 5.3: Battle when the two players meet.
    int defense_P = 0;

    while (players[0]->hp > 0 && players[1]->hp > 0){
        AttackItem* atk = players[curRound]->attackItems.attack();

        // if no attack items
        if (atk == nullptr){
            printBattle(nullptr, nullptr);
        }
        else{
            DefenseItem* def = players[(curRound+1)%2]->defenseItems.defense(atk, defense_P);

            // if have defense item
            if (def != nullptr){
                int damage = atk->getDefaultPower() - defense_P;
                if (damage < 0) damage = 0;
                players[(curRound+1)%2]->hp -= damage;

                // reduce remaining defensing power
                // check the atk is smaller than defense power
                if (defense_P > atk->getDefaultPower()){
                    // check if remaining power is enough
                    if (def->getRemainingDefensePower() > atk->getDefaultPower()){
                        def->reduceRemainingDefensePower(atk->getDefaultPower());
                    }
                    else{
                        def->reduceRemainingDefensePower(def->getRemainingDefensePower());
                    }
                }
                else{
                    // check if remaining power is enough
                    if (def->getRemainingDefensePower() > defense_P){
                        def->reduceRemainingDefensePower(defense_P);
                    }
                    else{
                        def->reduceRemainingDefensePower(def->getRemainingDefensePower());
                    }
                }
            }
            else{
                players[(curRound+1)%2]->hp -= atk->getDefaultPower();
            }
            atk->decrementUsageTimes();
            printBattle(atk, def);
        }
        curRound++;
        curRound %= 2;

        // check the itemarray of 2 players
        bool check[2] = {false, false};

        for (int i=0; i<2; i++){
            // attack items empty?
            AttackItem* checkAtkEmpty = players[i]->attackItems.attack();
            if (checkAtkEmpty == nullptr) check[i] = true;
            else check[i] = false;
        }
        if (check[0] == true && check[1] == true) break;
    }
}