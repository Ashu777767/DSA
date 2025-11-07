/**
 * @param {number[][]} moves
 * @return {string}
 */

var tictactoe = function(moves) {
    // create empty 3x3 board
    const grid = [
        ['','',''],
        ['','',''],
        ['','','']
    ];

    let player = 'X'; // A = X, B = O

    // helper function to check winner
    const checkWinner = (r, c, letter) => {

        // row
        if (grid[r][0] === letter && grid[r][1] === letter && grid[r][2] === letter)
            return true;

        // col
        if (grid[0][c] === letter && grid[1][c] === letter && grid[2][c] === letter)
            return true;

        // main diagonal
        if (r === c && 
            grid[0][0] === letter && grid[1][1] === letter && grid[2][2] === letter)
            return true;

        // anti diagonal
        if (r + c === 2 &&
            grid[0][2] === letter && grid[1][1] === letter && grid[2][0] === letter)
            return true;

        return false;
    };

    // simulate moves
    for (let i = 0; i < moves.length; i++) {
        let r = moves[i][0];
        let c = moves[i][1];

        grid[r][c] = player;

        // check winner
        if (checkWinner(r, c, player)) {
            return player === 'X' ? "A" : "B";
        }

        // switch player
        player = player === 'X' ? 'O' : 'X';
    }

    // all 9 moves played but no winner
    if (moves.length === 9) return "Draw";

    // game not finished
    return "Pending";
};
