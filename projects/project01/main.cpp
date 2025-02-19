#include <iostream>
#include <vector>

enum class gameState {onGoing, player1Wins, player2Wins, draw};

void ignoreLine();
int getInt();
std::vector<std::vector<int>> makeBoard();
int play();
enum gameState gameStatus(std::vector<std::vector<int>> nums);
int turnsLeft(int usedTurn);
void userMenu();
void gameBoard(const std::vector<std::vector<int>>& nums);
int columnAvailibility(std::vector<std::vector<int>>& nums, int columnNum);
bool checkColumns(const std::vector<std::vector<int>>& nums, int player);
bool checkRows(const std::vector<std::vector<int>>& nums, int player);
bool checkDiagnals(const std::vector<std::vector<int>>& nums, int player);
bool winCheck(const std::vector<std::vector<int>>& nums, int player);



int main(){
    while (true){
        userMenu();
        int userChoice = getInt();
        if (userChoice == 1){
            break;
        }
        else if (userChoice == 0){
            return 0;
        }
        else{
            std::cerr << "Error: You have entered a number that isn't 1 or 0, try again.\n\n";
        }
    }
    while (true) {
        std::vector<std::vector<int>> board = makeBoard();
        turnsLeft(turnsLeft(0));
        turnsLeft(-42);
        while (true){
            gameBoard(board);
            int turn = play();
            if (turn == 1){
                while (true){
                    std::cout << "Player 1 enter the number of the column you would like to send your piece down into: ";
                    int player1Choice = getInt();
                    if (player1Choice > 7 || player1Choice < 1){
                        std::cerr << "Error: You have entered a number this isn't between 1 and 7, try again.\n\n";
                    }
                    else if (columnAvailibility(board, (player1Choice-1)) > -1){
                        board[columnAvailibility(board, (player1Choice-1))][player1Choice-1] = 1;
                        if (gameStatus(board) == gameState::onGoing){
                            break;
                        }
                        else if (gameStatus(board) == gameState::draw){
                            while (true){
                                gameBoard(board);
                                std::cout << "The Game has ended in a Draw.\n Enter 1 to play again or 0 to exit the program: ";
                                int userOption = getInt();
                                if (userOption == 0){
                                    return 0;
                                }
                                else if (userOption == 1){
                                    break;
                                }
                                else{
                                    std::cerr << "Error: You have entered a number that isn't 1 or 0, try again.\n\n";
                                }
                            }
                        }
                        else if (gameStatus(board) == gameState::player1Wins){
                            while (true){
                                gameBoard(board);
                                std::cout << "The Game has ended, Player 1 wins.\n Enter 1 to play again or 0 to exit the program: ";
                                int userOption = getInt();
                                if (userOption == 0){
                                    return 0;
                                }
                                else if (userOption == 1){
                                    break;
                                }
                                else{
                                    std::cerr << "Error: You have entered a number that isn't 1 or 0, try again.\n\n";
                                }
                            }
                        }
                        break;
                    }
                    else{
                        std::cerr << "Error: The column you have entered is full, try again.\n\n";
                    }
                }
            }
            else if (turn == 0){
                while (true){
                    std::cout << "Player 2 enter the number of the column you would like to send your piece down into: ";
                    int player2Choice = getInt();
                    if (player2Choice > 7 || player2Choice < 1){
                        std::cerr << "Error: You have entered a number this isn't between 1 and 7, try again.\n\n";
                    }
                    else if (columnAvailibility(board, (player2Choice-1)) > -1){
                        board[columnAvailibility(board, (player2Choice-1))][player2Choice-1] = 2;
                        if (gameStatus(board) == gameState::onGoing){
                            break;
                        }
                        else if (gameStatus(board) == gameState::draw){
                            while (true){
                                gameBoard(board);
                                std::cout << "The Game has ended in a Draw.\n Enter 1 to play again or 0 to exit the program: ";
                                int userOption = getInt();
                                if (userOption == 0){
                                    return 0;
                                }
                                else if (userOption == 1){
                                    break;
                                }
                                else{
                                    std::cerr << "Error: You have entered a number that isn't 1 or 0, try again.\n\n";
                                }
                            }
                        }
                        else if (gameStatus(board) == gameState::player2Wins){
                            while (true){
                                gameBoard(board);
                                std::cout << "The Game has ended, Player 2 wins.\n Enter 1 to play again or 0 to exit the program: ";
                                int userOption = getInt();
                                if (userOption == 0){
                                    return 0;
                                }
                                else if (userOption == 1){
                                    break;
                                }
                                else{
                                    std::cerr << "Error: You have entered a number that isn't 1 or 0, try again.\n\n";
                                }
                            }
                        }
                        break;
                    }
                    else{
                        std::cerr << "Error: The column you have entered is full, try again.\n\n";
                    }

                }
            }
            if (gameStatus(board) == gameState::draw || gameStatus(board) == gameState::player1Wins || gameStatus(board) == gameState::player2Wins){
                break;
            }
        }
    }

	return 0;
}


