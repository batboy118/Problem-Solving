function isValidSudoku(board: string[][]): boolean {
    let check = [0,0,0,0,0,0,0,0,0,0];
    for(let i = 0; i < board.length; i++){
        check = [0,0,0,0,0,0,0,0,0,0];
        for(let j = 0; j < board.length; j++) {
            if(board[i][j] == '.') continue;
            else if(check[Number(board[i][j])]++ != 0) return false;
        }
    }
    for(let i = 0; i < board.length; i++){
        check = [0,0,0,0,0,0,0,0,0,0];
        for(let j = 0; j < board.length; j++) {
            if(board[j][i] == '.') continue;
            else if(check[Number(board[j][i])]++ != 0) return false;
        }
    }
    for(let y = 0; y < 9; y += 3){
        for(let x = 0; x < 9; x += 3){
            check = [0,0,0,0,0,0,0,0,0,0];
            for(let i = y; i < y + 3; i++){
                for(let j = x; j < x + 3; j++) {
                    if(board[i][j] == '.') continue;
                    if(check[Number(board[i][j])]++ != 0) return false;
                }
            }
        }
    }
    return true;
};
