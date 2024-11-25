class Solution {
public:
    struct BoardState {
        std::vector<std::vector<int>> board; // Current board configuration
        int x; // X position of the empty square (0)
        int y; // Y position of the empty square (0)
        int level; // Number of moves taken to reach this state

        // Constructor to initialize BoardState object
        BoardState(const std::vector<std::vector<int>>& initBoard, int zeroX, int zeroY, int bfsLevel)
            : board(initBoard), x(zeroX), y(zeroY), level(bfsLevel) {}
    };

    int slidingPuzzle(vector<vector<int>>& board) {
        int x=0, y=0; // Initialize the positions of the empty square

        // Find the position of the empty square (0) in the board
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                if(!board[i][j]){
                    x=i;
                    y=j;
                    break;
                }
            }
        }

        BoardState state(board, x, y, 0); // Create the initial board state
        string end = "123450"; // Target configuration
        queue<BoardState> bfs; // BFS queue
        bfs.push(state); // Push the initial state into the queue
        set<string> v; // Set to track visited states
        v.insert(boardToString(board)); // Insert the initial state into visited set

        while(bfs.size()) {
            BoardState curr = bfs.front(); // Get the current state from the queue
            bfs.pop();

            // Check if we have reached the target configuration
            if(boardToString(curr.board) == end){
                return curr.level; // Return the number of moves taken
            }

            // You can use loop to make the code shorter, but I use if to each case to make it easy to understand

            // Go up
            if(curr.x != 0){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y], arr[curr.x-1][curr.y]); // Swap with the tile above
                if(!(v.count(boardToString(arr)))){ // Check if this state has been visited
                    BoardState next(arr, curr.x-1, curr.y, curr.level+1); // Create the next state
                    bfs.push(next); // Push the next state into the queue
                    v.insert(boardToString(arr)); // Mark this state as visited
                }
            }

            // Go left
            if(curr.y != 0){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y], arr[curr.x][curr.y-1]); // Swap with the tile to the left
                if(!(v.count(boardToString(arr)))){ // Check if this state has been visited
                    BoardState next(arr, curr.x, curr.y-1, curr.level+1); // Create the next state
                    bfs.push(next); // Push the next state into the queue
                    v.insert(boardToString(arr)); // Mark this state as visited
                }
            }

            // Go down
            if(curr.x != 1){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y], arr[curr.x+1][curr.y]); // Swap with the tile below
                if(!(v.count(boardToString(arr)))){ // Check if this state has been visited
                    BoardState next(arr, curr.x+1, curr.y, curr.level+1); // Create the next state
                    bfs.push(next); // Push the next state into the queue
                    v.insert(boardToString(arr)); // Mark this state as visited
                }
            }

            // Go right
            if(curr.y != 2){
                vector<vector<int>> arr = curr.board;
                swap(arr[curr.x][curr.y], arr[curr.x][curr.y+1]); // Swap with the tile to the right
                if(!(v.count(boardToString(arr)))){ // Check if this state has been visited
                    BoardState next(arr, curr.x, curr.y+1, curr.level+1); // Create the next state
                    bfs.push(next); // Push the next state into the queue
                    v.insert(boardToString(arr)); // Mark this state as visited
                }
            }
        }

        return -1; // Return -1 if the puzzle is unsolvable
    }

private:
    string boardToString(const vector<vector<int>>& board) {
        string res;
        // Convert the board to a string representation for easy comparison
        for (const auto& row : board) {
            for (int num : row) {
                res += to_string(num);
            }
        }
        return res;
    }
};