void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInt()
{
    while (true)
    {
        int x{};
        std::cin >> x;
        bool success{ std::cin };
        std::cin.clear();
        ignoreLine();
        if (success)
            return x;
        else
            std::cerr << "*Error invalid input* \n Try again: ";
    }
}

std::vector<std::vector<int>> makeBoard()
{
    std::vector<std::vector<int>> nums = {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}};
    return nums;
}

int play()
{
    return turnsLeft(1) % 2;
}

enum gameState gameStatus(std::vector<std::vector<int>> nums)
{
    if (turnsLeft(0) == 0 && !winCheck(nums, 1) && !winCheck(nums, 2))
    {
        return gameState::draw;
    }
    else if (winCheck(nums, 1))
    {
        return gameState::player1Wins;
    }
    else if (winCheck(nums, 2))
    {
        return gameState::player2Wins;
    }
    else
    {
        return gameState::onGoing;
    }
}

int turnsLeft(int usedTurn)
{
    static int turns = 0;
    turns -= usedTurn;
    return turns;
}

void userMenu()
{
    std::cout << "*Rules*\nSetup: Player #1 gets an X board piece and player #2 gets a O board piece. Take turns dropping one piece into a column.\n"
        << "Objective: Be the first to connect four of your pieces in a row, column, or diagonal.\n"
        << "Turns : Players take turns dropping one piece at a time.Pieces stack on top of each other.\n"
        << "Winning : If a player connects four in a row, they win!\n\n"
        << "Enter the number 1 to continue or 0 to exit the program: ";
}

void gameBoard(const std::vector<std::vector<int>>& nums)
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for (int i = 0; i < nums.size(); i++) 
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            if (nums[i][j] == 0) std::cout << ". ";
            else if (nums[i][j] == 1) std::cout << "X ";
            else if (nums[i][j] == 2) std::cout << "O ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------\n";
    std::cout << "1 2 3 4 5 6 7\n";
    std::cout << "Turns left: " << turnsLeft(0) << std::endl;

}

int columnAvailibility(std::vector<std::vector<int>>& nums, int columnNum)
{
    for (int i = 5; i >= 0; i--)
    {
        if (nums[i][columnNum] == 0) 
        {
            return i; 
        }
    }
    return -1; 
}

bool checkColumns(const std::vector<std::vector<int>>& nums, int player)
{
    for (int i = 0; i < nums[0].size(); i++)
    {
        for (int j = 0; j <= (nums.size() - 4); j++)
        {
            if (player == nums[j][i] && nums[j][i] == nums[j+1][i] && nums[j+1][i] == nums[j+2][i] && nums[j+2][i] == nums[j+3][i])
            {
                return true;
            }
        }
    }
    return false;
}

bool checkRows(const std::vector<std::vector<int>>& nums, int player)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j <= (nums[0].size() - 4); j++)
        {
            if (player == nums[i][j] && nums[i][j] == nums[i][j+1] && nums[i][j+1] == nums[i][j+2] && nums[i][j+2] == nums[i][j+3])
            {
                return true;
            }
        }
    }
    return false;
}

bool checkDiagnals(const std::vector<std::vector<int>>& nums, int player)
{
    if (player == nums[0][0] && nums[0][0] == nums[1][1] && nums[1][1] == nums[2][2] && nums[2][2] == nums[3][3])
    {
        return true;
    }
    else if (player == nums[1][1] && nums[1][1] == nums[2][2] && nums[2][2] == nums[3][3] && nums[3][3] == nums[4][4])
    {
        return true;
    }
    else if (player == nums[2][2] && nums[2][2] == nums[3][3] && nums[3][3] == nums[4][4] && nums[4][4] == nums[5][5])
    {
        return true;
    }
    else if (player == nums[0][1] && nums[0][1] == nums[1][2] && nums[1][2] == nums[2][3] && nums[2][3] == nums[3][4])
    {
        return true;
    }
    else if (player == nums[1][2] && nums[1][2] == nums[2][3] && nums[2][3] == nums[3][4] && nums[3][4] == nums[4][5])
    {
        return true;
    }
    else if (player == nums[2][3] && nums[2][3] == nums[3][4] && nums[3][4] == nums[4][5] && nums[4][5] == nums[5][6])
    {
        return true;
    }
    else if (player == nums[0][6] && nums[0][6] == nums[1][5] && nums[1][5] == nums[2][4] && nums[2][4] == nums[3][3])
    {
        return true;
    }
    else if (player == nums[1][5] && nums[1][5] == nums[2][4] && nums[2][4] == nums[3][3] && nums[3][3] == nums[4][2])
    {
        return true;
    }
    else if (player == nums[2][4] && nums[2][4] == nums[3][3] && nums[3][3] == nums[4][2] && nums[4][2] == nums[5][1])
    {
        return true;
    }
    else if (player == nums[0][5] && nums[0][5] == nums[1][4] && nums[1][4] == nums[2][3] && nums[2][3] == nums[3][2])
    {
        return true;
    }
    else if (player == nums[1][4] && nums[1][4] == nums[2][3] && nums[2][3] == nums[3][2] && nums[3][2] == nums[4][1])
    {
        return true;
    }
    else if (player == nums[2][3] && nums[2][3] == nums[3][2] && nums[3][2] == nums[4][1] && nums[4][1] == nums[5][0])
    {
        return true;
    }
    else if (player == nums[0][2] && nums[0][2] == nums[1][3] && nums[1][3] == nums[2][4] && nums[2][4] == nums[3][5])
    {
        return true;
    }
    else if (player == nums[1][3] && nums[1][3] == nums[2][4] && nums[2][4] == nums[3][5] && nums[3][5] == nums[4][6])
    {
        return true;
    }
    else if (player == nums[0][4] && nums[0][4] == nums[1][3] && nums[1][3] == nums[2][2] && nums[2][2] == nums[3][1])
    {
        return true;
    }
    else if (player == nums[1][3] && nums[1][3] == nums[2][2] && nums[2][2] == nums[3][1] && nums[3][1] == nums[4][0])
    {
        return true;
    }
    else if (player == nums[0][3] && nums[0][3] == nums[1][2] && nums[1][2] == nums[2][1] && nums[2][1] == nums[3][0])
    {
        return true;
    }
    else if (player == nums[0][3] && nums[0][3] == nums[1][4] && nums[1][4] == nums[2][5] && nums[2][5] == nums[3][6])
    {
        return true;
    }
    else if (player == nums[1][6] && nums[1][6] == nums[2][5] && nums[2][5] == nums[3][4] && nums[3][4] == nums[4][3])
    {
        return true;
    }
    else if (player == nums[2][5] && nums[2][5] == nums[3][4] && nums[3][4] == nums[4][3] && nums[4][3] == nums[5][2])
    {
        return true;
    }
    else if (player == nums[1][0] && nums[1][0] == nums[2][1] && nums[2][1] == nums[3][2] && nums[3][2] == nums[4][3])
    {
        return true;
    }
    else if (player == nums[2][1] && nums[2][1] == nums[3][2] && nums[3][2] == nums[4][3] && nums[4][3] == nums[5][4])
    {
        return true;
    }
    else if (player == nums[2][0] && nums[2][0] == nums[3][1] && nums[3][1] == nums[4][2] && nums[4][2] == nums[5][3])
    {
        return true;
    }
    else if (player == nums[2][6] && nums[2][6] == nums[3][5] && nums[3][5] == nums[4][4] && nums[4][4] == nums[5][3])
    {
        return true;
    }
    return false;
}

bool winCheck(const std::vector<std::vector<int>>& nums, int player)
{
    if (checkColumns(nums, player) || checkDiagnals(nums, player) || checkRows(nums, player))
    {
        return true;
    }
    return false;
}